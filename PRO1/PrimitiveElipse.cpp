/*****************************************************************//**
 * \file   PrimitiveElipse.cpp
 * \brief  Class that handles the primitive elipse
 *********************************************************************/
#include "PrimitiveElipse.h"

#define PI 3.14159265358979323846

/**
 * \brief Construct a new Primitive Elipse
 * 
 * Constructor of the Primitive Elipse object based on center and radius.
 * 
 * \param engine - pointer to the engine
 * \param center - center of the elipse
 * \param radius - radius of the elipse
 * \param thickness - thickness of the elipse
 * \param color - color of the elipse
 */
PrimitiveElipse::PrimitiveElipse(Engine* engine, Point2D center, Point2D radius, int thickness, Color color) : DrawableObject(engine)
{
	this->center.setPoint(center);
	this->radius.setPoint(radius);
	this->color = color;
	this->thickness = thickness;

	this->update();
}

/**
 * \brief Update the elipse output matrix
 * 
 * Update the elipse matrix based on the transformation matrix.
 */
void PrimitiveElipse::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4);

	float step;
	int x, y;

	step = 1 / (float)max(radius.getX(), radius.getY());

	for (float a = 0; a < 2 * PI; a += step)
	{
		x = this->thickness / 2 + (radius.getX() * cos(a)) + 0.5 + this->center.getX();
		y = this->thickness / 2 + (radius.getY() * sin(a)) + 0.5 + this->center.getY();

		x = x * this->transformationMatrix[0][0] + y * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
		y = x * this->transformationMatrix[1][0] + y * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

		for (int i = 0; i < this->thickness; i++)
		{
			for (int j = 0; j < this->thickness; j++)
			{
				int xPoint = x + ((int)(i / 2) + 0.5) * pow(-1, i);
				int yPoint = y + ((int)(j / 2) + 0.5) * pow(-1, j);

				if (xPoint >= 0 && xPoint < this->matrixWidth && yPoint >= 0 && yPoint < this->matrixHeight)
				{
					this->matrix[(xPoint + yPoint * this->matrixWidth) * 4] = this->color.r;
					this->matrix[(xPoint + yPoint * this->matrixWidth) * 4 + 1] = this->color.g;
					this->matrix[(xPoint + yPoint * this->matrixWidth) * 4 + 2] = this->color.b;
					this->matrix[(xPoint + yPoint * this->matrixWidth) * 4 + 3] = this->color.a;
				}
			}
		}
	}

	if (this->fillColor != Color::Transparent)
	{
		int x = this->center.getX() * this->transformationMatrix[0][0] + this->center.getY() * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
		int y = this->center.getX() * this->transformationMatrix[1][0] + this->center.getY() * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

		this->fillAlgorithm(x, y);
	}
	this->texture.update(this->matrix.data());
}
