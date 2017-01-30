#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <InputSystem.h>

class Input
{
public:
	Input(GLFWwindow* window);
	~Input();

	void CheckInput();

private:
	GLFWwindow* window;
};
