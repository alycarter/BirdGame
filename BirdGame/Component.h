#pragma once
#include "Object.h"

class Time;
class Controls;
class GraphicsManager;
class SubState;
class Entity;

#define COMPONENT_DEFAULT "default"

class Component :
	public Object
{
public:
	Component();
	~Component();
	virtual void update(Time * time, Controls * controls, SubState * state, Entity * entity){}
	virtual void render(GraphicsManager * graphics){}
	char * getType();
	void requestDelete();
	bool isDeleteRequested();
protected:
	void setType(char * newType);
private:
	bool deleteRequested;
	char * type;
};

