#pragma once

#include "SFML/Graphics.hpp"
#include "Point2D.h"
#include "Engine.h"

using namespace sf;

class PrimitiveRenderer
{
private:
	Engine* engine;

public:
	PrimitiveRenderer(Engine* engine);

	void drawLine(Point2D start, Point2D end, int thickess, Color color);
	void drawElipse(Point2D center, Point2D radius, int thickess, Color color);
};

