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
	this->fillColor = Color::Yellow;
}
