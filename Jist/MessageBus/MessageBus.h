#pragma once
#include <iostream>
#include <string>
#include <list>

#include "Message.h"
#include "System.h"
#include "InputSystem.h"

class MessageBus
{
public:


	MessageBus();
	~MessageBus();

	static void Subscribe(System* subscriber);
	static void PutMessage(Message *msg);

private:
	static std::list<System*> subscribers;
};

