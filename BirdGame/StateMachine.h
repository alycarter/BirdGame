#pragma once
#include "Object.h"

class State;
class Time;
class Controls;
class GraphicsManager;

class StateMachine :
	public Object
{
public:
	StateMachine();
	~StateMachine();
	bool isEmpty();
	void setState(State * state);
	void update(Time * time, Controls * controls);
	void render(GraphicsManager * graphics);
private:
	State * activeState;
};

