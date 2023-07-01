#include "camera.h"
#include <iostream>

Camera::Camera(float x, float y, float z)
	: cam_pos(glm::vec3(x, y, z))
{
	update_cam_vec();
}

Camera::~Camera()
{
}

void Camera::handle_keyboard_event(int mov, float dt)
{

	float dist = mov_speed * dt;

	// for movement locked in x-z plane
	//glm::vec3 dir_xz = glm::normalize(glm::vec3(cam_dir.x, 0.0f, cam_dir.z));
	//if		(mov == FORWARD)
	//{ cam_pos -= dir_xz * dist; }
	//else if (mov == BACKWARD)
	//{ cam_pos += dir_xz * dist; }
	
	// for fly movement
	if		(mov == FORWARD)
	{ cam_pos -= cam_dir * dist; }
	else if (mov == BACKWARD)
	{ cam_pos += cam_dir * dist; }

	else if (mov == LEFT)
	{ cam_pos += cam_right * dist; }
	else if (mov == RIGHT)
	{ cam_pos -= cam_right * dist; }
}

void Camera::handle_mouse_event(float x_offset, float y_offset)
{
	if (pitch > 450) { pitch -= 360; }
	if (pitch < -90) { pitch += 360; }
	pitch -= y_offset * mouse_sens;

	if (yaw > 450) { yaw -= 360; }
	if (yaw < -90) { yaw += 360; }
	yaw += x_offset * mouse_sens;

	update_cam_vec();
}

void Camera::update_cam_vec()
{
	glm::vec3 dir;
	dir.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
	dir.y = glm::sin(glm::radians(pitch));
	dir.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
	cam_dir = glm::normalize(dir);
	cam_right = glm::normalize(glm::cross(cam_dir, world_up));
	cam_up = glm::cross(cam_right, cam_dir);
}


// moving cam according to cam coordiantes after translation
glm::mat4 Camera::get_cam_mat()
{
	return glm::lookAt(cam_pos, cam_pos + cam_dir, cam_up);
}
