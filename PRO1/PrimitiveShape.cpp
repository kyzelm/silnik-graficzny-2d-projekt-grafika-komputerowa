#include "PrimitiveShape.h"
#include <vector>

//void PrimitiveShape::drawFunction()
//{
//	int left, right, up, down;
//	left = right = points[0].getX();
//	up = down = points[0].getY();
//
//	for (int i = 1; i < points.size(); i++)
//	{
//		if (points[i].getX() < left)
//			left = points[i].getX();
//		if (points[i].getX() > right)
//			right = points[i].getX();
//		if (points[i].getY() < up)
//			up = points[i].getY();
//		if (points[i].getY() > down)
//			down = points[i].getY();
//	}
//
//	this->objectImage.create(right - left + this->thickness, down - up + this->thickness, Color::Transparent);
//
//	for (int i = 0; i < points.size() - 1; i++)
//	{
//		this->drawLine(this->points[i], this->points[i + 1], this->thickness, this->color, Point2D(left, up));
//	}
//
//	if (this->isClosed)
//	{
//		this->drawLine(this->points[points.size() - 1], this->points[0], this->thickness, this->color, Point2D(left, up));
//	}
//
//	this->spriteX = left - this->thickness / 2 + this->xModerator;
//	this->spriteY = up - this->thickness / 2 + this->yModerator;
//}

PrimitiveShape::PrimitiveShape(Engine* engine, vector<Point2D> points, bool isClosed, int thickness, Color color) : DrawableObject(engine)
{
	this->points = points;
	this->isClosed = isClosed;
	this->color = color;
}
