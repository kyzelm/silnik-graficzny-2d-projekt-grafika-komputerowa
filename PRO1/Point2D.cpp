#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
	this->color = Color::Black;
}

Point2D::Point2D(float x, float y, Color color)
{
	this->x = x;
	this->y = y;
	this->color = color;
}

void Point2D::setPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point2D::setPointColor(Color color)
{
	this->color = color;
}

float Point2D::getX()
{
	return x;
}

float Point2D::getY()
{
	return y;
}

Image Point2D::getPointImage()
{
	Image pointImage;
	pointImage.create(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height, Color::Transparent);
	pointImage.setPixel(this->x, this->y, this->color);
	return pointImage;
}