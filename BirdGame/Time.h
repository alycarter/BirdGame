#pragma once
#include "Object.h"
#include <Windows.h>

class Time :
	public Object
{
public:
	Time();
	~Time();
	void update();
	float getDeltaTime();
	float getRunTime();
	unsigned int getFrameRate();
private:
	float deltaTime;
	float runTime;
	DWORD startFrameTime;
};

