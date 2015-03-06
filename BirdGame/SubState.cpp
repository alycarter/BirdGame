#include "SubState.h"
#include "Entity.h"
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
	//update all entities
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i)->update(time, controls, this);
	}
	//delete any entities that need deleting
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities.at(i)->isDeleteRequested())
		{
			entities.erase(entities.begin() + i);
			i--;
		}
	}
	onUpdate(time, controls);
}

void SubState::onUpdate(Time * time, Controls * controls)
{

}

void SubState::render(GraphicsManager * graphics)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i)->render(graphics);
	}
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

void SubState::getEntitiesWithComponentOfType(vector<Entity *> * foundEntities, char * type)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities.at(i)->hasComponentOfType(type))
		{
			foundEntities->push_back(entities.at(i));
		}
	}
}

void SubState::getComponentsOfType(vector<Component *> * foundComponents, char * type)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i)->getComponentsOfType(foundComponents , type);
	}
}

void SubState::addEntity(Entity * entity)
{
	entities.push_back(entity);
}