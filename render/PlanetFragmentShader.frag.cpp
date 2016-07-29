const char* PlanetFragmentShader = 
"#version 330\n"
"\n"
"smooth in float height;\n"
"\n"
"out vec3 colour;\n"
"\n"
"void main()\n"
"{\n"
"	colour = vec3(height, 0.0, 0.0);\n"
"}\n"
;

