/*****************************************************************//**
 * \file   AnimationHandler.h
 * \brief  Class that handles animations sheets
 *********************************************************************/
#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

/**
 * \class AnimationHandler
 * \brief Class that handles animations sheets
 * 
 * Class responsible for handling animations sheets and animating them. Based on DrawableObject.
 */
class AnimationHandler : public DrawableObject
{
private:
	map<string, vector<Uint8>> framesMap; /**< Map of frames with their names */
	string currentFrameSet; /**< Current frame set */

	int imageWidth; /**< Width of the image */
	int imageHeight; /**< Height of the image */
	int spriteSheetWidth; /**< Width of the sprite sheet */

	int frameNumber = 0; /**< Number of the current frame */
	int frameCount; /**< Number of frames for animation frame */
	int frameCounter = 0; /**< Counter of frames */

public:
	AnimationHandler(Engine* engine, map<string, string> framesPaths, Point2D dimensions, Point2D start, int frameCount);
	void update();

	void step();
	void setFrameSet(string name);
};

