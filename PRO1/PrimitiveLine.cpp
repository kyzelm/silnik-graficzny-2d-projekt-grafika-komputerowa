/*****************************************************************//**
 * \file   PrimitiveLine.cpp
 * \brief  Class that represents a line primitive object.
 *********************************************************************/
#include "PrimitiveLine.h"
#include <iostream>

/**
 * \brief Construct a new Primitive Line object
 * 
 * Constructor of the PrimitiveLine class based on the start and end points, thickness and color.
 * 
 * \param engine - Engine object
 * \param start - Start point
 * \param end - End point
 * \param thickness - Thickness of the line
 * \param color - Color of the line
 */
PrimitiveLine::PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color) : DrawableObject(engine)
{
	this->color = color;
	this->thickness = thickness;
	this->start = start;
	this->end = end;
	this->center = Point2D((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2);

	this->update();
}

/**
 * \brief Update the line output matrix
 * 
 * Function that updates the line output matrix based on the start and end points, thickness and color.
 */
void PrimitiveLine::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4);
	this->drawLine(this->start, this->end, this->thickness, this->color);
	this->texture.update(this->matrix.data());
}