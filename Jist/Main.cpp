
#include "Console.h"
#include "InputSystem.h"
#include "Draw.h"
#include <iostream>
#include <thread>


int main()
{
	MessageBus().Subscribe(&InputSystem());
	MessageTypes().Init();

	//Create the drawing thread and join it
	Draw window;
	std::thread consoleInput(&Console::ConsoleThread, Console());
	consoleInput.detach();

	bool gameActive = true;
	std::string message;
	while (gameActive)
	{
		window.Redraw();
	}
	return 0;
}