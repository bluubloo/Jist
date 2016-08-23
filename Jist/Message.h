#pragma once

#include <string>

class Message
{
public:
	Message(int type);
	~Message();
	
	int MessageType;
};

