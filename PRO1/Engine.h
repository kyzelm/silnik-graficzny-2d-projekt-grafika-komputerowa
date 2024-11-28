/*****************************************************************//**
 * \file   Engine.h
 * \brief  Main engine class for the game.
 *********************************************************************/
#pragma once 

#include "Point2D.h"
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/**
 * \class Engine
 * \brief Main engine class for the game.
 * 
 * Class that contains the main loop of the game.
 */
class Engine
{
private:

	bool isRunning = false; /**< Is main loop running */ 
	int windowWidth = 800; /**< Width of the window */
	int windowHeight = 600; /**< Height of the window */
	String windowTitle = ""; /**< Title of the window */
	Uint32 windowStyle = Style::Default; /**< Style of the window */
	Color backgroundColor = Color::White; /**< Background color of the window */

	double msPerFrame = 1000.0 / 60; /**< Milliseconds per frame */

	void (*gameEventHandler)(Event) = nullptr; /**< Event handler function */
	void (*gameUpdate)() = nullptr; /**< Update function */
	void (*gameRender)() = nullptr; /**< Render function */

	Event event; /**< Event handler object */

public:
	RenderWindow window; /**< Render window object */
	
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