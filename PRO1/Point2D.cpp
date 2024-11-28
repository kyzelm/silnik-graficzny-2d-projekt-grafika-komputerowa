/*****************************************************************//**
 * \file   Point2D.cpp
 * \brief  Vector2D class
 *********************************************************************/
#include "Point2D.h"

/**
 * \brief Construct a new Point2D object
 * 
 * Construct a new Point2D object with given x and y.
 * 
 * \param x - x coordinate
 * \param y - y coordinate
 */
Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

/**
 * \brief Change point coordinates at once
 * 
 * Function that changes point coordinates at once method.
 * 
 * \param x - x coordinate
 * \param y - y coordinate
 */
void Point2D::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

/**
 * \brief Change point coordinates at once
 * 
 * Change point coordinates at once method by another point.
 * 
 * \param point - point to set
 */
void Point2D::setPoint(Point2D point)
{
	this->x = point.getX();
	this->y = point.getY();
}

/**
 * \brief Set x coordinate
 * 
 * Function that sets x coordinate of the point.
 * 
 * \param x - x coordinate
 */
void Point2D::setX(int x)
{
	this->x = x;
}

/**
 * \brief Set y coordinate
 *
 * Function that sets y coordinate of the point.
 *
 * \param y - y coordinate
 */
void Point2D::setY(int y)
{
	this->y = y;
}

/**
 * \brief Get x coordinate
 *
 * Function that returns x coordinate of the point.
 *
 * \return x coordinate
 */
int Point2D::getX()
{
	return x;
}

/**
 * \brief Get y coordinate
 *
 * Function that returns y coordinate of the point.
 *
 * \return y coordinate
 */
int Point2D::getY()
{
	return y;
}
