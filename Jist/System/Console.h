#pragma once
#include <string>
#include <iostream>

#include "MessageBus.h"
#include "MessageTypes.h"

class Console : public System
{
public:
	Console();
	~Console();

	void ConsoleThread();

	void ConsoleInput(std::string input);

	void HandleMessage(Message *msg);

private:
	bool gameActive;
};

