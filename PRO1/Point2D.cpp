#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point2D::setPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point2D::setPoint(Point2D point)
{
	this->x = point.getX();
	this->y = point.getY();
}

float Point2D::getX()
{
	return x;
}

float Point2D::getY()
{
	return y;
}
