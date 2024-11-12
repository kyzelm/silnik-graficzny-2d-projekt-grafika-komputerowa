#include "PrimitiveLine.h"
#include <iostream>

PrimitiveLine::PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color) : DrawableObject(engine)
{
	this->color = color;
	this->thickness = thickness;
	this->start = start;
	this->end = end;

	this->transformationMatrix[0][2] = (start.getX() < end.getX() ? start.getX() : end.getX()) - (int)(thickness / 2);
	this->transformationMatrix[1][2] = (start.getY() < end.getY() ? start.getY() : end.getY()) - (int)(thickness / 2);

	this->update();
}

void PrimitiveLine::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4);
	this->drawLine(this->start, this->end, this->thickness, this->color);
}