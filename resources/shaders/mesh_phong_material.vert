#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texPos;
layout (location = 2) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 View;
uniform mat4 Projection;
uniform mat4 Model;

void main()
{
   gl_Position = Projection * View * Model * vec4(aPos, 1.0);
   FragPos = vec3(Model * vec4(aPos, 1.0));
   Normal = aNormal;
}
