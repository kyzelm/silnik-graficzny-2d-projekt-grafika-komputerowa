/*****************************************************************//**
 * \file   ImageHandler.cpp
 * \brief  Class that handles the image and its matrix
 *********************************************************************/
#include "ImageHandler.h"
#include "DrawableObject.h"

/**
 * \brief Construct a new Image Handler
 * 
 * Construct a new Image Handler object based on the given path
 * 
 * \param engine - pointer to the engine
 * \param path - path to the image
 * \param start - starting point of the image
 */
ImageHandler::ImageHandler(Engine* engine, string path, Point2D start) : DrawableObject(engine)
{
	this->isTransformable = false;
	this->transformationMatrix[0][2] = start.getX();
	this->transformationMatrix[1][2] = start.getY();

	Image image;
	if (!image.loadFromFile(path)) {
		cerr << "B³¹d: Nie uda³o siê wczytaæ pliku: " << path << endl;
		return;
	}

	sf::Vector2u imageSize = image.getSize();
	this->imageWidth = imageSize.x;
	this->imageHeight = imageSize.y;

	this->center = Point2D(this->imageWidth / 2, this->imageHeight / 2);

	const sf::Uint8* pixels = image.getPixelsPtr();

	this->baseMatrix = vector<Uint8>(pixels, pixels + (this->imageWidth * this->imageHeight * 4));

	this->update();
}

/**
 * \brief Update the image output matrix
 *
 * Function that updates the image matrix based on the transformation matrix.
 */
void ImageHandler::update()
{
	this->matrix = vector<Uint8>(this->matrixWidth * this->matrixHeight * 4, 0);

	for (int i = 0; i < this->imageWidth; i++)
	{
		for (int j = 0; j < this->imageHeight; j++)
		{
			if (this->baseMatrix[(i + j * this->imageWidth) * 4 + 3] == 0)
			{
				continue;
			}

			int x = i * this->transformationMatrix[0][0] + j * this->transformationMatrix[0][1] + this->transformationMatrix[0][2];
			int y = i * this->transformationMatrix[1][0] + j * this->transformationMatrix[1][1] + this->transformationMatrix[1][2];

			if (x < 0 || x >= this->matrixWidth || y < 0 || y >= this->matrixHeight)
			{
				continue;
			}

			int index = (i + j * this->imageWidth) * 4;
			int newIndex = (x + y * this->matrixWidth) * 4;

			this->matrix[newIndex] = (Uint8)this->baseMatrix[index];
			this->matrix[newIndex + 1] = (Uint8)this->baseMatrix[index + 1];
			this->matrix[newIndex + 2] = (Uint8)this->baseMatrix[index + 2];
			this->matrix[newIndex + 3] = (Uint8)this->baseMatrix[index + 3];
		}
	}

	this->texture.update(this->matrix.data());
}

/**
 * \brief Set new image matrix
 * 
 * Function that sets new image matrix based on the given matrix
 * 
 * \param baseMatrix - new image matrix
 */
void ImageHandler::loadBaseMatrix(vector<Uint8> baseMatrix)
{
	this->baseMatrix = baseMatrix;
}

/**
 * \brief Get the base matrix
 * 
 * \return base matrix - the base matrix of the image
 */
vector<Uint8> ImageHandler::getBaseMatrix()
{
	return this->baseMatrix;
}
