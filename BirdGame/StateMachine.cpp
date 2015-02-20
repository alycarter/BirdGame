#include "StateMachine.h"
#include "State.h"
#define NULL 0

StateMachine::StateMachine()
{

}


StateMachine::~StateMachine()
{

}

bool StateMachine::isEmpty()
{
	return activeState == NULL;
}

void StateMachine::update(Time * time, Controls * controls)
{
	if (activeState != NULL)
	{
		activeState->update(time, controls);
		if (activeState->isEmpty())
		{
			State * newState = activeState->getNextState();
			delete activeState;
			activeState = newState;
		}
	}
}

void StateMachine::render(GraphicsManager * graphics)
{
	if (activeState != NULL)
	{
		activeState->render(graphics);
	}
}

void StateMachine::setState(State * state)
{
	if (activeState != NULL)
	{
		delete activeState;
	}
	activeState = state;
}