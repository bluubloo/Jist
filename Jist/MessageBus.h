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

	void Start();
	void Subscribe(System* subscriber);
	void PutMessage(Message *msg);

private:
	static std::list<System*> subscribers;
};

