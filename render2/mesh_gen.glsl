#version 430

layout(local_size_x = 128) in;

// Vertex Information Layout:
//   vec3 vertex
//   vec3 normal
//   float displacement

layout(location = 0) uniform uint size;
layout(location = 1) uniform uint SIDE_LEN;

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


double noise(in dvec3 v)
{
	return 0.0;
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
	const double INTERP = (1.0 / double(SIDE_LEN - 1));

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
