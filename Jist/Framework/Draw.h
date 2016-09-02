#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <InputSystem.h>
#include <Point2D.h>
#include <Shaders.h>

class Draw
{
public:
	Draw();
	~Draw();


	void Redraw();
	void CheckInput();

	void DrawButton(float x, float y, float width, float height, std::string text);
	void DrawString(float x, float y, float width, float height, std::string text);
	void DrawRectangle(float x, float y, float width, float height);
	void DrawEclipse(float centreX, float centreY, float width, float height);
	void DrawTriangle(Point2D a, Point2D b, Point2D c);

private:
	GLFWwindow* window;
};

