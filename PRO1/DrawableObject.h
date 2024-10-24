#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Point2D.h"

using namespace sf;

class DrawableObject
{
protected:
	Engine* engine;

	Image objectImage;
	int spriteX = 0;
	int spriteY = 0;

	int thickness = 0;
	Color color = Color::Black;

	float xModerator = 0;
	float yModerator = 0;

	virtual void drawFunction();

	void drawLine(Point2D start, Point2D end, int thickess, Color color, Point2D relativeValue);

public:
	DrawableObject(Engine* engine);
	void drawImage();
	void move(Point2D vector);
};

