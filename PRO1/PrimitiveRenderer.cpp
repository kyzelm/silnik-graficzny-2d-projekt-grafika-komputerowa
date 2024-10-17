#include "PrimitiveRenderer.h"

#define PI 3.14159265358979323846

PrimitiveRenderer::PrimitiveRenderer(Engine* engine)
{
	this->engine = engine;
}

void PrimitiveRenderer::drawLine(Point2D start, Point2D end, int thickess, Color color)
{
	float dx = end.getX() - start.getX();
	float dy = end.getY() - start.getY();

	float absDx = abs(dx);
	float absDy = abs(dy);

	Image image;
	image.create(absDx + thickess, absDy + thickess, Color::Transparent);

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
					if (a >= 0 && a <= image.getSize().x && b >= 0 && b <= image.getSize().y)
					{
						image.setPixel(a, b, color);
					}
				}
				else {
					if (a >= 0 && b <= image.getSize().x && a >= 0 && a <= image.getSize().y)
					{
						image.setPixel(b, a, color);
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

	Texture texture;
	texture.loadFromImage(image);

	Sprite sprite(texture);
	sprite.setPosition(min(start.getX(), end.getX()), min(start.getY(), end.getY()));

	engine->draw(sprite);
}

void PrimitiveRenderer::drawElipse(Point2D center, Point2D radius, int thickess, Color color)
{
	Image image;
	image.create(radius.getX() * 2 + thickess, radius.getY() * 2 + thickess, Color::Transparent);

	float step;
	int x, y;

	step = 1 / max(radius.getX(), radius.getY());

	for (float a = 0; a < 2 * PI; a += step)
	{
		x = radius.getX() + thickess / 2 + (radius.getX() * cos(a)) + 0.5;
		y = radius.getY() + thickess / 2 + (radius.getY() * sin(a)) + 0.5;

		for (int i = 0; i < thickess; i++)
		{
			for (int j = 0; j < thickess; j++)
			{
				if ((x + ((int)(i / 2) + 0.5) * pow(-1, i)) >= 0 && (x + ((int)(i / 2) + 0.5) * pow(-1, i)) < image.getSize().x && (y + ((int)(j / 2) + 0.5) * pow(-1, j)) >= 0 && (y + ((int)(j / 2) + 0.5) * pow(-1, j)) < image.getSize().y)
				{
					image.setPixel((x + ((int)(i / 2) + 0.5) * pow(-1, i)), (y + ((int)(j / 2) + 0.5) * pow(-1, j)), color);
				}
			}
		}
	}

	Texture texture;
	texture.loadFromImage(image);

	Sprite sprite(texture);
	sprite.setPosition(center.getX() - radius.getX() - thickess / 2, center.getY() - radius.getY() - thickess / 2);

	engine->draw(sprite);
}