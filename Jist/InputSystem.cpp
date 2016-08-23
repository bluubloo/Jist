#include "InputSystem.h"



InputSystem::InputSystem()
{
}


InputSystem::~InputSystem()
{
}

void InputSystem::HandleMessage(Message *msg)
{
	switch (msg->MessageType)
	{
	case MessageInput::MOVE_PLAYER:
		std::cout << "Player has moved";
		break;
	default:
		break;
	}
}
