#include "GraphicsResource.h"

#define NULL 0

GraphicsResource::GraphicsResource()
{
	boundSubState = NULL;
}

GraphicsResource::~GraphicsResource()
{

}

RESOURCE_TYPE GraphicsResource::getType()
{
	return type;
}

SubState * GraphicsResource::getBoundSubState()
{
	return boundSubState;
}

void GraphicsResource::setType(RESOURCE_TYPE newType)
{
	type = newType;
}

void GraphicsResource::bindToSubState(SubState * bind)
{
	boundSubState = bind;
}
