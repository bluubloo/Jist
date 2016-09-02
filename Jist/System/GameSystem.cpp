#include "GameSystem.h"



GameSystem::GameSystem()
{
	isActive = true;
}


GameSystem::~GameSystem()
{
}

void GameSystem::HandleMessage(Message * msg)
{
	switch (msg->MessageType)
	{
	case MessageTypes::WINDOW_CLOSED:
		isActive = false;
		std::list<MessageAttribute> attr;
		MessageBus::PutMessage(&Message(MessageTypes::GAME_EXITED, attr));
		break;
	}
}

bool GameSystem::IsActive()
{
	return isActive;
}
