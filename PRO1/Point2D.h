/*****************************************************************//**
 * \file   Point2D.h
 * \brief  Vector2D class
 *********************************************************************/
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * \class Point2D
 * \brief Class that represents 2D point
 * 
 * Class that represents 2D point with x and y coordinates.
 */
class Point2D
{
private:
	int x, y; ///< x and y coordinates

public:
	Point2D(int x, int y);
	void setPoint(int x, int y);
	void setPoint(Point2D point);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};