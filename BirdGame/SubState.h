#pragma once
#include "Object.h"

class Time;
class Controls;
class GraphicsManager;

class SubState :
	public Object
{
public:
	SubState();
	~SubState();
	void update(Time * time, Controls * controls);
	virtual void onUpdate(Time * time, Controls * controls);
	void render(GraphicsManager * graphics);
	bool isPopRequested();
	virtual SubState * getNextState();
protected:
	void RequestPop();
private:
	bool requestedPop;
};

