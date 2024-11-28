/*****************************************************************//**
 * \file   DrawableObject.h
 * \brief  Main class for drawable objects
 *********************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Point2D.h"
#include <vector>

using namespace std;
using namespace sf;

/**
 * \class DrawableObject
 * \brief Main class for drawable objects
 * 
 * Class is responsible for drawing objects on the screen, moving them, rotating, scaling, leaning and filling them with color. Caontains all the necessary methods for these operations and line drawind method.
 */
class DrawableObject
{
protected:
	Engine* engine; /**< Pointer to the main engine */
	int matrixWidth; /**< Width of the main matrix */
	int matrixHeight; /**< Height of the main matrix */


	int thickness = 1; /**< Thickness of border */
	Color color = Color::Black; /**< Color of border */
	Color fillColor = Color::Transparent; /**< Color of fill */

	vector<Uint8> matrix; /**< Object matrix */
	float transformationMatrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }; /**< Transformation matrix */
	bool isTransformable = true; /**< Is object transformable */

	Texture texture; /**< Texture of the object */
	Sprite sprite; /**< Sprite of the object */

	void drawLine(Point2D start, Point2D end, int thickess, Color color);
	void multiplyMatrix(float matrix[3][3]);
	void fillAlgorithm(int x, int y);

public:
	Point2D center = Point2D(0, 0); /**< Center of the object */

	DrawableObject(Engine* engine);
	virtual void update();
	void draw();
	void fill(Color color);
	void move(Point2D vector);
	void rotate(float angle);
	void scale(float factor);
};