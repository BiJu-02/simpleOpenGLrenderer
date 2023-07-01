#pragma once

#include <GL/glew.h>
#include <unordered_map>

class Object
{
public:
	unsigned int _vao, _ebo, _count;
	std::unordered_map<std::string, unsigned int> _vbo;
	bool has_index = false;

	Object();
	void destroy();

	// for floating values in vert_data
	void set_vertex_bufferf(const void* vert_data, unsigned int v_size, const char* name);
	void set_indices(const void* idx_data, unsigned int i_size);
	void set_vertex_layoutf(int index, int size, int stride, int offset, const char* name);

	void bind();
	void unbind();
	static void draw(Object& obj);
};

