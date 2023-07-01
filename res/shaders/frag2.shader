#version 330 core

in vec2 tex_cord;
//in int gl_PrimitiveID;

out vec4 FragColor;

uniform sampler2D our_tex;


void main()
{
	//if (gl_PrimitiveID < 4)
	//{ FragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f); }
	//else if (gl_PrimitiveID < 8)
	//{ FragColor = vec4(0.0f, 0.5f, 0.0f, 1.0f); }
	//else
	//{ FragColor = vec4(0.0f, 0.0f, 0.5f, 1.0f); }
	FragColor = texture(our_tex, tex_cord);
	//FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}