#pragma once
#include "Object.h"

class SubState;

enum RESOURCE_TYPE { RESOURCE_TYPE_MESH, RESOURCE_TYPE_TEXTURE, RESOURCE_TYPE_SHADER};

class GraphicsResource :
	public Object
{
public:
	GraphicsResource();
	~GraphicsResource();
	RESOURCE_TYPE getType();
	SubState * getBoundSubState();
protected:
	void setType(RESOURCE_TYPE newType);
	void bindToSubState(SubState * bind);
private:
	RESOURCE_TYPE type;
	SubState * boundSubState;
};

