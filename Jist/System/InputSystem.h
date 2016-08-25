#pragma once
#include "System.h"
#include <iostream>

#include "MessageTypes.h"

class InputSystem : public System
{
public:
	int MOVE_PLAYER = std::hash<std::string>()("move_player");

	InputSystem();
	~InputSystem();

	void HandleMessage(Message *msg);


};

