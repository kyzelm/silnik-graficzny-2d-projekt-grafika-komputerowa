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

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}
