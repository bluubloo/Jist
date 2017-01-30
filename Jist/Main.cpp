
#include "Draw.h"
#include "Input.h"

#include "Console.h"
#include "InputSystem.h"
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
	Draw draw;
	Shaders::Init();
	Input input(draw.GetWindow());
	std::thread consoleInput(&Console::ConsoleThread, Console());
	consoleInput.detach();

	bool gameActive = true;
	std::string message;
	draw.Redraw();
	while (game.IsActive())
	{
		input.CheckInput();
	}
	return 0;
}