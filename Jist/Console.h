#pragma once
#include <string>
#include <iostream>

#include "MessageBus.h"
#include "MessageTypes.h"

class Console
{
public:
	Console();
	~Console();

	void ConsoleThread();

	void ConsoleInput(std::string input);
};

