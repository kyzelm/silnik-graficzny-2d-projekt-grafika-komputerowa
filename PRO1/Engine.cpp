#include "Engine.h"

Engine::Engine(int windowWidth = 800, int windowHeight = 600, String windowTitle = "", Uint32 windowStyle = Style::Default)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->windowTitle = windowTitle;
	this->windowStyle = windowStyle;
}

void Engine::setBackgroundColor(Color color)
{
	this->backgroundColor = color;
}

void Engine::setFramesPerSecond(int framesPerSecond)
{
	this->msPerFrame = 1000.0 / framesPerSecond;
}

void Engine::setLoopFunctions(void(*gameEventHandler)(Event), void(*gameUpdate)(), void(*gameRender)())
{
	this->gameEventHandler = gameEventHandler;
	this->gameUpdate = gameUpdate;
	this->gameRender = gameRender;
}

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

void Engine::stop()
{
	this->isRunning = false;
}

int Engine::getMatrixWidth()
{
	return this->windowWidth;
}

int Engine::getMatrixHeight()
{
	return this->windowHeight;
}

Point2D Engine::getMouseConrds()
{
	return Point2D(Mouse::getPosition(this->window).x, Mouse::getPosition(this->window).y);
}