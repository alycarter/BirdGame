#include "Time.h"


Time::Time()
{
	deltaTime = 0;
	runTime = 0;
	startFrameTime = GetTickCount();
}


Time::~Time()
{
}

void Time::update()
{
	DWORD endFrameTime = GetTickCount();
	deltaTime = (float)(endFrameTime - startFrameTime) / 1000.0f;
	startFrameTime = GetTickCount();
	runTime += deltaTime;
}

float Time::getDeltaTime()
{
	return deltaTime;
}

float Time::getRunTime()
{
	return runTime;
}

unsigned int Time::getFrameRate()
{
	return (unsigned int)(1.0f / deltaTime);
}