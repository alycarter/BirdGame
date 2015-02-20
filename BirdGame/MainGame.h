#pragma once
#include "State.h"
class MainGame :
	public State
{
public:
	MainGame();
	~MainGame();
	State * getNextState();
};

