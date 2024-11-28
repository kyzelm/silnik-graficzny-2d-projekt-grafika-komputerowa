/*****************************************************************//**
 * \file   ImageHandler.h
 * \brief  Class that handles the image and its matrix
 *********************************************************************/
#pragma once

#include "DrawableObject.h"
#include "Point2D.h"
#include "Engine.h"

/**
 * \class ImageHandler
 * \brief Class that handles the image and its matrix
 * 
 * Class that handles the image and its matrix
 */
class ImageHandler : public DrawableObject
{
private:
	vector<Uint8> baseMatrix; /**< Base matrix of the image */

	int imageWidth; /**< Width of the image */
	int imageHeight; /**< Height of the image */

public:
	ImageHandler(Engine *engine, string path, Point2D start);
	void update();
	void loadBaseMatrix(vector<Uint8> baseMatrix);
	vector<Uint8> getBaseMatrix();

};

