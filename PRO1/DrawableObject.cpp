#include "DrawableObject.h"
#include <iostream>

using namespace std;

void DrawableObject::drawFunction()
{
	cout << "This is a virtual function" << endl;
}

void DrawableObject::drawLine(Point2D start, Point2D end, int thickess, Color color, Point2D relativeValue)
{
	float dx = end.getX() - start.getX();
	float dy = end.getY() - start.getY();

	float absDx = abs(dx);
	float absDy = abs(dy);

	float m = absDy / absDx;

	float printer = thickess / 2;
	if ((dx < 0 && dy > 0) || (dx > 0 && dy < 0))
	{
		printer += m < 1 ? absDy : absDx;
	}

	int step = 0;
	int limit = m < 1 ? absDx : absDy;

	for (; step <= limit; step++) {
		for (int i = 0; i < thickess; i++)
		{
			for (int j = 0; j < thickess; j++)
			{
				int a = step + thickess / 2 + (int)(i / 2) * pow(-1, i);
				int b = printer + (int)(j / 2) * pow(-1, j);

				if (m < 1)
				{
					a += (start.getX() < end.getX() ? start.getX() : end.getX()) - relativeValue.getX();
					b += (start.getY() < end.getY() ? start.getY() : end.getY()) - relativeValue.getY();

					if (a >= 0 && a <= this->objectImage.getSize().x && b >= 0 && b <= this->objectImage.getSize().y)
					{
						this->objectImage.setPixel(a, b, color);
					}
				}
				else {
					a += (start.getY() < end.getY() ? start.getY() : end.getY()) - relativeValue.getY();
					b += (start.getX() < end.getX() ? start.getX() : end.getX()) - relativeValue.getX();

					if (a >= 0 && b < this->objectImage.getSize().x && a >= 0 && a < this->objectImage.getSize().y)
					{
						this->objectImage.setPixel(b, a, color);
					}
				}
			}
		}

		if ((dx < 0 && dy > 0) || (dx > 0 && dy < 0))
		{
			printer -= m < 1 ? m : 1 / m;
		}
		else
		{
			printer += m < 1 ? m : 1 / m;
		}
	}
}

DrawableObject::DrawableObject(Engine* engine)
{
	this->engine = engine;
	this->objectImage.create(1, 1, Color::Transparent);
}

void DrawableObject::drawImage()
{
	this->drawFunction();

	Texture texture;
	texture.loadFromImage(this->objectImage);

	Sprite sprite(texture);
	sprite.setPosition(this->spriteX, this->spriteY);
	
	this->engine->draw(sprite);
}

void DrawableObject::move(Point2D vector)
{
	this->xModerator += vector.getX();
	this->yModerator += vector.getY();
}
