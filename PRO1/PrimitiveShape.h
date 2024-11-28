/*****************************************************************//**
 * \file   PrimitiveShape.h
 * \brief  Class that represents a primitive shape.
 *********************************************************************/
#pragma once

#include "DrawableObject.h"
#include <vector>

using namespace std;

/**
 * \class PrimitiveShape
 * \brief Class that represents a primitive shape.
 * 
 * Class that represents a primitive shape based on DrawableObject.
 */
class PrimitiveShape : public DrawableObject
{
private:
	vector<Point2D> points; /**< Vector of points that define the shape. */
	bool isClosed; /**< Is the shape closed. */

public:
	PrimitiveShape(Engine* engine, vector<Point2D> points, bool isClosed, int thickness, Color color);
	void update() override;
};

