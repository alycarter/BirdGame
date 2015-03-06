#include "Game.h"
#include "StateMachine.h"
#include "Window.h"
#include "Controls.h"
#include "Time.h"
#include "GraphicsManager.h"

Game::Game()
{
	//set the name to game
	name = "Game";
}

Game::~Game()
{

}

void Game::play(HINSTANCE hInstance, State * startingState, wchar_t * name, int width, int height)
{
	initialize(hInstance, startingState, name, width, height);
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

void Game::initialize(HINSTANCE hInstance, State * startingState, wchar_t * name, int width, int height)
{
	controls = new Controls();
	stateMachine = new StateMachine();
	stateMachine->setState(startingState);
	window = new Window();
	window->create(name, 0, 0, width, height, hInstance);
	window->show();
	graphics.create(window, 512, 512);
	graphics.createMeshResourceFromFile("doesntMater", "obj/spit.obj", NULL);
	graphics.createTextureResourceFromFile("doesntMater", L"textures/crack.png", NULL);
	graphics.createShaderResourceFromFile("doesntMater", L"shaders/light.hlsl", "shaders/light.hlsl", NULL);
	time = new Time();
}

void Game::update()
{
	time->update();
	//printf("delta time : %f run time: %f frame rate: %u \n", time->getDeltaTime(), time->getRunTime(), time->getFrameRate());
	controls->clearKeysReleased();
	window->readMessages(controls);
	stateMachine->update(time, controls);
}

struct Instance
{
	XMMATRIX model;
	XMMATRIX rotation;
	unsigned int texture;
};

struct Constant
{
	XMFLOAT4 light;
	XMMATRIX viewProjection;
};

void Game::render()
{
	stateMachine->render(&graphics);
	graphics.bindShader(2);
	Constant constant;
	constant.light = XMFLOAT4(0, 1, 0, 1);
	constant.viewProjection = XMMatrixPerspectiveFovLH(XMConvertToRadians(45),800.0f/600.0f, 0.1f,100);
	graphics.setConstantBufferData(&constant, sizeof(Constant));
	Instance data;
	data.texture = 0;
	data.model = XMMatrixRotationRollPitchYaw(0, XMConvertToRadians(time->getRunTime()*90.0f), 0) * XMMatrixTranslation(0, 0, 2);
	data.rotation = XMMatrixIdentity() * XMMatrixRotationRollPitchYaw(0, XMConvertToRadians(time->getRunTime()*90.0f), 0);
	graphics.setInstanceBufferData(&data, sizeof(Instance), sizeof(Instance));
	graphics.drawMesh(0, 1);
	graphics.swapBuffers();
	graphics.clearBuffer();
}

void Game::destroy()
{

}