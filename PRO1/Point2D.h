#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Point2D
{
private:
	int x, y;

public:
	Point2D(int x, int y);
	void setPoint(int x, int y);
	void setPoint(Point2D point);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};