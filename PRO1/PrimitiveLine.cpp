#include "PrimitiveLine.h"
#include <iostream>

using namespace std;

PrimitiveLine::PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color) : DrawableObject(engine)
{
	this->color = color;

	this->drawLine(start, end, thickness, color, Point2D(0, 0));

	this->transformationMatrix[0][2] = (start.getX() < end.getX() ? start.getX() : end.getX()) - (int)(thickness / 2);
	this->transformationMatrix[1][2] = (start.getY() < end.getY() ? start.getY() : end.getY()) - (int)(thickness / 2);
}
