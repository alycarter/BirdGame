#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Time;
class Controls;
class GraphicsManager;
class Entity;
class Component;

class SubState :
	public Object
{
public:
	SubState();
	~SubState();
	void update(Time * time, Controls * controls);
	virtual void onUpdate(Time * time, Controls * controls);
	void render(GraphicsManager * graphics);
	bool isPopRequested();
	virtual SubState * getNextState();
	void getEntitiesWithComponentOfType(vector<Entity *> * foundEntities, char * type);
	void getComponentsOfType(vector<Component *> * foundComponents, char * type);
	void addEntity(Entity * entity);
protected:
	void RequestPop();
private:
	vector<Entity*> entities;
	bool requestedPop;
};

