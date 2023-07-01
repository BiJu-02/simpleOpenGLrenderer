#version 330 core

uniform vec4 app_colr;
out vec4 FragColor;

void main()
{
	FragColor = app_colr;
}