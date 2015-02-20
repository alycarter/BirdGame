#include "SubState.h"

#define NULL 0

SubState::SubState()
{
	requestedPop = false;
}


SubState::~SubState()
{
}

void SubState::update(Time * time, Controls * controls)
{
	onUpdate(time, controls);
}

void SubState::onUpdate(Time * time, Controls * controls)
{

}

void SubState::render(GraphicsManager * graphics)
{

}

bool SubState::isPopRequested()
{
	return requestedPop;
}

SubState * SubState::getNextState()
{
	return NULL;
}

void SubState::RequestPop()
{
	requestedPop = true;
}