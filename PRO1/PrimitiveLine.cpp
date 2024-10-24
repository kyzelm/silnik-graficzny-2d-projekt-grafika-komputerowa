#include "PrimitiveLine.h"
#include <iostream>

using namespace std;

void PrimitiveLine::drawFunction()
{
	float dx = abs(end.getX() - start.getX()) + thickness;
	float dy = abs(end.getY() - start.getY()) + thickness;

	this->objectImage.create(dx, dy, Color::Transparent);
	this->drawLine(start, end, thickness, color, Point2D(0, 0));

	this->spriteX = (start.getX() < end.getX() ? start.getX() : end.getX()) - thickness / 2 + this->xModerator;
	this->spriteY = (start.getY() < end.getY() ? start.getY() : end.getY()) - thickness / 2 + this->yModerator;
}

PrimitiveLine::PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color) : DrawableObject(engine)
{
	this->start.setPoint(start);
	this->end.setPoint(end);
	this->thickness = thickness;
	this->color = color;
}
