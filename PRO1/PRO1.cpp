#include "Engine.h"

#include <iostream>

using namespace std;

Engine engine(800, 600, "SFML Engine", Style::Default);

void gameEventHandler(Event event)
{
	if (event.type == Event::KeyPressed)
	{
	}

	if (event.type == Event::KeyReleased)
	{
	}

	if (event.type == Event::MouseButtonPressed)
	{
	}

	if (event.type == Event::MouseButtonReleased)
	{
	}

	if (event.type == Event::MouseMoved)
	{
	}

	if (event.type == Event::MouseWheelMoved)
	{
	}
}

void gameUpdate()
{
}

void gameRender()
{
	Image line = Engine::Primitives::getLineImage(Vector2f(0, 0), Vector2f(800, 600), 3, Color::Red);
	engine.draw(line);
}

int main()
{
	engine.setBackgroundColor(Color::White);
	engine.setFramesPerSecond(60);
	engine.setLoopFunctions(gameEventHandler, gameUpdate, gameRender);
	engine.start();

	return 0;
}