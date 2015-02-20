#include "Scene.h"
#include "Controls.h"
#include "PauseScreen.h"

Scene::Scene()
{
	needsToPause = false;
}


Scene::~Scene()
{
}

void Scene::onUpdate(Time * time, Controls * controls)
{
	printf("scene update \n");
	if (controls->isKeyReleased(VK_RETURN))
	{
		needsToPause = true;
	}
	if (controls->isKeyReleased(VK_ESCAPE))
	{
		RequestPop();
	}
}

SubState * Scene::getNextState()
{
	if (needsToPause)
	{
		printf("pause \n");
		needsToPause = false;
		return new PauseScreen();
	}
	return NULL;
}