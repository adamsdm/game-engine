#version 330 core

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 Color;
uniform sampler2D Texture;

void main(){

	float ambientStrength = 0.2;
	vec3 LightColor = vec3(1.0, 1.0, 1.0);
	vec3 LightPos = vec3(0.0, 2.0, 2.0);

	vec3 norm = normalize(Normal);
	vec3 LightDir = normalize(LightPos - FragPos);
	float diff = max(dot(norm, LightDir), 0.0);

	vec3 ambient = ambientStrength * LightColor;
	vec3 diffuse = diff * LightColor;

	vec4 TexColor = texture(Texture, TexCoord);
	vec3 result = (ambient + diffuse) * vec3(TexColor);

	FragColor = vec4(result, 1.0);
}
