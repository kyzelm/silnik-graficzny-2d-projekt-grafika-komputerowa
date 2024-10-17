#include "Engine.h"

#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

Engine engine(800, 600, "SFML Engine", Style::Default);
PrimitiveRenderer renderer(&engine);

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
	renderer.drawElipse(Point2D(400, 300), Point2D(100, 50), 10, Color::Green);
	renderer.drawLine(Point2D(0, 0), Point2D(800, 600), 5, Color::Red);
}

int main()
{
	engine.setBackgroundColor(Color::White);
	engine.setFramesPerSecond(60);
	engine.setLoopFunctions(gameEventHandler, gameUpdate, gameRender);
	engine.start();

	return 0;
}