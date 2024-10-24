#include "Engine.h"

#include "PrimitiveLine.h"
#include "PrimitiveElipse.h"
#include "PrimitiveShape.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

bool isUp = false;
bool isDown = false;
bool isLeft = false;
bool isRight = false;

Engine engine(800, 600, "SFML Engine", Style::Default);
PrimitiveLine line(&engine, Point2D(0, 0), Point2D(800, 600), 5, Color::Red);
PrimitiveElipse elipse(&engine, Point2D(400, 300), Point2D(100, 50), 5, Color::Blue);
PrimitiveShape shape(&engine, { Point2D(400, 100), Point2D(500, 50), Point2D(450, 150), Point2D(350, 150), Point2D(300, 50)}, true, 5, Color::Green);

void gameEventHandler(Event event)
{
	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Up)
		{
			isUp = true;
		}

		if (event.key.code == Keyboard::Down)
		{
			isDown = true;
		}

		if (event.key.code == Keyboard::Left)
		{
			isLeft = true;
		}

		if (event.key.code == Keyboard::Right)
		{
			isRight = true;

		}
	}

	if (event.type == Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Up)
		{
			isUp = false;
		}

		if (event.key.code == Keyboard::Down)
		{
			isDown = false;
		}

		if (event.key.code == Keyboard::Left)
		{
			isLeft = false;
		}

		if (event.key.code == Keyboard::Right)
		{
			isRight = false;
		}
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
	line.move(Point2D(isRight - isLeft, isDown - isUp));
	elipse.move(Point2D(isRight - isLeft, isDown - isUp));
	shape.move(Point2D(isRight - isLeft, isDown - isUp));
}

void gameRender()
{
	line.drawImage();
	elipse.drawImage();
	shape.drawImage();
}

int main()
{
	engine.setBackgroundColor(Color::White);
	engine.setFramesPerSecond(60);
	engine.setLoopFunctions(gameEventHandler, gameUpdate, gameRender);
	engine.start();

	return 0;
}