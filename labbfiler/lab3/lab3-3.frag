#version 150

in vec3 normal;
out vec4 out_Color;
in vec3 positionInView;

uniform float specularExponent[4];
uniform bool isDirectional[4];
uniform vec3 lightSourcesDirPosArr[4];
uniform vec3 lightSourcesColorArr[4];

void main(void)
{
	vec3 viewDir = -normalize(positionInView);
	float distance = length(positionInView);	
	vec3 lightDir;
	vec3 resulting_color=vec3(0.0,0.0,0.0);
	int i;
	for(i = 0; i < 4; i++){
		if(!isDirectional[i]){
			lightDir = normalize(lightSourcesDirPosArr[i] - positionInView);
		}else{
			lightDir = -normalize(lightSourcesDirPosArr[i]);	
		}
		
		float intensity = clamp(dot(normalize(normal),lightDir),0.0,1.0);
		float diffuse_shading = intensity;	

		float base = clamp(dot(normalize(normal), normalize(lightDir - viewDir) ),0.0,1.0);
	
		intensity = pow(base,specularExponent[i]); 		

		float specular_shading = intensity; 
		
		vec3 color = lightSourcesColorArr[i];

		resulting_color += color*specular_shading  + color*diffuse_shading*0.2;

	}
	
	out_Color = vec4(resulting_color,0.0);
}