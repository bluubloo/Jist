#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}

void Console::ConsoleInput(std::string input)
{
	Message *msg = &Message(MessageTypes().GetAsInt(input));
	MessageBus().PutMessage(msg);
}
