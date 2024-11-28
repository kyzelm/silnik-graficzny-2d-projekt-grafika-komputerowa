#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

class ImageHandler : public DrawableObject
{
private:
	vector<Uint8> baseMatrix;

	int imageWidth;
	int imageHeight;

public:
	ImageHandler(Engine *engine, string path, Point2D start);
	void update();
	void loadBaseMatrix(vector<Uint8> baseMatrix);
	vector<Uint8> getBaseMatrix();

};

