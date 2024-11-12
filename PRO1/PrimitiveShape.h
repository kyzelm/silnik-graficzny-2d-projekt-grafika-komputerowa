#pragma once

#include "DrawableObject.h"
#include <vector>

using namespace std;

class PrimitiveShape : public DrawableObject
{
private:
	vector<Point2D> points;
	bool isClosed;

public:
	PrimitiveShape(Engine* engine, vector<Point2D> points, bool isClosed, int thickness, Color color);
	void update() override;
};

