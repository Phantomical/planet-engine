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
dvec3 _simplex_0_mod289(dvec3 x) {
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
dvec4 _simplex_0_mod289(dvec4 x) {
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
dvec4 _simplex_0_permute(dvec4 x) {
     return _simplex_0_mod289(((x*34.0)+1.0)*x);
}
dvec4 _simplex_0_taylorInvSqrt(dvec4 r)
{
  return 1.79284291400159 - 0.85373472095314 * r;
}
double _simplex_0(dvec3 v)
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
  i = _simplex_0_mod289(i); 
  dvec4 p = _simplex_0_permute( _simplex_0_permute( _simplex_0_permute( 
             i.z + dvec4(0.0, i1.z, i2.z, 1.0 ))
           + i.y + dvec4(0.0, i1.y, i2.y, 1.0 )) 
           + i.x + dvec4(0.0, i1.x, i2.x, 1.0 ));

// Gradients: 7x7 points over a square, mapped onto an octahedron.
// The ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)
  float n_ = 0.142857142857; // 1.0/7.0
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
  dvec4 norm = _simplex_0_taylorInvSqrt(dvec4(dot(p0,p0), dot(p1,p1), dot(p2, p2), dot(p3,p3)));
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
double _scale_1(dvec3 v){
	return _simplex_0(v * (vec3(75.0)));
}
double _max_2(dvec3 v){
	return max(_scale_1(v), -5.0);
}
double noise(dvec3 v)
{
	return _max_2(v);
}

