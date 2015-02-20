#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Time;
class Controls;
class GraphicsManager;
class SubState;

class State :
	public Object
{
public:
	State();
	~State();
	void update(Time * time, Controls * controls);
	void render(GraphicsManager * graphics);
	bool isEmpty();
	virtual State * getNextState();
protected:
	void addState(SubState * subState);
private:
	vector<SubState*> * subStates;
};

