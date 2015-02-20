#include "MainGame.h"
#include "Scene.h"

MainGame::MainGame()
{
	addState(new Scene());
}


MainGame::~MainGame()
{
}

State * MainGame::getNextState()
{
	return NULL;
}