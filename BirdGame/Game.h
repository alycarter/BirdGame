#pragma once
#include "Object.h"
#include "GraphicsManager.h"
#include <Windows.h>

class StateMachine;
class State;
class Window;
class Controls;
class Time;

class Game :
	public Object
{
public:
	Game();
	~Game();
	void play(HINSTANCE hInstance, State * startingState, wchar_t * name, int width, int height);
private:
	void run();
	void initialize(HINSTANCE hInstance, State * startingState, wchar_t * name, int width, int height);
	void update();
	void render();
	void destroy();
	StateMachine * stateMachine;
	Window * window;
	Controls * controls;
	Time * time;
	GraphicsManager graphics;
};

