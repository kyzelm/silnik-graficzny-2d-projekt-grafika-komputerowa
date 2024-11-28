#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

class AnimationHandler : public DrawableObject
{
private:
	map<string, vector<Uint8>> framesMap;
	string currentFrameSet;

	int imageWidth;
	int imageHeight;
	int spriteSheetWidth;

	int frameNumber = 0;
	int frameCount;
	int frameCounter = 0;

public:
	AnimationHandler(Engine* engine, map<string, string> framesPaths, Point2D dimensions, Point2D start, int frameCount);
	void update();

	void step();
	void setFrameSet(string name);
};

