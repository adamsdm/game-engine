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
uniform sampler2D Texture;


// TODO: Move to uniforms
float ambientStrength = 0.2;
vec3 LightColor = vec3(1.0, 1.0, 1.0);
vec3 LightPos = vec3(0.0, 2.0, 2.0);
float specularStrength = 0.5;

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
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * LightColor;
	return specular;
}

void main(){

	vec3 ambient = calculate_ambient();
    vec3 diffuse = calculate_diffuse();
	vec3 specular = calculate_specular(); 

	vec4 TexColor = texture(Texture, TexCoord);
	vec3 result = (ambient + diffuse + specular) * vec3(TexColor);

	FragColor = vec4(result, 1.0);
}
