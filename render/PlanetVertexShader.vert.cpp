const char* PlanetVertexShader = 
"#version 430\n"
"\n"
"layout(location = 0) in vec3 vertex;\n"
"layout(location = 1) in vec3 texcoord;\n"
"layout(location = 2) in float displacement;\n"
"\n"
"smooth out float height;\n"
"\n"
"layout(location = 0) uniform mat4 mvp;\n"
"\n"
"void main()\n"
"{\n"
"	gl_Position = mvp * vec4(vertex, 1.0);\n"
"	height = displacement;\n"
"}\n"
;

