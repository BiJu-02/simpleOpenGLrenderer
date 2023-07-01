#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum cam_mov
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera
{
private:
	glm::vec3 cam_pos;
	glm::vec3 cam_up;
	glm::vec3 cam_dir = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cam_right = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);

	float mov_speed = 2.5f;
	float mouse_sens = 0.05f;
	float pitch = 0.0f;
	float yaw = -90.0f;

public:
	Camera(float x, float y, float z);
	~Camera();

	void handle_keyboard_event(int mov, float dt);
	void handle_mouse_event(float x_offset, float y_offset);
	void update_cam_vec();
	glm::mat4 get_cam_mat();
};
