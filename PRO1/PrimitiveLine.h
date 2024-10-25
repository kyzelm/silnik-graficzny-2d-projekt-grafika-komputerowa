#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

class PrimitiveLine : public DrawableObject
{
public:
	PrimitiveLine(Engine* engine, Point2D start, Point2D end, int thickness, Color color);
};