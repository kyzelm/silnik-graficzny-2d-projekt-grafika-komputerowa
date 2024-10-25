#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Point2D.h"

using namespace sf;

enum ObjectFillType
{
	NoFill,
	Fill,
	Border
};

class DrawableObject
{
protected:
	Engine* engine;

	Image objectImage;

	Color color = Color::Black;
	Color fillColor = Color::Transparent;

	int matrixWidth;
	int matrixHeight;
	ObjectFillType** imageMatrix = nullptr;

	float transformationMatrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	void drawLine(Point2D start, Point2D end, int thickess, Color color, Point2D relativeValue);

public:
	DrawableObject(Engine* engine);
	void drawImage();
	void fill(Color color);
	void move(Point2D vector);
};

