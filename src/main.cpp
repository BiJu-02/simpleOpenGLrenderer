
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "app.h"
#include "object.h"
#include "shader.h"
#include "camera.h"

#include "cube.h"
#include "minecraft_blocks.h"



int main()
{

	init_app(900, 900, "grafiks");
	if (!all_good)
	{
		std::cout << ";-;" << std::endl;
		return -1;
	}

	unsigned int tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int tex_w, tex_h, tex_nr_channels;
	unsigned char *tex_data = stbi_load("res/images/texture_sheet.png", &tex_w, &tex_h, &tex_nr_channels, 0);

	if (tex_data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_w, tex_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "could not load texture" << std::endl;
	}
	stbi_image_free(tex_data);

	// object class changes...
	// c: vert coordinates
	// t: tex coordinates
	Object cube;
	cube.set_indices((void*)indices2, sizeof(indices2));
	cube.set_vertex_bufferf((void*)vertices2, sizeof(vertices2), "buf1");
	cube.set_vertex_layoutf(0, 3, 5, 0, "buf1");		// x, y, z
	cube.set_vertex_layoutf(1, 2, 5, 3, "buf1");		// s, t

	const char* vs2 = "res/shaders/vrtx2.shader";
	const char* fs2 = "res/shaders/frag2.shader";

	Shader prog2(vs2, fs2);

	// magix really..!?
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)scr_w / (float)scr_h, 0.1f, 100.0f);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		float current_time = (float)glfwGetTime();
		delta_time = last_frame - current_time;
		last_frame = current_time;

		process_input();

		glClearColor(1.0, 1.0, 1.0, 0);
		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		prog2.bind();
		glBindTexture(GL_TEXTURE_2D, tex);

		/* transformation shiz */
		// define position and orientation of camera (move the world space)
		glm::mat4 view(1.0f);
		view = cam->get_cam_mat();

		draw_landscape2(cube, "trans", prog2, projection * view);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	cube.destroy();
	close_app();

	return 0;
}

