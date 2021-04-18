#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;


out vec2 TexCoord;

uniform mat4 View;
uniform mat4 Projection;
uniform mat4 Model;

void main()
{
   TexCoord = aTexCoord;
   gl_Position = Projection * View * Model * vec4(aPos, 1.0);
}
