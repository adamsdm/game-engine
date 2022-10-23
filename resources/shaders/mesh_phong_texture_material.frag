#version 330 core

// Inputs
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

// Outputs
out vec4 FragColor;

// Uniforms
uniform vec4 Color;
uniform vec3 ViewPos;

// TODO: Implement uniforms 
uniform bool UseTexture;
uniform sampler2D Texture;
uniform bool UseSpecularMap;
uniform sampler2D SpecularMap;
uniform bool UseNormalMap;
uniform sampler2D NormalMap;

// TODO: Move to uniforms
float ambientStrength = 0.2;
vec3 LightColor = vec3(1.0, 1.0, 1.0);
vec3 LightPos = vec3(0.0, 0.0, 2.0);
float specularStrength = 0.9;

// Global variables
vec3 norm = normalize(Normal);
vec3 LightDir = normalize(LightPos - FragPos);


vec3 calculate_ambient() {
	vec3 ambient = ambientStrength * LightColor; 
	return ambient;
};

vec3 calculate_diffuse() {
	float diff = max(dot(norm, LightDir), 0.0);
	vec3 diffuse = diff * LightColor;
	return diffuse;
}

vec3 calculate_specular() {
    vec3 viewDir = normalize(ViewPos - FragPos);
    vec3 reflectDir = reflect(-LightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
	vec3 specular = specularStrength * spec * LightColor;
	return specular;
}

void main(){
	vec3 ambient = calculate_ambient();
    vec3 diffuse = calculate_diffuse();
	vec3 specular = calculate_specular(); 
	
	if(UseTexture) {
		vec3 diffuseTexColor = vec3(texture(Texture, TexCoord));
		ambient *= diffuseTexColor;
		diffuse *= diffuseTexColor;
		specular *= diffuseTexColor;
	}

	if(UseSpecularMap) {
		vec3 specularTexColor = vec3(texture(SpecularMap, TexCoord));
		specular *= specularTexColor;
	}

	FragColor = vec4(ambient + diffuse + specular, 1.0);   
}
