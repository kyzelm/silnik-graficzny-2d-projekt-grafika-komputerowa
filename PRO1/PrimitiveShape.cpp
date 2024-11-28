/*****************************************************************//**
 * \file   PrimitiveShape.h
 * \brief  Class that represents a primitive shape.
 *********************************************************************/
#include "PrimitiveShape.h"
#include <vector>

/**
 * \brief Construct a new Primitive Shape object
 * 
 * Constructor of the PrimitiveShape class based on a list of points, a boolean that indicates if the shape is closed, a thickness and a color.
 * 
 * \param engine - Engine where the object will be drawn.
 * \param points - List of points that define the shape.
 * \param isClosed - Boolean that indicates if the shape is closed.
 * \param thickness - Thickness of the shape.
 * \param color - Color of the shape.
 */
PrimitiveShape::PrimitiveShape(Engine* engine, vector<Point2D> points, bool isClosed, int thickness, Color color) : DrawableObject(engine)
{
	this->points = points;
	this->isClosed = isClosed;
	this->color = color;
	this->thickness = thickness;

	int xCenter = 0;
	int yCenter = 0;

	for (int i = 0; i < points.size(); i++)
	{
		xCenter += points[i].getX();
		yCenter += points[i].getY();
	}

	this->center = Point2D(xCenter / points.size(), yCenter / points.size());

	this->update();
}

/**
 * \brief Update the shape output matrix.
 * 
 * Function that updates the output matrix of the shape based on the points, thickness, color and fill color.
 */
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

	if (this->fillColor != Color::Transparent && this->isClosed)
	{
		int x = this->center.getX() * this->transformationMatrix[0][0] + this->center.getY() * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
		int y = this->center.getX() * this->transformationMatrix[1][0] + this->center.getY() * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

		this->fillAlgorithm(x, y);
	}
	this->texture.update(this->matrix.data());
}
