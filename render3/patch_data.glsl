
struct patch_data
{
	// Corners
	dvec3 nwc; // Quadrant 0
	dvec3 nec; // Quadrant 1
	dvec3 swc; // Quadrant 2
	dvec3 sec; // Quadrant 3
	// Position transformed by noise function
	// (in planet space)
	dvec3 pos; 

	// Indices of children
	uint nw;
	uint ne;
	uint sw;
	uint se;

	uint level; // Level within the quadtree
	uint parent; // Index of the parent of this patch
	float farthest_vertex;

	uint _vpad;
};

#define INVALID_LEVEL (~0u)
#define INVALID_INDEX (~0u)
#define MULT (1.0 / 10.0)
#define FLT_MAX 3.402823466e+38F
