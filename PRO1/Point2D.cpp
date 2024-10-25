#include "Point2D.h"

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point2D::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point2D::setPoint(Point2D point)
{
	this->x = point.getX();
	this->y = point.getY();
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}
