#version 150

in  vec3 inPosition;
in  vec3 inNormal;

out vec3 normal;
out vec3 lightdir;

// NY
uniform mat4 projMatrix;
uniform mat4 mdlMatrix;

void main(void)
{

	mat3 normalMatrix = mat3(mdlMatrix);
	lightdir = normalMatrix*vec3(0.0,1.0,0.0);
	normal = normalMatrix*inNormal;
	gl_Position = projMatrix * mdlMatrix * vec4(inPosition, 1.0);
}