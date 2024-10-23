#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Point2D
{
private:
	float x, y;

public:
	Point2D(float x, float y);
	void setPoint(float x, float y);
	void setPoint(Point2D point);
	float getX();
	float getY();
};