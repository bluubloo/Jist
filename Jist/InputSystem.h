#pragma once
#include "System.h"
#include "MessageInput.h"
#include <iostream>

class InputSystem : public System
{
public:
	InputSystem();
	~InputSystem();

	void HandleMessage(Message *msg);
};

