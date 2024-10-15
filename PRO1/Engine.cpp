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
		cout << "Error: gameEventHandler, gameUpdate, or gameRender is not set." << endl;
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

			window.clear(backgroundColor);
			this->gameRender();
			window.display();

			lag -= this->msPerFrame;
		}
	}
}

void Engine::stop()
{
	this->isRunning = false;
}

void Engine::draw(Image image)
{
	Texture texture;
	texture.loadFromImage(image);

	Sprite sprite(texture);
	sprite.setPosition(0, 0);

	this->window.draw(sprite);

}

void Engine::draw(Sprite sprite)
{
	this->window.draw(sprite);
}

Image Engine::Primitives::getLineImage(Vector2f start, Vector2f end, int thickess, Color color)
{
	Image image;
	image.create(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height, Color::Transparent);

	float dx = end.x - start.x;
	float dy = end.y - start.y;
	float m = abs(dy / dx);

	float ly, hy, lx, hx;

	if (m < 1) {
		if (dx < 0)
		{
			lx = end.x;
			hx = start.x;
			ly = end.y;
			hy = start.y;
		}
		else
		{
			lx = start.x;
			hx = end.x;
			ly = start.y;
			hy = end.y;
		}

		for (; lx <= hx; lx++)
		{
			for (int i = 0; i < thickess; i++)
			{
				if ((ly + ((int)(i / 2) + 0.5) * pow(-1, i)) >= 0 && (ly + ((int)(i / 2) + 0.5) * pow(-1, i)) < image.getSize().y && lx >= 0 && lx < image.getSize().x)
				{
					image.setPixel(lx, (ly + ((int)(i / 2) + 0.5) * pow(-1, i)), color);
				}
			}
			ly += ly < hy ? m : -m;
		}
	}
	else {
		if (dy < 0)
		{
			lx = end.x;
			hx = start.x;
			ly = end.y;
			hy = start.y;
		}
		else
		{
			lx = start.x;
			hx = end.x;
			ly = start.y;
			hy = end.y;
		}

		for (; ly <= hy; ly++)
		{
			for (int i = 0; i < thickess; i++)
			{
				if ((lx + ((int)(i / 2) + 0.5) * pow(-1, i)) >= 0 && (lx + ((int)(i / 2) + 0.5) * pow(-1, i)) < image.getSize().x && ly >= 0 && ly < image.getSize().y)
				{
					image.setPixel((lx + ((int)(i / 2) + 0.5) * pow(-1, i)), ly, color);
				}
			}
			lx += lx < hx ? 1 / m : -1 / m;
		}
	}

	return image;
}
