#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "camera.h"


GLFWwindow* window;
Camera* cam;
float last_x, last_y;
int scr_w, scr_h;
float delta_time, last_frame;
bool all_good;



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	float x = (float)xpos;
	float y = (float)ypos;
	cam->handle_mouse_event(x - last_x, y - last_y);
	last_x = x;
	last_y = y;
}


void process_input()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cam->handle_keyboard_event(FORWARD, delta_time);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cam->handle_keyboard_event(BACKWARD, delta_time);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cam->handle_keyboard_event(LEFT, delta_time);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cam->handle_keyboard_event(RIGHT, delta_time);
	}
}


void init_app(int w, int h, const char* title)
{
	scr_w = w;
	scr_h = h;
	delta_time = 0.0f;
	last_frame = 0.0f;
	cam = new Camera(0.0f, 0.0f, 5.0f);
	last_x = scr_w / 2.0;
	last_y = scr_h / 2.0;
	all_good = false;

	if (!glfwInit())
	{
		std::cout << "could not initialize glfw" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(scr_w, scr_h, title, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "could not open window" << std::endl;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error" << std::endl;
	}

	std::cout << "opengl version: " << glGetString(GL_VERSION) << std::endl;


	glViewport(0, 0, scr_w, scr_h);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	all_good = true;
}


void close_app()
{
	delete cam;
	glfwTerminate();
}
