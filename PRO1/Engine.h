#pragma once 

#include "Point2D.h"
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Engine
{
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

	Event event;

public:
	RenderWindow window;
	
	Engine(int windowWidth, int windowHeight, String windowTitle, Uint32 windowStyle);

	void setBackgroundColor(Color color);
	void setFramesPerSecond(int framesPerSecond);
	void setLoopFunctions(void(*gameEventHandler)(Event), void(*gameUpdate)(), void(*gameRender)());

	void start();
	void stop();

	int getMatrixWidth();
	int getMatrixHeight();

	Point2D getMouseConrds();

};