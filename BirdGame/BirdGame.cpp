#include <windows.h>
#include "Game.h"
#include "MainGame.h"

#include <stdio.h>

#define DEBUG true

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	FILE * stream;
	if (DEBUG)
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		freopen_s(&stream, "CONOUT$", "w", stdout);
	}
	//create a game
	Game game;
	//play the game withe the window size and name info
	game.play(hInstance ,new MainGame(), L"Bird Game", 100,100,800, 600);
	if (DEBUG)
	{
		fclose(stream);
	}
	return 0;
}


