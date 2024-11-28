#include "DrawableObject.h"
#include <iostream>
#include <stack>

using namespace std;

void DrawableObject::drawLine(Point2D start, Point2D end, int thickess, Color color)
{
	int startX = start.getX() * this->transformationMatrix[0][0] + start.getY() * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
	int startY = start.getX() * this->transformationMatrix[1][0] + start.getY() * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

	int endX = end.getX() * this->transformationMatrix[0][0] + end.getY() * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
	int endY = end.getX() * this->transformationMatrix[1][0] + end.getY() * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

	int dx = endX - startX;
	int dy = endY - startY;

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
					a += (startX < endX ? startX : endX);
					b += (startY < endY ? startY : endY);

					unsigned int index = a * 4 + b * this->matrixWidth * 4;

					if (a >= 0 && a < this->matrixWidth && b >= 0 && b < this->matrixHeight && index >= 0 && index < this->matrix.size())
					{

						this->matrix[index] = color.r;
						this->matrix[index + 1] = color.g;
						this->matrix[index + 2] = color.b;
						this->matrix[index + 3] = color.a;
					}
				}
				else {
					a += (startY < endY ? startY : endY);
					b += (startX < endX ? startX : endX);

					unsigned int index = b * 4 + a * this->matrixWidth * 4;

					if (b >= 0 && b < this->matrixWidth && a >= 0 && a < this->matrixHeight && index >= 0 && index < this->matrix.size())
					{
						this->matrix[index] = color.r;
						this->matrix[index + 1] = color.g;
						this->matrix[index + 2] = color.b;
						this->matrix[index + 3] = color.a;
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

void DrawableObject::multiplyMatrix(float matrix[3][3])
{
	float result[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				result[i][j] += this->transformationMatrix[i][k] * matrix[k][j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->transformationMatrix[i][j] = result[i][j];
		}
	}
}

void DrawableObject::fillAlgorithm(int x, int y)
{
	stack<pair<int, int>> stack;

	stack.push(make_pair(x, y));

	while (!stack.empty())
	{
		pair<int, int> point = stack.top();
		stack.pop();

		int x = point.first;
		int y = point.second;

		if (x >= 0 && x < this->matrixWidth && y >= 0 && y < this->matrixHeight)
		{
			unsigned int index = x * 4 + y * this->matrixWidth * 4;

			if (this->matrix[index + 3] == 0)
			{
				this->matrix[index] = this->fillColor.r;
				this->matrix[index + 1] = this->fillColor.g;
				this->matrix[index + 2] = this->fillColor.b;
				this->matrix[index + 3] = this->fillColor.a;

				stack.push(make_pair(x + 1, y));
				stack.push(make_pair(x - 1, y));
				stack.push(make_pair(x, y + 1));
				stack.push(make_pair(x, y - 1));
			}
		}
	}
}

DrawableObject::DrawableObject(Engine* engine)
{
	this->engine = engine;
	this->matrixWidth = engine->getMatrixWidth();
	this->matrixHeight = engine->getMatrixHeight();
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4, 0);
	this->texture.create(this->matrixWidth, this->matrixHeight);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(0, 0);
}

void DrawableObject::update()
{
	cout << "Error: update function is not set." << endl;
}

void DrawableObject::draw()
{
	this->engine->window.draw(this->sprite);
}

void DrawableObject::fill(Color color)
{
	this->fillColor = color;
	this->update();
}

void DrawableObject::move(Point2D vector)
{
	this->multiplyMatrix(new float[3][3]{ {1, 0, (float)vector.getX()}, {0, 1, (float)vector.getY()}, {0, 0, 1} });
	this->update();
}

void DrawableObject::rotate(float angle)
{
	if (this->isTransformable == false) return;

	float radian = angle * 3.14159265359 / 180;
	this->multiplyMatrix(new float[3][3]{ {1, 0, (float)this->center.getX()}, {0, 1, (float)this->center.getY()}, {0, 0, 1} });
	this->multiplyMatrix(new float[3][3]{ {cos(radian), -sin(radian), 0}, {sin(radian), cos(radian), 0}, {0, 0, 1} });
	this->multiplyMatrix(new float[3][3]{ {1, 0, (float)-this->center.getX()}, {0, 1, (float)-this->center.getY()}, {0, 0, 1} });
	this->update();
}

void DrawableObject::scale(float factor)
{
	if (this->isTransformable == false) return;

	this->multiplyMatrix(new float[3][3]{ {1, 0, (float)this->center.getX()}, {0, 1, (float)this->center.getY()}, {0, 0, 1} });
	this->multiplyMatrix(new float[3][3]{ {factor, 0, 0}, {0, factor, 0}, {0, 0, 1} });
	this->multiplyMatrix(new float[3][3]{ {1, 0, (float)-this->center.getX()}, {0, 1, (float)-this->center.getY()}, {0, 0, 1} });
	this->update();
}

void DrawableObject::leanX(float factor)
{
	this->multiplyMatrix(new float[3][3]{ {1, factor, 0}, {0, 1, 0}, {0, 0, 1} });
	this->update();
}

void DrawableObject::leanY(float factor)
{
	this->multiplyMatrix(new float[3][3]{ {1, 0, 0}, {factor, 1, 0}, {0, 0, 1} });
	this->update();
}
