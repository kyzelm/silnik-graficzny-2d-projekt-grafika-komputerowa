/*****************************************************************//**
 * \file   PrimitiveLine.h
 * \brief  Class that represents a line primitive object.
 *********************************************************************/
#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

/**
 * \class PrimitiveLine
 * \brief Class that represents a line primitive object.
 * 
 * Class that represents a line primitive object based on the DrawableObject class.
 */
class PrimitiveLine : public DrawableObject
{
private:
	Point2D start = Point2D(0, 0); /**< First point of the line. */
	Point2D end = Point2D(0, 0); /**< Second point of the line. */

public:
	PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color);
	void update() override;
};