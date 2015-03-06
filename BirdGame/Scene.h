#pragma once
#include "SubState.h"
class Scene :
	public SubState
{
public:
	Scene();
	~Scene();
	void onUpdate(Time * time, Controls * controls);
	SubState * getNextState();
private:
	bool needsToPause;
	bool quitRequest;
};

