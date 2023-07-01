#include "shader.h"


Shader::Shader(const char* vrtx_shdr_path, const char* frag_shdr_path) 
{
	_id = glCreateProgram();
	compile_shader(GL_VERTEX_SHADER, vrtx_shdr_path);
	compile_shader(GL_FRAGMENT_SHADER, frag_shdr_path);
	link_shader();
}


std::string Shader::parse_shader(const char* src_path)
{
	std::fstream src_file(src_path);
	std::string s;
	std::stringstream src;
	while (std::getline(src_file, s))
	{ src << s << '\n'; }
	return src.str();
}


void Shader::compile_shader(unsigned int type, const char* src_path)
{
	unsigned int shdr = glCreateShader(type);
	std::string s = parse_shader(src_path);
	const char* src = s.c_str();
	//const char* src = parse_shader(src_path).c_str();
	glShaderSource(shdr, 1, &src, NULL);
	glCompileShader(shdr);

	int success;
	char info_log[512];
	glGetShaderiv(shdr, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shdr, 512, NULL, info_log);
		if (type == GL_VERTEX_SHADER) 
		{ std::cout << "vertex shader error: " << info_log << std::endl; }
		else 
		{ std::cout << "fragment shader error: " << info_log << std::endl; }
	}

	glAttachShader(_id, shdr);
	glDeleteShader(shdr);
}


void Shader::link_shader()
{
	glLinkProgram(_id);
	int success;
	char info_log[512];
	glGetProgramiv(_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(_id, 512, NULL, info_log); 
		std::cout << info_log << std::endl;
	}
	glValidateProgram(_id);
	glGetProgramiv(_id, GL_VALIDATE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(_id, 512, NULL, info_log);
		std::cout << info_log << std::endl;
	}
}


void Shader::setMat4(const char* name, glm::mat4 mtrx)
{
	glUniformMatrix4fv(getUniformLoc(name), 1, GL_FALSE, glm::value_ptr(mtrx));
}


int Shader::getUniformLoc(const char* name)
{
	if (unif_locs.find(name) != unif_locs.end()) { return unif_locs[name]; }
	int loc = glGetUniformLocation(_id, name);
	if (loc == -1) { std::cout << "uniform '" << name << "' does not exist" << std::endl; }
	unif_locs[name] = loc;
	return loc;
}


void Shader::bind() { glUseProgram(_id); }

void Shader::unbind() { glUseProgram(0); }

Shader::~Shader() { glDeleteProgram(_id); }
