#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}

void Console::ConsoleThread()
{
	std::string message;
	std::getline(std::cin, message);
	ConsoleInput(message);
}

void Console::ConsoleInput(std::string input)
{
	std::list<MessageAttribute> attributes;
	Message *msg = &Message(MessageTypes().GetAsInt(input), attributes);
	MessageBus().PutMessage(msg);
}
