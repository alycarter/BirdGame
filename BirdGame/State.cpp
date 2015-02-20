#include "State.h"
#include "SubState.h"

State::State()
{
	subStates = new vector<SubState * >();
}

State::~State()
{
	delete subStates;
}

void State::update(Time * time, Controls * controls)
{
	if (!isEmpty())
	{
		//update the current state
		subStates->at(subStates->size() - 1)->update(time, controls);
		//get any new states to be pushed
		SubState * newState = subStates->at(subStates->size() - 1)->getNextState();
		if (newState != NULL)
		{
			subStates->push_back(newState);
		}
		//if the current state needs popping then pop
		if (subStates->at(subStates->size()-1)->isPopRequested())
		{
			subStates->pop_back();
		}
	}
}

void State::render(GraphicsManager * graphics)
{
	for (int i = subStates->size()-1; i >= 0; i--)
	{
		subStates->at(i)->render(graphics);
	}
}

bool State::isEmpty()
{
	return subStates->empty();
}

State * State::getNextState()
{
	return NULL;
}

void State::addState(SubState * subState)
{
	subStates->push_back(subState);
}