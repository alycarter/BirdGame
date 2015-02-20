#pragma once
#include "SubState.h"
class PauseScreen :
	public SubState
{
public:
	PauseScreen();
	~PauseScreen();
	void onUpdate(Time * time, Controls * controls);
	SubState * getNextState();
};

