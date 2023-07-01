#pragma once
#include "object.h"
#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void draw_landscape(Object& cube, const char* trans, Shader& prog, glm::mat4 pv)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			glm::mat4 cube_model1(1.0f);
			cube_model1 = glm::translate(cube_model1, glm::vec3(i, 0, j));
			cube_model1 = glm::scale(cube_model1, glm::vec3(0.5, 0.5, 0.5));

			prog.setMat4(trans, pv * cube_model1);

			Object::draw(cube);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		glm::mat4 cube_model1(1.0f);
		cube_model1 = glm::translate(cube_model1, glm::vec3(4, 1, i + 1));
		cube_model1 = glm::scale(cube_model1, glm::vec3(0.5, 0.5, 0.5));

		prog.setMat4("trans", pv * cube_model1);

		Object::draw(cube);
	}

	for (int i = 0; i < 3; i++)
	{
		glm::mat4 cube_model1(1.0f);
		cube_model1 = glm::translate(cube_model1, glm::vec3(i + 1, 1, 4));
		cube_model1 = glm::scale(cube_model1, glm::vec3(0.5, 0.5, 0.5));

		prog.setMat4("trans", pv * cube_model1);

		Object::draw(cube);
	}

	for (int i = 0; i < 2; i++)
	{
		glm::mat4 cube_model1(1.0f);
		cube_model1 = glm::translate(cube_model1, glm::vec3(4, i + 1, 4));
		cube_model1 = glm::scale(cube_model1, glm::vec3(0.5, 0.5, 0.5));

		prog.setMat4("trans", pv * cube_model1);

		Object::draw(cube);
	}
}

void draw_landscape2(Object& cube, const char* trans, Shader& prog, glm::mat4 pv)
{
	glm::mat4 cube_model1(1.0f);
	cube_model1 = glm::scale(cube_model1, glm::vec3(0.5f, 0.5f, 0.5f));
	prog.setMat4(trans, pv * cube_model1);
	Object::draw(cube);
}