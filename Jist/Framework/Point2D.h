#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Point2D
{
public:
	Point2D(float x, float y);
	~Point2D();

	float GetX();
	float GetY();

	float GLGetX();
	float GLGetY();

	void Print();

private:
	float x;
	float y;


};

