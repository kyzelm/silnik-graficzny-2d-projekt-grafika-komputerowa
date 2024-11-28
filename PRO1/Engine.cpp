/*****************************************************************//**
 * \file   Engine.cpp
 * \brief  Main engine class for the game.
 *********************************************************************/
#include "Engine.h"

/**
 * \brief Construct a new Engine object
 * 
 * Construct a new Engine object with default values.
 * 
 * \param windowWidth - Width of the window.
 * \param windowHeight - Height of the window.
 * \param windowTitle - Title of the window.
 * \param windowStyle - SFML style of the window.
 */
Engine::Engine(int windowWidth = 800, int windowHeight = 600, String windowTitle = "", Uint32 windowStyle = Style::Default)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->windowTitle = windowTitle;
	this->windowStyle = windowStyle;
}

/**
 * \brief Set the background color of the window.
 * 
 * Function to set the background color of the window.
 * 
 * \param color - Color to set the background to.
 */
void Engine::setBackgroundColor(Color color)
{
	this->backgroundColor = color;
}

/**
 * \brief Set the frames per second of the game.
 * 
 * Function to set the frames per second of the game.
 * 
 * \param framesPerSecond - Frames per second to set the game to.
 */
void Engine::setFramesPerSecond(int framesPerSecond)
{
	this->msPerFrame = 1000.0 / framesPerSecond;
}

/**
 * \brief Set the loop functions of the game.
 * 
 * Function to set the loop functions of the game, including the event handler, update function, and render function.
 * 
 * \param gameEventHandler - Event handler function.
 * \param gameUpdate - Update function.
 * \param gameRender - Render function.
 */
void Engine::setLoopFunctions(void(*gameEventHandler)(Event), void(*gameUpdate)(), void(*gameRender)())
{
	this->gameEventHandler = gameEventHandler;
	this->gameUpdate = gameUpdate;
	this->gameRender = gameRender;
}

/**
 * \brief Start the game.
 * 
 * Function to start the game loop.
 */
void Engine::start()
{
	if (this->gameEventHandler == nullptr || this->gameUpdate == nullptr || this->gameRender == nullptr)
	{
		cout << "Error: gameEventHandler, gameUpdate, or scenes are not set." << endl;
		return;
	}

	this->window.create(VideoMode(this->windowWidth, this->windowHeight), this->windowTitle, this->windowStyle);

	this->isRunning = true;

	double previousTime = clock();
	double lag = 0.0;

	while (this->isRunning)
	{
		double currentTime = clock();
		double elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		lag += elapsedTime;

		while (this->window.pollEvent(this->event))
		{
			if (event.type == Event::Closed)
			{
				this->stop();
			}

			this->gameEventHandler(this->event);
		}

		while (lag >= this->msPerFrame)
		{
			this->gameUpdate();

			this->window.clear(backgroundColor);
			this->gameRender();
			this->window.display();

			lag -= this->msPerFrame;
		}
	}
}


/**
 * \brief Stop the game.
 *
 * Function to stop the game loop.
 */
void Engine::stop()
{
	this->isRunning = false;
}

/**
 * \brief Get the width of the window.
 * 
 * Function to get the width of the window.
 * 
 * \return windowWidth - Width of the window.
 */
int Engine::getMatrixWidth()
{
	return this->windowWidth;
}

/**
 * \brief Get the height of the window.
 * 
 * Function to get the height of the window.
 * 
 * \return windowHeight - Height of the window.
 */
int Engine::getMatrixHeight()
{
	return this->windowHeight;
}

/**
 * \brief Get the coordinates of the mouse.
 * 
 * Function to get the coordinates of the mouse.
 * 
 * \return mouseCoords - Coordinates of the mouse.
 */
Point2D Engine::getMouseConrds()
{
	return Point2D(Mouse::getPosition(this->window).x, Mouse::getPosition(this->window).y);
}