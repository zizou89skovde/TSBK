#version 150

in vec3 normal;
in vec2 TexCoord;
out vec4 out_Color;

void main(void)
{
	const vec3 light = vec3(0.0,1.0,0.0);
	float shade = dot(normalize(normal), light);

	//out_Color = vec4(shade, shade, shade, 1.0);
	out_Color = vec4(TexCoord.x, TexCoord.y, 0, 1.0);
}