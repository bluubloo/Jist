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
	case MessageTypes::MOVE_PLAYER:
		std::cout << "Player has moved\n";
		break;
	case MessageTypes::OPEN_CHARACTER_SHEET:
		std::cout << "Character sheet is open\n";
		break;
	case MessageTypes::OPEN_INVENTORY:
		std::cout << "Inventory is open\n";
		break;
	default:
		break;
	}
}

void InputSystem::CloseWindow()
{
	std::list<MessageAttribute> attr;
	MessageBus::PutMessage(&Message(MessageTypes::WINDOW_CLOSED, attr));
}

