#pragma once

#include<SFML/Graphics.hpp>

using namespace sf;

class Point2D
{
private:
	float x, y;
	Color color;

public:
	Point2D(float x, float y);
	Point2D(float x, float y, Color color);
	void setPoint(float x, float y);
	void setPointColor(Color color);
	float getX();
	float getY();
	Image getPointImage();
};