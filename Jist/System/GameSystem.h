#pragma once
#include <System.h>
#include "MessageTypes.h"
#include "MessageBus.h"


class GameSystem : public System
{
public:
	

	GameSystem();
	~GameSystem();

	void HandleMessage(Message *msg);

	bool IsActive();

private:
	bool isActive; //The game active bool is private so only methods within the GameSystem classe can alter it
};

