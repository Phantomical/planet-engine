﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace noisemaker
{
	class Resources
	{
		#region fBm
		public static string fBm = @"
@scalar @name(@vec3 _v)
{
	@vec3 v = _v;
	@scalar total = 0.0;
	@scalar maxAmplitude = 0.0;
	@scalar amplitude = 1.0;
	@scalar frequency = @frequency;
	uint octaves = @octaves;
	@scalar persistance = @persistance;
	@scalar lacunarity = @lacunarity;

	for (uint i = 0; i < octaves; ++i)
	{
		v = _v * frequency;
		total += @base * amplitude;
		frequency *= lacunarity;
		maxAmplitude += amplitude;
		amplitude *= persistance;
	}

	return total / maxAmplitude;
}";
		#endregion
		#region Simplex
		public static string Simplex = @"
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

@vec3 @name_mod289(@vec3 x)
{
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
@vec4 @name_mod289(@vec4 x)
{
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
@vec4 @name_permute(@vec4 x)
{
     return @name_mod289(((x*34.0)+1.0)*x);
}
@vec4 @name_taylorInvSqrt(@vec4 r)
{
  return 1.79284291400159 - 0.85373472095314 * r;
}
@scalar @name(@vec3 v)
{ 
  const @vec2  C = @vec2(1.0/6.0, 1.0/3.0) ;
  const @vec4  D = @vec4(0.0, 0.5, 1.0, 2.0);

// First corner
  @vec3 i  = floor(v + dot(v, C.yyy) );
  @vec3 x0 =   v - i + dot(i, C.xxx) ;

// Other corners
  @vec3 g = step(x0.yzx, x0.xyz);
  @vec3 l = 1.0 - g;
  @vec3 i1 = min( g.xyz, l.zxy );
  @vec3 i2 = max( g.xyz, l.zxy );

  //   x0 = x0 - 0.0 + 0.0 * C.xxx;
  //   x1 = x0 - i1  + 1.0 * C.xxx;
  //   x2 = x0 - i2  + 2.0 * C.xxx;
  //   x3 = x0 - 1.0 + 3.0 * C.xxx;
  @vec3 x1 = x0 - i1 + C.xxx;
  @vec3 x2 = x0 - i2 + C.yyy; // 2.0*C.x = 1/3 = C.y
  @vec3 x3 = x0 - D.yyy;      // -1.0+3.0*C.x = -0.5 = -D.y

// Permutations
  i = @name_mod289(i); 
  @vec4 p = @name_permute( @name_permute( @name_permute( 
             i.z + @vec4(0.0, i1.z, i2.z, 1.0 ))
           + i.y + @vec4(0.0, i1.y, i2.y, 1.0 )) 
           + i.x + @vec4(0.0, i1.x, i2.x, 1.0 ));

// Gradients: 7x7 points over a square, mapped onto an octahedron.
// The ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)
  @scalar n_ = 0.142857142857; // 1.0/7.0
  @vec3  ns = n_ * D.wyz - D.xzx;

  @vec4 j = p - 49.0 * floor(p * ns.z * ns.z);  //  mod(p,7*7)

  @vec4 x_ = floor(j * ns.z);
  @vec4 y_ = floor(j - 7.0 * x_ );    // mod(j,N)

  @vec4 x = x_ *ns.x + ns.yyyy;
  @vec4 y = y_ *ns.x + ns.yyyy;
  @vec4 h = 1.0 - abs(x) - abs(y);

  @vec4 b0 = @vec4( x.xy, y.xy );
  @vec4 b1 = @vec4( x.zw, y.zw );

  //@vec4 s0 = @vec4(lessThan(b0,0.0))*2.0 - 1.0;
  //@vec4 s1 = @vec4(lessThan(b1,0.0))*2.0 - 1.0;
  @vec4 s0 = floor(b0)*2.0 + 1.0;
  @vec4 s1 = floor(b1)*2.0 + 1.0;
  @vec4 sh = -step(h, @vec4(0.0));

  @vec4 a0 = b0.xzyw + s0.xzyw*sh.xxyy ;
  @vec4 a1 = b1.xzyw + s1.xzyw*sh.zzww ;

  @vec3 p0 = @vec3(a0.xy,h.x);
  @vec3 p1 = @vec3(a0.zw,h.y);
  @vec3 p2 = @vec3(a1.xy,h.z);
  @vec3 p3 = @vec3(a1.zw,h.w);

//Normalise gradients
  @vec4 norm = @name_taylorInvSqrt(@vec4(dot(p0,p0), dot(p1,p1), dot(p2, p2), dot(p3,p3)));
  p0 *= norm.x;
  p1 *= norm.y;
  p2 *= norm.z;
  p3 *= norm.w;

// Mix final noise value
  @vec4 m = max(0.6 - @vec4(dot(x0,x0), dot(x1,x1), dot(x2,x2), dot(x3,x3)), 0.0);
  m = m * m;
  return 42.0 * dot( m*m, @vec4( dot(p0,x0), dot(p1,x1), 
                                dot(p2,x2), dot(p3,x3) ) );
}";
		#endregion
		#region Voronoi
		public static string Voronoi = @"
// Cellular noise (""Worley noise"") in 3D in GLSL.
// Copyright (c) Stefan Gustavson 2011-04-19. All rights reserved.
// This code is released under the conditions of the MIT license.
// See LICENSE file for details.
// https://github.com/stegu/webgl-noise

// Modulo 289 without a division (only multiplications)
@vec3 @name_mod289(@vec3 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}
// Modulo 7 without a division
@vec3 @name_mod7(@vec3 x)
{
	return x - floor(x * (1.0 / 7.0)) * 7.0;
}
// Permutation polynomial: (34x^2 + x) mod 289
@vec3 @name_permute(@vec3 x)
{
	return @name_mod289((34.0 * x + 1.0) * x);
}

// Cellular noise, returning F1 and F2 in a @vec2.
// 3x3x3 search region for good F2 everywhere, but a lot
// slower than the 2x2x2 version.
// The code below is a bit scary even to its author,
// but it has at least half decent performance on a
// modern GPU. In any case, it beats any software
// implementation of Worley noise hands down.
@vec2 @name_source(@vec3 P)
{
#define K 0.142857142857 // 1/7
#define Ko 0.428571428571 // 1/2-K/2
#define K2 0.020408163265306 // 1/(7*7)
#define Kz 0.166666666667 // 1/6
#define Kzo 0.416666666667 // 1/2-1/6*2
#define jitter 1.0 // smaller jitter gives more regular pattern

	@vec3 Pi = @name_mod289(floor(P));
	@vec3 Pf = fract(P) - 0.5;
	
	@vec3 Pfx = Pf.x + @vec3(1.0, 0.0, -1.0);
	@vec3 Pfy = Pf.y + @vec3(1.0, 0.0, -1.0);
	@vec3 Pfz = Pf.z + @vec3(1.0, 0.0, -1.0);
	
	@vec3 p = @name_permute(Pi.x + @vec3(-1.0, 0.0, 1.0));
	@vec3 p1 = @name_permute(p + Pi.y - 1.0);
	@vec3 p2 = @name_permute(p + Pi.y);
	@vec3 p3 = @name_permute(p + Pi.y + 1.0);
	
	@vec3 p11 = @name_permute(p1 + Pi.z - 1.0);
	@vec3 p12 = @name_permute(p1 + Pi.z);
	@vec3 p13 = @name_permute(p1 + Pi.z + 1.0);
	
	@vec3 p21 = @name_permute(p2 + Pi.z - 1.0);
	@vec3 p22 = @name_permute(p2 + Pi.z);
	@vec3 p23 = @name_permute(p2 + Pi.z + 1.0);
	
	@vec3 p31 = @name_permute(p3 + Pi.z - 1.0);
	@vec3 p32 = @name_permute(p3 + Pi.z);
	@vec3 p33 = @name_permute(p3 + Pi.z + 1.0);
	
	@vec3 ox11 = fract(p11 * K) - Ko;
	@vec3 oy11 = @name_mod7(floor(p11 * K)) * K - Ko;
	@vec3 oz11 = floor(p11 * K2) * Kz - Kzo; // p11 < 289 guaranteed
	
	@vec3 ox12 = fract(p12 * K) - Ko;
	@vec3 oy12 = @name_mod7(floor(p12 * K)) * K - Ko;
	@vec3 oz12 = floor(p12 * K2) * Kz - Kzo;
	
	@vec3 ox13 = fract(p13 * K) - Ko;
	@vec3 oy13 = @name_mod7(floor(p13 * K)) * K - Ko;
	@vec3 oz13 = floor(p13 * K2) * Kz - Kzo;
	
	@vec3 ox21 = fract(p21 * K) - Ko;
	@vec3 oy21 = @name_mod7(floor(p21 * K)) * K - Ko;
	@vec3 oz21 = floor(p21 * K2) * Kz - Kzo;
	
	@vec3 ox22 = fract(p22 * K) - Ko;
	@vec3 oy22 = @name_mod7(floor(p22 * K)) * K - Ko;
	@vec3 oz22 = floor(p22 * K2) * Kz - Kzo;
	
	@vec3 ox23 = fract(p23 * K) - Ko;
	@vec3 oy23 = @name_mod7(floor(p23 * K)) * K - Ko;
	@vec3 oz23 = floor(p23 * K2) * Kz - Kzo;
	
	@vec3 ox31 = fract(p31 * K) - Ko;
	@vec3 oy31 = @name_mod7(floor(p31 * K)) * K - Ko;
	@vec3 oz31 = floor(p31 * K2) * Kz - Kzo;
	
	@vec3 ox32 = fract(p32 * K) - Ko;
	@vec3 oy32 = @name_mod7(floor(p32 * K)) * K - Ko;
	@vec3 oz32 = floor(p32 * K2) * Kz - Kzo;
	
	@vec3 ox33 = fract(p33 * K) - Ko;
	@vec3 oy33 = @name_mod7(floor(p33 * K)) * K - Ko;
	@vec3 oz33 = floor(p33 * K2) * Kz - Kzo;
	
	@vec3 dx11 = Pfx + jitter * ox11;
	@vec3 dy11 = Pfy.x + jitter * oy11;
	@vec3 dz11 = Pfz.x + jitter * oz11;
	
	@vec3 dx12 = Pfx + jitter * ox12;
	@vec3 dy12 = Pfy.x + jitter * oy12;
	@vec3 dz12 = Pfz.y + jitter * oz12;
	
	@vec3 dx13 = Pfx + jitter * ox13;
	@vec3 dy13 = Pfy.x + jitter * oy13;
	@vec3 dz13 = Pfz.z + jitter * oz13;
	
	@vec3 dx21 = Pfx + jitter * ox21;
	@vec3 dy21 = Pfy.y + jitter * oy21;
	@vec3 dz21 = Pfz.x + jitter * oz21;
	
	@vec3 dx22 = Pfx + jitter * ox22;
	@vec3 dy22 = Pfy.y + jitter * oy22;
	@vec3 dz22 = Pfz.y + jitter * oz22;
	
	@vec3 dx23 = Pfx + jitter * ox23;
	@vec3 dy23 = Pfy.y + jitter * oy23;
	@vec3 dz23 = Pfz.z + jitter * oz23;
	
	@vec3 dx31 = Pfx + jitter * ox31;
	@vec3 dy31 = Pfy.z + jitter * oy31;
	@vec3 dz31 = Pfz.x + jitter * oz31;
	
	@vec3 dx32 = Pfx + jitter * ox32;
	@vec3 dy32 = Pfy.z + jitter * oy32;
	@vec3 dz32 = Pfz.y + jitter * oz32;
	
	@vec3 dx33 = Pfx + jitter * ox33;
	@vec3 dy33 = Pfy.z + jitter * oy33;
	@vec3 dz33 = Pfz.z + jitter * oz33;
	
	@vec3 d11 = dx11 * dx11 + dy11 * dy11 + dz11 * dz11;
	@vec3 d12 = dx12 * dx12 + dy12 * dy12 + dz12 * dz12;
	@vec3 d13 = dx13 * dx13 + dy13 * dy13 + dz13 * dz13;
	@vec3 d21 = dx21 * dx21 + dy21 * dy21 + dz21 * dz21;
	@vec3 d22 = dx22 * dx22 + dy22 * dy22 + dz22 * dz22;
	@vec3 d23 = dx23 * dx23 + dy23 * dy23 + dz23 * dz23;
	@vec3 d31 = dx31 * dx31 + dy31 * dy31 + dz31 * dz31;
	@vec3 d32 = dx32 * dx32 + dy32 * dy32 + dz32 * dz32;
	@vec3 d33 = dx33 * dx33 + dy33 * dy33 + dz33 * dz33;
	
	// Do it right and sort out both F1 and F2
	@vec3 d1a = min(d11, d12);
	d12 = max(d11, d12);
	d11 = min(d1a, d13); // Smallest now not in d12 or d13
	d13 = max(d1a, d13);
	d12 = min(d12, d13); // 2nd smallest now not in d13
	@vec3 d2a = min(d21, d22);
	d22 = max(d21, d22);
	d21 = min(d2a, d23); // Smallest now not in d22 or d23
	d23 = max(d2a, d23);
	d22 = min(d22, d23); // 2nd smallest now not in d23
	@vec3 d3a = min(d31, d32);
	d32 = max(d31, d32);
	d31 = min(d3a, d33); // Smallest now not in d32 or d33
	d33 = max(d3a, d33);
	d32 = min(d32, d33); // 2nd smallest now not in d33
	@vec3 da = min(d11, d21);
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
}";
		public static string VoronoiF1 = Voronoi + @"
@scalar @name(@vec3 v)
{
	// Only return F1
	return @name_source(v).x;
}";
		public static string VoronoiF2 = Voronoi + @"
@scalar @name(@vec3 v)
{
	// Only return F2
	return @name_source(v).y;
}";
		#endregion
		#region Constant
		public static string Constant = @"
@scalar @name(@vec3 v)
{
	return @value;
}";
		#endregion
	}
}
