#include "Component.h"


Component::Component()
{
	setType(COMPONENT_DEFAULT);
}

Component::~Component()
{

}

char * Component::getType()
{
	return type;
}

void Component::setType(char * newType)
{
	type = newType;
}

void Component::requestDelete()
{
	deleteRequested = true;
}

bool Component::isDeleteRequested()
{
	return deleteRequested;
}