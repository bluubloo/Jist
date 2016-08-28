
#include "Console.h"
#include "InputSystem.h"
#include "Draw.h"
#include "GameSystem.h"

#include <iostream>
#include <thread>


int main()
{
	GameSystem game;

	MessageBus().Subscribe(&InputSystem());
	MessageBus().Subscribe(&game);
	MessageTypes().Init();

	//Create the drawing thread and join it
	Draw window;
	std::thread consoleInput(&Console::ConsoleThread, Console());
	consoleInput.detach();

	bool gameActive = true;
	std::string message;
	while (game.IsActive())
	{
		window.Redraw();
	}
	return 0;
}