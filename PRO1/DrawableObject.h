#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Point2D.h"
#include <vector>

using namespace std;
using namespace sf;

class DrawableObject
{
protected:
	Engine* engine;
	int matrixWidth;
	int matrixHeight;


	int thickness = 1;
	Color color = Color::Black;
	Color fillColor = Color::Transparent;

	vector<Uint8> matrix;
	float transformationMatrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
	bool isTransformable = true;

	Texture texture;
	Sprite sprite;

	void drawLine(Point2D start, Point2D end, int thickess, Color color);
	void multiplyMatrix(float matrix[3][3]);
	void fillAlgorithm(int x, int y);

public:
	Point2D center = Point2D(0, 0);

	DrawableObject(Engine* engine);
	virtual void update();
	void draw();
	void fill(Color color);
	void move(Point2D vector);
	void rotate(float angle);
	void scale(float factor);
	void leanX(float factor);
	void leanY(float factor);
};