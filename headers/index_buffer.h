#pragma once

#include <GL/glew.h>

class IndexBuffer
{
public:
	unsigned int _id;
	unsigned int _count;

	IndexBuffer(const void *data, unsigned int count);
	~IndexBuffer();

	void bind();
	void unbind();

	inline unsigned int get_count();
};

