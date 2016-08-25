#pragma once
#include "MessageAttribute.h"
#include <string>
#include <list>

class Message
{
public:
	Message(int type, std::list<MessageAttribute> attributes);
	~Message();
	
	int MessageType;
	std::list<MessageAttribute> Attributes;
};

