#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Engine
{
public:
	static class Primitives
	{
	public:
		static Image getLineImage(Vector2f start, Vector2f end, int thickess, Color color);
		static Image getElipseImage(Vector2f center, Vector2f radius, int thickess, Color color);
	};


private:
	bool isRunning = false;

	int windowWidth = 800;
	int windowHeight = 600;
	String windowTitle = "";
	Uint32 windowStyle = Style::Default;
	Color backgroundColor = Color::White;

	double msPerFrame = 1000.0 / 60;

	void (*gameEventHandler)(Event) = nullptr;
	void (*gameUpdate)() = nullptr;
	void (*gameRender)() = nullptr;

	RenderWindow window;
	Event event;
public:

	Engine(int windowWidth, int windowHeight, String windowTitle, Uint32 windowStyle);

	void setBackgroundColor(Color color);
	void setFramesPerSecond(int framesPerSecond);
	void setLoopFunctions(void(*gameEventHandler)(Event), void(*gameUpdate)(), void(*gameRender)());

	void start();
	void stop();

	void draw(Image image);
	void draw(Sprite sprite);
};