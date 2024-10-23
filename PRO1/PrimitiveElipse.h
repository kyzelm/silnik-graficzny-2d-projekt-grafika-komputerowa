#pragma once

#include "DrawableObject.h"

class PrimitiveElipse : public DrawableObject
{
private:
	Point2D center = Point2D(0, 0);
	Point2D radius = Point2D(0, 0);

protected:
	void drawFunction() override;

public:
	PrimitiveElipse(Engine* engine, Point2D center, Point2D radius, int thickness, Color color);
};
