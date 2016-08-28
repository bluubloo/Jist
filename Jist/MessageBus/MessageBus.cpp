#include "MessageBus.h"

std::list<System*> MessageBus::subscribers;

MessageBus::MessageBus()
{
	
}


MessageBus::~MessageBus()
{
}


//Adds a system to the subscriber list so it will receive messages from the message bus
void MessageBus::Subscribe(System* subscriber)
{
	subscribers.push_back(subscriber);
}

void MessageBus::PutMessage(Message *msg)
{
	for each (System* sys in subscribers)
	{
		sys->HandleMessage(msg);
	}
}