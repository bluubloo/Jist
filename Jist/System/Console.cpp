#include "Console.h"



Console::Console()
{
	gameActive = true;
	MessageBus().Subscribe(this);
}


Console::~Console()
{
}

void Console::ConsoleThread()
{
	while (gameActive)
	{
		std::string message;
		std::getline(std::cin, message);
		ConsoleInput(message);
	}
}

void Console::ConsoleInput(std::string input)
{
	std::list<MessageAttribute> attributes;
	Message *msg = &Message(MessageTypes().GetAsInt(input), attributes);
	MessageBus::PutMessage(msg);
}

void Console::HandleMessage(Message * msg)
{
	switch (msg->MessageType)
	{
	case MessageTypes::GAME_EXITED:
		gameActive = false;
		break;
	}
}
