#include "index_buffer.h"

IndexBuffer::IndexBuffer(const void *data, unsigned int count)
: _count(count)
{
	glGenBuffers(1, &_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_id);
}

void IndexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void IndexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

inline unsigned int IndexBuffer::get_count()
{
	return _count;
}
