#pragma once
#include <GLFW/glfw3.h>

class Point2D
{
public:
	Point2D(float x, float y);
	~Point2D();

	GLfloat* GetFloats();

private:
	float x;
	float y;


};

