#include "PrimitiveLine.h"
#include <iostream>

PrimitiveLine::PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color) : DrawableObject(engine)
{
	this->color = color;
	this->thickness = thickness;
	this->start = start;
	this->end = end;
	this->center = Point2D((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2);

	this->update();
}

void PrimitiveLine::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4);
	this->drawLine(this->start, this->end, this->thickness, this->color);
	this->texture.update(this->matrix.data());
}