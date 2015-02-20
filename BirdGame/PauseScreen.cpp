#include "PauseScreen.h"
#include "Controls.h"

PauseScreen::PauseScreen()
{
}


PauseScreen::~PauseScreen()
{
}

void PauseScreen::onUpdate(Time * time, Controls * controls)
{
	printf("pause update \n");
	if (controls->isKeyReleased(VK_ESCAPE))
	{
		RequestPop();
	}
}

SubState * PauseScreen::getNextState()
{
	return NULL;
}