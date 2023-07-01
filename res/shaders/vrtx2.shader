#version 330 core

layout (location = 0) in vec3 vpos;
layout (location = 1) in vec2 texCord;

out vec2 tex_cord;

uniform mat4 trans;

void main()
{
	gl_Position = trans * vec4(vpos, 1.0f);
	tex_cord = texCord;
}