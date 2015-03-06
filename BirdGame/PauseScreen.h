#pragma once
#include "SubState.h"
class PauseScreen :
	public SubState
{
public:
	PauseScreen(bool * quitSceneFlag);
	~PauseScreen();
	void onUpdate(Time * time, Controls * controls);
	SubState * getNextState();
private:
	bool * quitScene;
};

