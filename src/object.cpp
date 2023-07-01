#include "object.h"

#include <iostream>


Object::Object()
{
	glGenVertexArrays(1, &_vao);
}

void Object::destroy()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_ebo);
	for (auto& vb : _vbo)
	{ glDeleteBuffers(1, &vb.second); }
}

void Object::set_vertex_bufferf(const void* vert_data, unsigned int v_size, const char* name)
{
	glBindVertexArray(_vao);
	unsigned int vb;
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, v_size, vert_data, GL_STATIC_DRAW);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	_vbo[name] = vb;
}

void Object::set_indices(const void* idx_data, unsigned int i_size)
{
	glBindVertexArray(_vao);
	glGenBuffers(1, &_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, i_size, idx_data, GL_STATIC_DRAW);
	_count = i_size / sizeof(unsigned int);
	has_index = true;
}

void Object::set_vertex_layoutf(int index, int size, int stride, int offset, const char* name)
{
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo[name]);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
	glEnableVertexAttribArray(index);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::bind()
{
	glBindVertexArray(_vao);
}

void Object::unbind()
{
	glBindVertexArray(0);
}

void Object::draw(Object& obj)
{
	obj.bind();
	glDrawElements(GL_TRIANGLES, obj._count, GL_UNSIGNED_INT, 0);
}




//			// define position of objects in world space
//			cube_model1 = glm::translate(cube_model1, glm::vec3((float)i * 0.35, (float)j * 0.35, (float)k * 0.35));
//			//cube_model1 = glm::rotate(cube_model1, glm::radians(15.0f), glm::vec3(1.0f, 1.0f, 0.0f));
//			cube_model1 = glm::scale(cube_model1, glm::vec3(0.5f, 0.5f, 0.5f));
