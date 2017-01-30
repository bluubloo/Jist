#include "Input.h"

Input::Input(GLFWwindow* window)
{
	Input::window = window;
}

Input::~Input()
{

}

void Input::CheckInput()
{
	if (glfwWindowShouldClose(window))
	{
		glfwTerminate();
		InputSystem().CloseWindow();
		return;
	}
	glfwPollEvents();
}