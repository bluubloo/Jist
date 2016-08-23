#pragma once
#include <string>

#include "MessageBus.h"
#include "MessageTypes.h"

class Console
{
public:
	Console();
	~Console();

	void ConsoleInput(std::string input);
};

