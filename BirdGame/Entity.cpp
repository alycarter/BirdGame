#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
	deleteRequested = false;
}


Entity::~Entity()
{
	components.clear();
}

void Entity::update(Time * time, Controls * controls, SubState * state)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->update(time, controls, state, this);
	}
	//delete any entities that need deleting
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components.at(i)->isDeleteRequested())
		{
			components.erase(components.begin() + i);
			i--;
		}
	}
}

void Entity::render(GraphicsManager * graphics)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->render(graphics);
	}
}

void Entity::requestDelete()
{
	deleteRequested = true;
}

bool Entity::isDeleteRequested()
{
	return deleteRequested;
}

void Entity::getComponentsOfType(vector<Component *> * foundComponents, char * type)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (strcmp(type, components.at(i)->getType()) == 0)
		{
			foundComponents->push_back(components.at(i));
		}
	}
}

bool Entity::hasComponentOfType(char * type)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (strcmp(type, components.at(i)->getType()) == 0)
		{
			return true;
		}
	}
	return false;
}

void Entity::addComponent(Component * component)
{
	components.push_back(component);
}