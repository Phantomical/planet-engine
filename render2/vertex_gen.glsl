#version 440

layout(local_size_x = 8, local_size_y = 8) in;

layout(location = 0) uniform uint SIDE_LEN;

layout(binding = 0, std430) writeonly buffer Output
{
	vec4 vertices[];
};

layout(binding = 0, std140) uniform GeneratorInputs
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};


uint _voronoi_0_lcgRandom(uint lastValue)
{
	return uint(1103515245u) * lastValue + 12345u;

}
uint _voronoi_0_hash(uint i, uint j, uint k)
{
#define OFFSET_BASIS 2166136261
#define FNV_PRIME 16777619
	return ((((((OFFSET_BASIS ^ i) * FNV_PRIME) ^ j) * FNV_PRIME) ^ k) * FNV_PRIME);
#undef OFFSET_BASIS
#undef FNV_PRIME
}
uint _voronoi_0_probLookup(uint value)
{
	if (value < 393325350) return 1;
	if (value < 1022645910) return 2;
	if (value < 1861739990) return 3;
	if (value < 2700834071) return 4;
	if (value < 3372109335) return 5;
	if (value < 3819626178) return 6;
	if (value < 4075350088) return 7;
	if (value < 4203212043) return 8;
	return 9;
}
// Cellular noise ("Worley noise") in 3D in GLSL.
// Copyright (c) Stefan Gustavson 2011-04-19. All rights reserved.
// This code is released under the conditions of the MIT license.
// See LICENSE file for details.
// https://github.com/stegu/webgl-noise

// Modulo 289 without a division (only multiplications)
dvec3 _voronoi_0_mod289(dvec3 x) {
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}

// Modulo 7 without a division
dvec3 _voronoi_0_mod7(dvec3 x) {
	return x - floor(x * (1.0 / 7.0)) * 7.0;
}

// Permutation polynomial: (34x^2 + x) mod 289
dvec3 _voronoi_0_permute(dvec3 x) {
	return _voronoi_0_mod289((34.0 * x + 1.0) * x);
}

// Cellular noise, returning F1 and F2 in a vec2.
// 3x3x3 search region for good F2 everywhere, but a lot
// slower than the 2x2x2 version.
// The code below is a bit scary even to its author,
// but it has at least half decent performance on a
// modern GPU. In any case, it beats any software
// implementation of Worley noise hands down.

