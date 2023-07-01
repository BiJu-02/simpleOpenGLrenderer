#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

class Shader
{
public:
	unsigned int _id;
	std::unordered_map<std::string, int> unif_locs;

	//Shader(std::string& vrtx_src_path, std::string& frag_src_path);
	Shader(const char* vrtx_shdr_path, const char* frag_shdr_path);
	~Shader();

	std::string parse_shader(const char* src_path);
	//unsigned int compile_shader(unsigned int type, std::string& s);
	void compile_shader(unsigned int type, const char* src_path);
	void link_shader();

	void bind();
	void unbind();

	void setMat4(const char* name, glm::mat4 mtrx);
	int getUniformLoc(const char* name);
};