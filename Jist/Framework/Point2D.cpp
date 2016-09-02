#include "Point2D.h"



Point2D::Point2D(float x, float y)
{
	Point2D::x = x;
	Point2D::y = y;
}


Point2D::~Point2D()
{

}

GLfloat* Point2D::GetFloats()
{
	GLfloat points[] = { x, y, 0.0f };
	return points;
}
