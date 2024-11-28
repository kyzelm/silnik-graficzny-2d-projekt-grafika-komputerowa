#include "Engine.h"

#include "PrimitiveLine.h"
#include "PrimitiveElipse.h"
#include "PrimitiveShape.h"
#include "ImageHandler.h"
#include "AnimationHandler.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

bool isUp = false;
bool isDown = false;
bool isLeft = false;
bool isRight = false;

Engine engine(800, 600, "SFML Engine", Style::Default);
AnimationHandler animation(&engine, {
	{"spray", "sprayAnim.png"},
	{"shape", "shapeAnim.png"}
	}, Point2D(128, 128), Point2D(400, 300), 30);
PrimitiveShape shape(&engine, { Point2D(0, 0), Point2D(100, 0), Point2D(100, 100), Point2D(0, 100) }, true, 10, Color::Red);
PrimitiveLine line(&engine, Point2D(0, 0), Point2D(100, 100), 5, Color::Blue);

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

		if (event.key.code == Keyboard::A)
		{
			shape.rotate(-5);
		}

		if (event.key.code == Keyboard::D)
		{
			shape.rotate(5);
		}

		if (event.key.code == Keyboard::W)
		{
		}

		if (event.key.code == Keyboard::S)
		{
		}

		if (event.key.code == Keyboard::Q)
		{
			animation.setFrameSet("shape");
			shape.fill(Color::Green);
		}

		if (event.key.code == Keyboard::E)
		{
			animation.setFrameSet("spray");
			shape.fill(Color::Transparent);
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
	animation.step();
	shape.move(Point2D(isRight - isLeft, isDown - isUp));
}

void gameRender()
{
	//animation.draw();
	shape.draw();
	//line.draw();
}

int main()
{
	animation.setFrameSet("spray");

	engine.setBackgroundColor(Color::White);
	engine.setFramesPerSecond(60);
	engine.setLoopFunctions(gameEventHandler, gameUpdate, gameRender);
	engine.start();

	return 0;
}