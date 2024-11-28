/*****************************************************************//**
 * \file   AnimationHandler.h
 * \brief  Class that handles animations sheets
 *********************************************************************/
#include "AnimationHandler.h"
#include "DrawableObject.h"

/**
 * \brief Construct a new AnimationHandler
 * 
 * Construct a new AnimationHandler object with given spite sheet.
 * 
 * \param engine - pointer to the engine
 * \param framesPaths - map of frames paths with names
 * \param dimensions - dimensions of the frame
 * \param start - start point of the animation
 * \param frameCount - number of frames by one step
 */
AnimationHandler::AnimationHandler(Engine* engine, map<string, string> framesPaths, Point2D dimensions, Point2D start, int frameCount) : DrawableObject(engine)
{
	this->isTransformable = false;
	this->transformationMatrix[0][2] = start.getX();
	this->transformationMatrix[1][2] = start.getY();

	this->imageWidth = dimensions.getX();
	this->imageHeight = dimensions.getY();

	this->frameCount = frameCount;

	Image image;

	for (auto it = framesPaths.begin(); it != framesPaths.end(); it++)
	{
		string name = it->first;
		string path = it->second;

		if (!image.loadFromFile(path)) {
			cerr << "B³¹d: Nie uda³o siê wczytaæ pliku: " << path << endl;
			return;
		}

		int width = image.getSize().x;
		int height = image.getSize().y;

		this->spriteSheetWidth = width;

		const sf::Uint8* pixels = image.getPixelsPtr();

		if (this->currentFrameSet.empty())
		{
			this->currentFrameSet = it->first;
		}

		this->framesMap[name] = vector<Uint8>(pixels, pixels + width * height * 4);
	}

	this->update();
}

/**
 * \brief Update the animation
 * 
 * Function that updates the animation matrix based on actual frame number. 
 */
void AnimationHandler::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4, 0);

	for (int i = 0; i < this->imageWidth; i++)
	{
		for (int j = 0; j < this->imageHeight; j++)
		{
			int x = i * this->transformationMatrix[0][0] + j * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
			int y = i * this->transformationMatrix[1][0] + j * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

			if (x < 0 || x >= this->matrixWidth || y < 0 || y >= this->matrixHeight)
			{
				continue;
			}

			int index = (i + j * this->spriteSheetWidth) * 4 + this->frameNumber * 4 * this->imageWidth;
			int newIndex = (x + y * this->matrixWidth) * 4;

			this->matrix[newIndex] = (Uint8)this->framesMap[this->currentFrameSet][index];
			this->matrix[newIndex + 1] = (Uint8)this->framesMap[this->currentFrameSet][index + 1];
			this->matrix[newIndex + 2] = (Uint8)this->framesMap[this->currentFrameSet][index + 2];
			this->matrix[newIndex + 3] = (Uint8)this->framesMap[this->currentFrameSet][index + 3];
		}
	}

	this->texture.update(this->matrix.data());


}

/**
 * \brief Step the animation
 * 
 * Function that steps the animation to the next frame.
 */
void AnimationHandler::step()
{
	this->frameCounter++;

	if (this->frameCounter >= this->frameCount)
	{
		this->frameCounter = 0;
		this->frameNumber++;

		if (this->frameNumber * this->imageWidth >= this->spriteSheetWidth)
		{
			this->frameNumber = 0;
		}

		this->update();
	}

}

/**
 * \brief Set the frame set
 * 
 * \param name - name of the frame set
 */
void AnimationHandler::setFrameSet(string name)
{
	this->currentFrameSet = name;
}
