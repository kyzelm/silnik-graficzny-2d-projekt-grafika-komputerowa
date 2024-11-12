#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

class PrimitiveLine : public DrawableObject
{
private:
	Point2D start = Point2D(0, 0);
	Point2D end = Point2D(0, 0);

public:
	PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color);
	void update() override;
};