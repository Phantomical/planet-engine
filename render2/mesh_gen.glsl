#version 430

layout(local_size_x = 128) in;

// Vertex Information Layout:
//   vec3 vertex
//   vec3 normal
//   float displacement

layout(location = 0) uniform uint size;

layout(binding = 0, std140) uniform GeneratorInputs
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};

layout(binding = 0, std430) buffer OutputValues
{
	float values[];
};


//
// Description : Array and textureless GLSL 2D/3D/4D simplex 
//               noise functions.
//      Author : Ian McEwan, Ashima Arts.
//  Maintainer : stegu
//     Lastmod : 20110822 (ijm)
//     License : Copyright (C) 2011 Ashima Arts. All rights reserved.
//               Distributed under the MIT License. See LICENSE file.
//               https://github.com/ashima/webgl-noise
//               https://github.com/stegu/webgl-noise
// 

dvec3 simplex1_mod289(dvec3 x)
{
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
dvec4 simplex1_mod289(dvec4 x)
{
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
dvec4 simplex1_permute(dvec4 x)
{
     return simplex1_mod289(((x*34.0)+1.0)*x);
}
dvec4 simplex1_taylorInvSqrt(dvec4 r)
{
  return 1.79284291400159 - 0.85373472095314 * r;
}
double simplex1(dvec3 v)
{ 
  const dvec2  C = dvec2(1.0/6.0, 1.0/3.0) ;
  const dvec4  D = dvec4(0.0, 0.5, 1.0, 2.0);

// First corner
  dvec3 i  = floor(v + dot(v, C.yyy) );
  dvec3 x0 =   v - i + dot(i, C.xxx) ;

// Other corners
  dvec3 g = step(x0.yzx, x0.xyz);
  dvec3 l = 1.0 - g;
  dvec3 i1 = min( g.xyz, l.zxy );
  dvec3 i2 = max( g.xyz, l.zxy );

  //   x0 = x0 - 0.0 + 0.0 * C.xxx;
  //   x1 = x0 - i1  + 1.0 * C.xxx;
  //   x2 = x0 - i2  + 2.0 * C.xxx;
  //   x3 = x0 - 1.0 + 3.0 * C.xxx;
  dvec3 x1 = x0 - i1 + C.xxx;
  dvec3 x2 = x0 - i2 + C.yyy; // 2.0*C.x = 1/3 = C.y
  dvec3 x3 = x0 - D.yyy;      // -1.0+3.0*C.x = -0.5 = -D.y

// Permutations
  i = simplex1_mod289(i); 
  dvec4 p = simplex1_permute( simplex1_permute( simplex1_permute( 
             i.z + dvec4(0.0, i1.z, i2.z, 1.0 ))
           + i.y + dvec4(0.0, i1.y, i2.y, 1.0 )) 
           + i.x + dvec4(0.0, i1.x, i2.x, 1.0 ));

// Gradients: 7x7 points over a square, mapped onto an octahedron.
// The ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)
  double n_ = 0.142857142857; // 1.0/7.0
  dvec3  ns = n_ * D.wyz - D.xzx;

  dvec4 j = p - 49.0 * floor(p * ns.z * ns.z);  //  mod(p,7*7)

  dvec4 x_ = floor(j * ns.z);
  dvec4 y_ = floor(j - 7.0 * x_ );    // mod(j,N)

  dvec4 x = x_ *ns.x + ns.yyyy;
  dvec4 y = y_ *ns.x + ns.yyyy;
  dvec4 h = 1.0 - abs(x) - abs(y);

  dvec4 b0 = dvec4( x.xy, y.xy );
  dvec4 b1 = dvec4( x.zw, y.zw );

  //dvec4 s0 = dvec4(lessThan(b0,0.0))*2.0 - 1.0;
  //dvec4 s1 = dvec4(lessThan(b1,0.0))*2.0 - 1.0;
  dvec4 s0 = floor(b0)*2.0 + 1.0;
  dvec4 s1 = floor(b1)*2.0 + 1.0;
  dvec4 sh = -step(h, dvec4(0.0));

  dvec4 a0 = b0.xzyw + s0.xzyw*sh.xxyy ;
  dvec4 a1 = b1.xzyw + s1.xzyw*sh.zzww ;

  dvec3 p0 = dvec3(a0.xy,h.x);
  dvec3 p1 = dvec3(a0.zw,h.y);
  dvec3 p2 = dvec3(a1.xy,h.z);
  dvec3 p3 = dvec3(a1.zw,h.w);

//Normalise gradients
  dvec4 norm = simplex1_taylorInvSqrt(dvec4(dot(p0,p0), dot(p1,p1), dot(p2, p2), dot(p3,p3)));
  p0 *= norm.x;
  p1 *= norm.y;
  p2 *= norm.z;
  p3 *= norm.w;

// Mix final noise value
  dvec4 m = max(0.6 - dvec4(dot(x0,x0), dot(x1,x1), dot(x2,x2), dot(x3,x3)), 0.0);
  m = m * m;
  return 42.0 * dot( m*m, dvec4( dot(p0,x0), dot(p1,x1), 
                                dot(p2,x2), dot(p3,x3) ) );
}

// Cellular noise ("Worley noise") in 3D in GLSL.
// Copyright (c) Stefan Gustavson 2011-04-19. All rights reserved.
// This code is released under the conditions of the MIT license.
// See LICENSE file for details.
// https://github.com/stegu/webgl-noise

// Modulo 289 without a division (only multiplications)
dvec3 voronoi1_mod289(dvec3 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}
// Modulo 7 without a division
dvec3 voronoi1_mod7(dvec3 x)
{
	return x - floor(x * (1.0 / 7.0)) * 7.0;
}
// Permutation polynomial: (34x^2 + x) mod 289
dvec3 voronoi1_permute(dvec3 x)
{
	return voronoi1_mod289((34.0 * x + 1.0) * x);
}

// Cellular noise, returning F1 and F2 in a dvec2.
// 3x3x3 search region for good F2 everywhere, but a lot
// slower than the 2x2x2 version.
// The code below is a bit scary even to its author,
// but it has at least half decent performance on a
// modern GPU. In any case, it beats any software
// implementation of Worley noise hands down.
dvec2 voronoi1_source(dvec3 P)
{
#define K 0.142857142857 // 1/7
#define Ko 0.428571428571 // 1/2-K/2
#define K2 0.020408163265306 // 1/(7*7)
#define Kz 0.166666666667 // 1/6
#define Kzo 0.416666666667 // 1/2-1/6*2
#define jitter 1.0 // smaller jitter gives more regular pattern

	dvec3 Pi = voronoi1_mod289(floor(P));
	dvec3 Pf = fract(P) - 0.5;
	
	dvec3 Pfx = Pf.x + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfy = Pf.y + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfz = Pf.z + dvec3(1.0, 0.0, -1.0);
	
	dvec3 p = voronoi1_permute(Pi.x + dvec3(-1.0, 0.0, 1.0));
	dvec3 p1 = voronoi1_permute(p + Pi.y - 1.0);
	dvec3 p2 = voronoi1_permute(p + Pi.y);
	dvec3 p3 = voronoi1_permute(p + Pi.y + 1.0);
	
	dvec3 p11 = voronoi1_permute(p1 + Pi.z - 1.0);
	dvec3 p12 = voronoi1_permute(p1 + Pi.z);
	dvec3 p13 = voronoi1_permute(p1 + Pi.z + 1.0);
	
	dvec3 p21 = voronoi1_permute(p2 + Pi.z - 1.0);
	dvec3 p22 = voronoi1_permute(p2 + Pi.z);
	dvec3 p23 = voronoi1_permute(p2 + Pi.z + 1.0);
	
	dvec3 p31 = voronoi1_permute(p3 + Pi.z - 1.0);
	dvec3 p32 = voronoi1_permute(p3 + Pi.z);
	dvec3 p33 = voronoi1_permute(p3 + Pi.z + 1.0);
	
	dvec3 ox11 = fract(p11 * K) - Ko;
	dvec3 oy11 = voronoi1_mod7(floor(p11 * K)) * K - Ko;
	dvec3 oz11 = floor(p11 * K2) * Kz - Kzo; // p11 < 289 guaranteed
	
	dvec3 ox12 = fract(p12 * K) - Ko;
	dvec3 oy12 = voronoi1_mod7(floor(p12 * K)) * K - Ko;
	dvec3 oz12 = floor(p12 * K2) * Kz - Kzo;
	
	dvec3 ox13 = fract(p13 * K) - Ko;
	dvec3 oy13 = voronoi1_mod7(floor(p13 * K)) * K - Ko;
	dvec3 oz13 = floor(p13 * K2) * Kz - Kzo;
	
	dvec3 ox21 = fract(p21 * K) - Ko;
	dvec3 oy21 = voronoi1_mod7(floor(p21 * K)) * K - Ko;
	dvec3 oz21 = floor(p21 * K2) * Kz - Kzo;
	
	dvec3 ox22 = fract(p22 * K) - Ko;
	dvec3 oy22 = voronoi1_mod7(floor(p22 * K)) * K - Ko;
	dvec3 oz22 = floor(p22 * K2) * Kz - Kzo;
	
	dvec3 ox23 = fract(p23 * K) - Ko;
	dvec3 oy23 = voronoi1_mod7(floor(p23 * K)) * K - Ko;
	dvec3 oz23 = floor(p23 * K2) * Kz - Kzo;
	
	dvec3 ox31 = fract(p31 * K) - Ko;
	dvec3 oy31 = voronoi1_mod7(floor(p31 * K)) * K - Ko;
	dvec3 oz31 = floor(p31 * K2) * Kz - Kzo;
	
	dvec3 ox32 = fract(p32 * K) - Ko;
	dvec3 oy32 = voronoi1_mod7(floor(p32 * K)) * K - Ko;
	dvec3 oz32 = floor(p32 * K2) * Kz - Kzo;
	
	dvec3 ox33 = fract(p33 * K) - Ko;
	dvec3 oy33 = voronoi1_mod7(floor(p33 * K)) * K - Ko;
	dvec3 oz33 = floor(p33 * K2) * Kz - Kzo;
	
	dvec3 dx11 = Pfx + jitter * ox11;
	dvec3 dy11 = Pfy.x + jitter * oy11;
	dvec3 dz11 = Pfz.x + jitter * oz11;
	
	dvec3 dx12 = Pfx + jitter * ox12;
	dvec3 dy12 = Pfy.x + jitter * oy12;
	dvec3 dz12 = Pfz.y + jitter * oz12;
	
	dvec3 dx13 = Pfx + jitter * ox13;
	dvec3 dy13 = Pfy.x + jitter * oy13;
	dvec3 dz13 = Pfz.z + jitter * oz13;
	
	dvec3 dx21 = Pfx + jitter * ox21;
	dvec3 dy21 = Pfy.y + jitter * oy21;
	dvec3 dz21 = Pfz.x + jitter * oz21;
	
	dvec3 dx22 = Pfx + jitter * ox22;
	dvec3 dy22 = Pfy.y + jitter * oy22;
	dvec3 dz22 = Pfz.y + jitter * oz22;
	
	dvec3 dx23 = Pfx + jitter * ox23;
	dvec3 dy23 = Pfy.y + jitter * oy23;
	dvec3 dz23 = Pfz.z + jitter * oz23;
	
	dvec3 dx31 = Pfx + jitter * ox31;
	dvec3 dy31 = Pfy.z + jitter * oy31;
	dvec3 dz31 = Pfz.x + jitter * oz31;
	
	dvec3 dx32 = Pfx + jitter * ox32;
	dvec3 dy32 = Pfy.z + jitter * oy32;
	dvec3 dz32 = Pfz.y + jitter * oz32;
	
	dvec3 dx33 = Pfx + jitter * ox33;
	dvec3 dy33 = Pfy.z + jitter * oy33;
	dvec3 dz33 = Pfz.z + jitter * oz33;
	
	dvec3 d11 = dx11 * dx11 + dy11 * dy11 + dz11 * dz11;
	dvec3 d12 = dx12 * dx12 + dy12 * dy12 + dz12 * dz12;
	dvec3 d13 = dx13 * dx13 + dy13 * dy13 + dz13 * dz13;
	dvec3 d21 = dx21 * dx21 + dy21 * dy21 + dz21 * dz21;
	dvec3 d22 = dx22 * dx22 + dy22 * dy22 + dz22 * dz22;
	dvec3 d23 = dx23 * dx23 + dy23 * dy23 + dz23 * dz23;
	dvec3 d31 = dx31 * dx31 + dy31 * dy31 + dz31 * dz31;
	dvec3 d32 = dx32 * dx32 + dy32 * dy32 + dz32 * dz32;
	dvec3 d33 = dx33 * dx33 + dy33 * dy33 + dz33 * dz33;
	
	// Do it right and sort out both F1 and F2
	dvec3 d1a = min(d11, d12);
	d12 = max(d11, d12);
	d11 = min(d1a, d13); // Smallest now not in d12 or d13
	d13 = max(d1a, d13);
	d12 = min(d12, d13); // 2nd smallest now not in d13
	dvec3 d2a = min(d21, d22);
	d22 = max(d21, d22);
	d21 = min(d2a, d23); // Smallest now not in d22 or d23
	d23 = max(d2a, d23);
	d22 = min(d22, d23); // 2nd smallest now not in d23
	dvec3 d3a = min(d31, d32);
	d32 = max(d31, d32);
	d31 = min(d3a, d33); // Smallest now not in d32 or d33
	d33 = max(d3a, d33);
	d32 = min(d32, d33); // 2nd smallest now not in d33
	dvec3 da = min(d11, d21);
	d21 = max(d11, d21);
	d11 = min(da, d31); // Smallest now in d11
	d31 = max(da, d31); // 2nd smallest now not in d31
	d11.xy = (d11.x < d11.y) ? d11.xy : d11.yx;
	d11.xz = (d11.x < d11.z) ? d11.xz : d11.zx; // d11.x now smallest
	d12 = min(d12, d21); // 2nd smallest now not in d21
	d12 = min(d12, d22); // nor in d22
	d12 = min(d12, d31); // nor in d31
	d12 = min(d12, d32); // nor in d32
	d11.yz = min(d11.yz, d12.xy); // nor in d12.yz
	d11.y = min(d11.y, d12.z); // Only two more to go
	d11.y = min(d11.y, d11.z); // Done! (Phew!)
	return sqrt(d11.xy); // F1, F2

#undef K										
#undef Ko
#undef K2
#undef Kz
#undef Kzo
#undef jitter
}
double voronoi1(dvec3 v)
{
	// Only return F1
	return voronoi1_source(v).x;
}

// Cellular noise ("Worley noise") in 3D in GLSL.
// Copyright (c) Stefan Gustavson 2011-04-19. All rights reserved.
// This code is released under the conditions of the MIT license.
// See LICENSE file for details.
// https://github.com/stegu/webgl-noise

// Modulo 289 without a division (only multiplications)
dvec3 voronoi2_mod289(dvec3 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}
// Modulo 7 without a division
dvec3 voronoi2_mod7(dvec3 x)
{
	return x - floor(x * (1.0 / 7.0)) * 7.0;
}
// Permutation polynomial: (34x^2 + x) mod 289
dvec3 voronoi2_permute(dvec3 x)
{
	return voronoi2_mod289((34.0 * x + 1.0) * x);
}

// Cellular noise, returning F1 and F2 in a dvec2.
// 3x3x3 search region for good F2 everywhere, but a lot
// slower than the 2x2x2 version.
// The code below is a bit scary even to its author,
// but it has at least half decent performance on a
// modern GPU. In any case, it beats any software
// implementation of Worley noise hands down.
dvec2 voronoi2_source(dvec3 P)
{
#define K 0.142857142857 // 1/7
#define Ko 0.428571428571 // 1/2-K/2
#define K2 0.020408163265306 // 1/(7*7)
#define Kz 0.166666666667 // 1/6
#define Kzo 0.416666666667 // 1/2-1/6*2
#define jitter 1.0 // smaller jitter gives more regular pattern

	dvec3 Pi = voronoi2_mod289(floor(P));
	dvec3 Pf = fract(P) - 0.5;
	
	dvec3 Pfx = Pf.x + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfy = Pf.y + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfz = Pf.z + dvec3(1.0, 0.0, -1.0);
	
	dvec3 p = voronoi2_permute(Pi.x + dvec3(-1.0, 0.0, 1.0));
	dvec3 p1 = voronoi2_permute(p + Pi.y - 1.0);
	dvec3 p2 = voronoi2_permute(p + Pi.y);
	dvec3 p3 = voronoi2_permute(p + Pi.y + 1.0);
	
	dvec3 p11 = voronoi2_permute(p1 + Pi.z - 1.0);
	dvec3 p12 = voronoi2_permute(p1 + Pi.z);
	dvec3 p13 = voronoi2_permute(p1 + Pi.z + 1.0);
	
	dvec3 p21 = voronoi2_permute(p2 + Pi.z - 1.0);
	dvec3 p22 = voronoi2_permute(p2 + Pi.z);
	dvec3 p23 = voronoi2_permute(p2 + Pi.z + 1.0);
	
	dvec3 p31 = voronoi2_permute(p3 + Pi.z - 1.0);
	dvec3 p32 = voronoi2_permute(p3 + Pi.z);
	dvec3 p33 = voronoi2_permute(p3 + Pi.z + 1.0);
	
	dvec3 ox11 = fract(p11 * K) - Ko;
	dvec3 oy11 = voronoi2_mod7(floor(p11 * K)) * K - Ko;
	dvec3 oz11 = floor(p11 * K2) * Kz - Kzo; // p11 < 289 guaranteed
	
	dvec3 ox12 = fract(p12 * K) - Ko;
	dvec3 oy12 = voronoi2_mod7(floor(p12 * K)) * K - Ko;
	dvec3 oz12 = floor(p12 * K2) * Kz - Kzo;
	
	dvec3 ox13 = fract(p13 * K) - Ko;
	dvec3 oy13 = voronoi2_mod7(floor(p13 * K)) * K - Ko;
	dvec3 oz13 = floor(p13 * K2) * Kz - Kzo;
	
	dvec3 ox21 = fract(p21 * K) - Ko;
	dvec3 oy21 = voronoi2_mod7(floor(p21 * K)) * K - Ko;
	dvec3 oz21 = floor(p21 * K2) * Kz - Kzo;
	
	dvec3 ox22 = fract(p22 * K) - Ko;
	dvec3 oy22 = voronoi2_mod7(floor(p22 * K)) * K - Ko;
	dvec3 oz22 = floor(p22 * K2) * Kz - Kzo;
	
	dvec3 ox23 = fract(p23 * K) - Ko;
	dvec3 oy23 = voronoi2_mod7(floor(p23 * K)) * K - Ko;
	dvec3 oz23 = floor(p23 * K2) * Kz - Kzo;
	
	dvec3 ox31 = fract(p31 * K) - Ko;
	dvec3 oy31 = voronoi2_mod7(floor(p31 * K)) * K - Ko;
	dvec3 oz31 = floor(p31 * K2) * Kz - Kzo;
	
	dvec3 ox32 = fract(p32 * K) - Ko;
	dvec3 oy32 = voronoi2_mod7(floor(p32 * K)) * K - Ko;
	dvec3 oz32 = floor(p32 * K2) * Kz - Kzo;
	
	dvec3 ox33 = fract(p33 * K) - Ko;
	dvec3 oy33 = voronoi2_mod7(floor(p33 * K)) * K - Ko;
	dvec3 oz33 = floor(p33 * K2) * Kz - Kzo;
	
	dvec3 dx11 = Pfx + jitter * ox11;
	dvec3 dy11 = Pfy.x + jitter * oy11;
	dvec3 dz11 = Pfz.x + jitter * oz11;
	
	dvec3 dx12 = Pfx + jitter * ox12;
	dvec3 dy12 = Pfy.x + jitter * oy12;
	dvec3 dz12 = Pfz.y + jitter * oz12;
	
	dvec3 dx13 = Pfx + jitter * ox13;
	dvec3 dy13 = Pfy.x + jitter * oy13;
	dvec3 dz13 = Pfz.z + jitter * oz13;
	
	dvec3 dx21 = Pfx + jitter * ox21;
	dvec3 dy21 = Pfy.y + jitter * oy21;
	dvec3 dz21 = Pfz.x + jitter * oz21;
	
	dvec3 dx22 = Pfx + jitter * ox22;
	dvec3 dy22 = Pfy.y + jitter * oy22;
	dvec3 dz22 = Pfz.y + jitter * oz22;
	
	dvec3 dx23 = Pfx + jitter * ox23;
	dvec3 dy23 = Pfy.y + jitter * oy23;
	dvec3 dz23 = Pfz.z + jitter * oz23;
	
	dvec3 dx31 = Pfx + jitter * ox31;
	dvec3 dy31 = Pfy.z + jitter * oy31;
	dvec3 dz31 = Pfz.x + jitter * oz31;
	
	dvec3 dx32 = Pfx + jitter * ox32;
	dvec3 dy32 = Pfy.z + jitter * oy32;
	dvec3 dz32 = Pfz.y + jitter * oz32;
	
	dvec3 dx33 = Pfx + jitter * ox33;
	dvec3 dy33 = Pfy.z + jitter * oy33;
	dvec3 dz33 = Pfz.z + jitter * oz33;
	
	dvec3 d11 = dx11 * dx11 + dy11 * dy11 + dz11 * dz11;
	dvec3 d12 = dx12 * dx12 + dy12 * dy12 + dz12 * dz12;
	dvec3 d13 = dx13 * dx13 + dy13 * dy13 + dz13 * dz13;
	dvec3 d21 = dx21 * dx21 + dy21 * dy21 + dz21 * dz21;
	dvec3 d22 = dx22 * dx22 + dy22 * dy22 + dz22 * dz22;
	dvec3 d23 = dx23 * dx23 + dy23 * dy23 + dz23 * dz23;
	dvec3 d31 = dx31 * dx31 + dy31 * dy31 + dz31 * dz31;
	dvec3 d32 = dx32 * dx32 + dy32 * dy32 + dz32 * dz32;
	dvec3 d33 = dx33 * dx33 + dy33 * dy33 + dz33 * dz33;
	
	// Do it right and sort out both F1 and F2
	dvec3 d1a = min(d11, d12);
	d12 = max(d11, d12);
	d11 = min(d1a, d13); // Smallest now not in d12 or d13
	d13 = max(d1a, d13);
	d12 = min(d12, d13); // 2nd smallest now not in d13
	dvec3 d2a = min(d21, d22);
	d22 = max(d21, d22);
	d21 = min(d2a, d23); // Smallest now not in d22 or d23
	d23 = max(d2a, d23);
	d22 = min(d22, d23); // 2nd smallest now not in d23
	dvec3 d3a = min(d31, d32);
	d32 = max(d31, d32);
	d31 = min(d3a, d33); // Smallest now not in d32 or d33
	d33 = max(d3a, d33);
	d32 = min(d32, d33); // 2nd smallest now not in d33
	dvec3 da = min(d11, d21);
	d21 = max(d11, d21);
	d11 = min(da, d31); // Smallest now in d11
	d31 = max(da, d31); // 2nd smallest now not in d31
	d11.xy = (d11.x < d11.y) ? d11.xy : d11.yx;
	d11.xz = (d11.x < d11.z) ? d11.xz : d11.zx; // d11.x now smallest
	d12 = min(d12, d21); // 2nd smallest now not in d21
	d12 = min(d12, d22); // nor in d22
	d12 = min(d12, d31); // nor in d31
	d12 = min(d12, d32); // nor in d32
	d11.yz = min(d11.yz, d12.xy); // nor in d12.yz
	d11.y = min(d11.y, d12.z); // Only two more to go
	d11.y = min(d11.y, d11.z); // Done! (Phew!)
	return sqrt(d11.xy); // F1, F2

#undef K										
#undef Ko
#undef K2
#undef Kz
#undef Kzo
#undef jitter
}
double voronoi2(dvec3 v)
{
	// Only return F2
	return voronoi2_source(v).y;
}

double noise(dvec3 _v)
{
	dvec3 v = _v;
	double total = 0.0;
	double maxAmplitude = 0.0;
	double amplitude = 1.0;
	double frequency = 1.0;
	uint octaves = 8;
	double persistance = voronoi1(v);
	double lacunarity = voronoi1(v);

	for (uint i = 0; i < octaves; ++i)
	{
		v = _v * frequency;
		total += simplex1(v) * amplitude;
		frequency *= lacunarity;
		maxAmplitude += amplitude;
		amplitude *= persistance;
	}

	return total / maxAmplitude;
}


dvec3 to_sphere(in dvec3 v)
{
	// _pos.w is planet_radius
	return _pos.w * normalize(v);
}

void main()
{
	const dvec3 pos = _pos.xyz;
	const dvec3 nwc = _nwc.xyz;
	const dvec3 nec = _nec.xyz;
	const dvec3 swc = _swc.xyz;
	const dvec3 sec = _sec.xyz;
	const double planet_radius = _pos.w;
	const double skirt_depth = _nwc.w;
	const double scale = _nec.w;

#define SIDE_LEN 129
#define INTERP (1.0 / (SIDE_LEN - 1))
	uint WorkGroupIndex = gl_WorkGroupID.z * gl_WorkGroupSize.x * gl_WorkGroupSize.y
		+ gl_WorkGroupID.y * gl_WorkGroupSize.x
		+ gl_WorkGroupID.x;
	uint index = WorkGroupIndex + gl_LocalInvocationIndex;

	if (index >= size)
		return;

	vec3 vertex;
	vec3 normal;
	float displacement;

	if (index < SIDE_LEN * SIDE_LEN)
	{
		double interp = INTERP * double(index / SIDE_LEN);
		dvec3 v1 = mix(nwc, nec, interp);
		dvec3 v2 = mix(swc, sec, interp);
		dvec3 vtx = to_sphere(mix(v1, v2, INTERP * double(index % SIDE_LEN)));
		dvec3 normal = normalize(vtx);
		double displacement = noise(vtx) * scale;
		vtx += normal * displacement - pos;

		vertex = vec3(vtx);
		normal = vec3(normal);
		displacement = float(displacement);
	}
	else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN)
	{
		dvec3 vertex = to_sphere(mix(nwc, swc, INTERP * double(index - (SIDE_LEN * SIDE_LEN))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		vertex = vec3(vertex);
		normal = vec3(normal);
		displacement = float(-skirt_depth);
	}
	else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 2)
	{
		dvec3 vertex = to_sphere(mix(swc, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		vertex = vec3(vertex);
		normal = vec3(normal);
		displacement = float(-skirt_depth);
	}
	else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 3)
	{
		dvec3 vertex = to_sphere(mix(nec, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 2))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		vertex = vec3(vertex);
		normal = vec3(normal);
		displacement = float(-skirt_depth);
	}
	else
	{
		dvec3 vertex = to_sphere(mix(nwc, nec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 3))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		vertex = vec3(vertex);
		normal = vec3(normal);
		displacement = float(-skirt_depth);
	}

	values[index * 7 + 0] = vertex.x;
	values[index * 7 + 1] = vertex.y;
	values[index * 7 + 2] = vertex.z;
	values[index * 7 + 3] = normal.x;
	values[index * 7 + 4] = normal.y;
	values[index * 7 + 5] = normal.z;
	values[index * 7 + 6] = displacement;
}
