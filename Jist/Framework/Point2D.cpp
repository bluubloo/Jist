#include "Point2D.h"


//x and y should be given as percentage of screen size in values form 0.0 to 100.0
Point2D::Point2D(float x, float y)
{
	Point2D::x = x;
	Point2D::y = y;
}


Point2D::~Point2D()
{

}

//Returns X as a screen coordinate
float Point2D::GetX()
{
	return x;
}

//Returns Y as a screen coordinate
float Point2D::GetY()
{
	return y;
}

//Returns x as an openGL screen coordinate
float Point2D::GLGetX()
{
	return x / 50 - 1;
}
//Returns y as a openGl screen coordinate
float Point2D::GLGetY()
{
	return -1 * (y / 50 - 1);
}

void Point2D::Print()
{
	std::cout << "Point X: " << x << " Y: " << y;
}

