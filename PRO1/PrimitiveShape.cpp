#include "PrimitiveShape.h"
#include <vector>

PrimitiveShape::PrimitiveShape(Engine* engine, vector<Point2D> points, bool isClosed, int thickness, Color color) : DrawableObject(engine)
{
	this->points = points;
	this->isClosed = isClosed;
	this->color = color;
	this->thickness = thickness;

	this->update();
}

void PrimitiveShape::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4);

	for (int i = 0; i < points.size() - 1; i++)
	{
		this->drawLine(this->points[i], this->points[i + 1], this->thickness, this->color);
	}

	if (this->isClosed)
	{
		this->drawLine(this->points[points.size() - 1], this->points[0], this->thickness, this->color);
	}
}