dvec2 _voronoi_0_source(dvec3 P) {
#define K 0.142857142857 // 1/7
#define Ko 0.428571428571 // 1/2-K/2
#define K2 0.020408163265306 // 1/(7*7)
#define Kz 0.166666666667 // 1/6
#define Kzo 0.416666666667 // 1/2-1/6*2
#define jitter 1.0 // smaller jitter gives more regular pattern

	dvec3 Pi = _voronoi_0_mod289(floor(P));
	dvec3 Pf = fract(P) - 0.5;

	dvec3 Pfx = Pf.x + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfy = Pf.y + dvec3(1.0, 0.0, -1.0);
	dvec3 Pfz = Pf.z + dvec3(1.0, 0.0, -1.0);

	dvec3 p = _voronoi_0_permute(Pi.x + dvec3(-1.0, 0.0, 1.0));
	dvec3 p1 = _voronoi_0_permute(p + Pi.y - 1.0);
	dvec3 p2 = _voronoi_0_permute(p + Pi.y);
	dvec3 p3 = _voronoi_0_permute(p + Pi.y + 1.0);

	dvec3 p11 = _voronoi_0_permute(p1 + Pi.z - 1.0);
	dvec3 p12 = _voronoi_0_permute(p1 + Pi.z);
	dvec3 p13 = _voronoi_0_permute(p1 + Pi.z + 1.0);

	dvec3 p21 = _voronoi_0_permute(p2 + Pi.z - 1.0);
	dvec3 p22 = _voronoi_0_permute(p2 + Pi.z);
	dvec3 p23 = _voronoi_0_permute(p2 + Pi.z + 1.0);

	dvec3 p31 = _voronoi_0_permute(p3 + Pi.z - 1.0);
	dvec3 p32 = _voronoi_0_permute(p3 + Pi.z);
	dvec3 p33 = _voronoi_0_permute(p3 + Pi.z + 1.0);

	dvec3 ox11 = fract(p11*K) - Ko;
	dvec3 oy11 = _voronoi_0_mod7(floor(p11*K))*K - Ko;
	dvec3 oz11 = floor(p11*K2)*Kz - Kzo; // p11 < 289 guaranteed

	dvec3 ox12 = fract(p12*K) - Ko;
	dvec3 oy12 = _voronoi_0_mod7(floor(p12*K))*K - Ko;
	dvec3 oz12 = floor(p12*K2)*Kz - Kzo;

	dvec3 ox13 = fract(p13*K) - Ko;
	dvec3 oy13 = _voronoi_0_mod7(floor(p13*K))*K - Ko;
	dvec3 oz13 = floor(p13*K2)*Kz - Kzo;

	dvec3 ox21 = fract(p21*K) - Ko;
	dvec3 oy21 = _voronoi_0_mod7(floor(p21*K))*K - Ko;
	dvec3 oz21 = floor(p21*K2)*Kz - Kzo;

	dvec3 ox22 = fract(p22*K) - Ko;
	dvec3 oy22 = _voronoi_0_mod7(floor(p22*K))*K - Ko;
	dvec3 oz22 = floor(p22*K2)*Kz - Kzo;

	dvec3 ox23 = fract(p23*K) - Ko;
	dvec3 oy23 = _voronoi_0_mod7(floor(p23*K))*K - Ko;
	dvec3 oz23 = floor(p23*K2)*Kz - Kzo;

	dvec3 ox31 = fract(p31*K) - Ko;
	dvec3 oy31 = _voronoi_0_mod7(floor(p31*K))*K - Ko;
	dvec3 oz31 = floor(p31*K2)*Kz - Kzo;

	dvec3 ox32 = fract(p32*K) - Ko;
	dvec3 oy32 = _voronoi_0_mod7(floor(p32*K))*K - Ko;
	dvec3 oz32 = floor(p32*K2)*Kz - Kzo;

	dvec3 ox33 = fract(p33*K) - Ko;
	dvec3 oy33 = _voronoi_0_mod7(floor(p33*K))*K - Ko;
	dvec3 oz33 = floor(p33*K2)*Kz - Kzo;

	dvec3 dx11 = Pfx + jitter*ox11;
	dvec3 dy11 = Pfy.x + jitter*oy11;
	dvec3 dz11 = Pfz.x + jitter*oz11;

	dvec3 dx12 = Pfx + jitter*ox12;
	dvec3 dy12 = Pfy.x + jitter*oy12;
	dvec3 dz12 = Pfz.y + jitter*oz12;

	dvec3 dx13 = Pfx + jitter*ox13;
	dvec3 dy13 = Pfy.x + jitter*oy13;
	dvec3 dz13 = Pfz.z + jitter*oz13;

	dvec3 dx21 = Pfx + jitter*ox21;
	dvec3 dy21 = Pfy.y + jitter*oy21;
	dvec3 dz21 = Pfz.x + jitter*oz21;

	dvec3 dx22 = Pfx + jitter*ox22;
	dvec3 dy22 = Pfy.y + jitter*oy22;
	dvec3 dz22 = Pfz.y + jitter*oz22;

	dvec3 dx23 = Pfx + jitter*ox23;
	dvec3 dy23 = Pfy.y + jitter*oy23;
	dvec3 dz23 = Pfz.z + jitter*oz23;

	dvec3 dx31 = Pfx + jitter*ox31;
	dvec3 dy31 = Pfy.z + jitter*oy31;
	dvec3 dz31 = Pfz.x + jitter*oz31;

	dvec3 dx32 = Pfx + jitter*ox32;
	dvec3 dy32 = Pfy.z + jitter*oy32;
	dvec3 dz32 = Pfz.y + jitter*oz32;

	dvec3 dx33 = Pfx + jitter*ox33;
	dvec3 dy33 = Pfy.z + jitter*oy33;
	dvec3 dz33 = Pfz.z + jitter*oz33;

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
double _voronoi_0_selector(dvec2 v)
{
	return v.x;
}
double _voronoi_0(dvec3 v)
{
	return _voronoi_0_selector(_voronoi_0_source(v));
}
double noise(dvec3 v)
{
	return (1.0 - _voronoi_0(v));
}

const dvec3 pos = _pos.xyz;
const dvec3 nwc = _nwc.xyz;
const dvec3 nec = _nec.xyz;
const dvec3 swc = _swc.xyz;
const dvec3 sec = _sec.xyz;
const double planet_radius = _pos.w;
const double skirt_depth = _nwc.w;
const double scale = _nec.w;
const double INTERP = (1.0 / double(SIDE_LEN - 1));
const uint array_size = SIDE_LEN + 2;

dvec3 to_sphere(in dvec3 v)
{
	return planet_radius * normalize(v);
}

void calc_vertex(in ivec2 p, out vec3 vertex, out float displacement)
{
	double interp = INTERP * double(p.x);
	dvec3 v1 = mix(nwc, nec, interp);
	dvec3 v2 = mix(swc, sec, interp);
	dvec3 vtx = to_sphere(mix(v1, v2, INTERP * double(p.y)));
	dvec3 nrm = normalize(vtx);
	double disp = noise(nrm) * scale;
	vtx += nrm * disp - pos;

	vertex = vec3(vtx);
	displacement = float(disp);
}

void write(in uvec2 idx, in vec4 val)
{
	vertices[idx.y * array_size + idx.x] = val;
}

void main()
{
	if (gl_GlobalInvocationID.x > SIDE_LEN + 2 || gl_GlobalInvocationID.y > SIDE_LEN + 2)
		// This shader doesn't have an output (it is out of bounds)
		return;

	ivec2 p = ivec2(gl_GlobalInvocationID.xy) - ivec2(1);

	vec3 vertex;
	float displacement;

	calc_vertex(p, vertex, displacement);

	write(gl_GlobalInvocationID.xy, vec4(vertex, displacement));
}
