#include "Game.h"
#include "StateMachine.h"
#include "Window.h"
#include "Controls.h"
#include "Time.h"

Game::Game()
{
	//set the name to game
	name = "Game";
}

Game::~Game()
{

}

void Game::play(HINSTANCE hInstance, State * startingState, wchar_t * name, int x, int y, int width, int height)
{
	initialize(hInstance, startingState, name, x, y, width, height);
	run();
	destroy();
}

void Game::run()
{
	while (!stateMachine->isEmpty() && !window->isQuitRequested())
	{
		update();
		render();
	}
}

void Game::initialize(HINSTANCE hInstance, State * startingState, wchar_t * name, int x, int y, int width, int height)
{
	controls = new Controls();
	stateMachine = new StateMachine();
	stateMachine->setState(startingState);
	window = new Window();
	window->create(name, x, y, width, height, hInstance);
	window->show();
	time = new Time();
}

void Game::update()
{
	time->update();
	printf("delta time : %f run time: %f frame rate: %u \n", time->getDeltaTime(), time->getRunTime(), time->getFrameRate());
	controls->clearKeysReleased();
	window->readMessages(controls);
	stateMachine->update(time, controls);
}

void Game::render()
{
	stateMachine->render(graphics);
}

void Game::destroy()
{

}