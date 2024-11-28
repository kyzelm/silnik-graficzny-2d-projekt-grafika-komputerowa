/*****************************************************************//**
 * \file   PrimitiveElipse.h
 * \brief  Class that handles the primitive elipse
 *********************************************************************/
#pragma once

#include "DrawableObject.h"

 /**
  * \class PimitiveElipse
  * \brief Class that handles the primitive elipse based DrawableObject
  */
class PrimitiveElipse : public DrawableObject
{
private:
	Point2D radius = Point2D(0, 0); /**< Radius of the elipse */

public:
	PrimitiveElipse(Engine* engine, Point2D center, Point2D radius, int thickness, Color color);
	void update() override;
};

