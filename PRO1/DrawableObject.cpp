#include "DrawableObject.h"
#include <iostream>
#include <stack>

using namespace std;

void DrawableObject::drawLine(Point2D start, Point2D end, int thickess, Color color, Point2D relativeValue)
{
	int dx = end.getX() - start.getX();
	int dy = end.getY() - start.getY();

	int absDx = abs(dx);
	int absDy = abs(dy);

	float m = (float)absDy / (float)absDx;

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

					if (a >= 0 && a < this->objectImage.getSize().x && b >= 0 && b < this->objectImage.getSize().y)
					{
						this->imageMatrix[a][b] = Border;
					}
				}
				else {
					a += (start.getY() < end.getY() ? start.getY() : end.getY()) - relativeValue.getY();
					b += (start.getX() < end.getX() ? start.getX() : end.getX()) - relativeValue.getX();

					if (b >= 0 && b < this->objectImage.getSize().x && a >= 0 && a < this->objectImage.getSize().y)
					{
						this->imageMatrix[b][a] = Border;
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

	this->matrixWidth = engine->getWindowWidth();
	this->matrixHeight = engine->getWindowHeight();
	this->imageMatrix = new ObjectFillType * [this->matrixWidth];
	for (int i = 0; i < this->matrixWidth; ++i) {
		this->imageMatrix[i] = new ObjectFillType[this->matrixHeight];
	}

	this->objectImage.create(this->matrixWidth, this->matrixHeight, Color::Transparent);
}

void DrawableObject::drawImage()
{

	for (int i = 0; i < this->matrixWidth; i++)
	{
		for (int j = 0; j < this->matrixHeight; j++)
		{
			int x = this->transformationMatrix[0][0] * i + this->transformationMatrix[0][1] * j + this->transformationMatrix[0][2];
			int y = this->transformationMatrix[1][0] * i + this->transformationMatrix[1][1] * j + this->transformationMatrix[1][2];

			if (x >= 0 && x < this->objectImage.getSize().x && y >= 0 && y < this->objectImage.getSize().y) {
				if (this->imageMatrix[i][j] == Fill || this->fillColor != Color::Transparent)
				{
					this->objectImage.setPixel(x, y, this->fillColor);
				}
				else if (this->imageMatrix[i][j] == Border)
				{
					this->objectImage.setPixel(x, y, this->color);
				}
			}
		}
	}

	Texture texture;
	texture.loadFromImage(this->objectImage);

	Sprite sprite(texture);
	sprite.setPosition(0, 0);

	this->engine->draw(sprite);
}

void DrawableObject::fill(Color color)
{
	this->fillColor = color;
}

void DrawableObject::move(Point2D vector)
{
	this->transformationMatrix[0][2] += vector.getX();
	this->transformationMatrix[1][2] += vector.getY();
}
