
#include "Console.h"
#include "InputSystem.h"
#include <iostream>


int main()
{
	MessageBus().Subscribe(&InputSystem());
	MessageTypes().Init();
	bool gameActive = true;
	std::string message;
	while (gameActive)
	{
		std::getline(std::cin, message);
		Console().ConsoleInput(message);
	}
	return 0;
}