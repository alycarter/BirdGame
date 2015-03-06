#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Time;
class Controls;
class GraphicsManager;
class SubState;
class Component;

class Entity :
	public Object
{
public:
	Entity();
	~Entity();
	void update(Time * time, Controls * controls, SubState * state);
	void render(GraphicsManager * graphics);
	void addComponent(Component * component);
	void getComponentsOfType(vector<Component *> * foundComponents, char * type);
	bool hasComponentOfType(char * type);
	void requestDelete();
	bool isDeleteRequested();
private:
	vector<Component *> components;
	bool deleteRequested;
};

