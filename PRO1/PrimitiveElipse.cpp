#include "PrimitiveElipse.h"

#define PI 3.14159265358979323846

//void PrimitiveElipse::drawFunction()
//{
//	this->objectImage.create(radius.getX() * 2 + this->thickness, radius.getY() * 2 + this->thickness, Color::Transparent);
//
//	float step;
//	int x, y;
//
//
//	step = 1 / (float)max(radius.getX(), radius.getY());
//
//	for (float a = 0; a < 2 * PI; a += step)
//	{
//		x = radius.getX() + this->thickness / 2 + (radius.getX() * cos(a)) + 0.5;
//		y = radius.getY() + this->thickness / 2 + (radius.getY() * sin(a)) + 0.5;
//
//		for (int i = 0; i < this->thickness; i++)
//		{
//			for (int j = 0; j < this->thickness; j++)
//			{
//				if ((x + ((int)(i / 2) + 0.5) * pow(-1, i)) >= 0 && (x + ((int)(i / 2) + 0.5) * pow(-1, i)) < this->objectImage.getSize().x && (y + ((int)(j / 2) + 0.5) * pow(-1, j)) >= 0 && (y + ((int)(j / 2) + 0.5) * pow(-1, j)) < this->objectImage.getSize().y)
//				{
//					this->objectImage.setPixel((x + ((int)(i / 2) + 0.5) * pow(-1, i)), (y + ((int)(j / 2) + 0.5) * pow(-1, j)), this->color);
//				}
//			}
//		}
//	}
//
//	this->spriteX = this->center.getX() - this->objectImage.getSize().x / 2 + this->xModerator;
//	this->spriteY = this->center.getY() - this->objectImage.getSize().y / 2 + this->yModerator;
//}

PrimitiveElipse::PrimitiveElipse(Engine* engine, Point2D center, Point2D radius, int thickness, Color color) : DrawableObject(engine)
{
	this->center.setPoint(center);
	this->radius.setPoint(radius);
	this->color = color;
	this->thickness = thickness;

	this->update();
}

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
}
