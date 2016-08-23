#pragma once
#include "Message.h"

class MessageInput
{
public:
	//List of all the message types for easy decoding
	typedef enum
	{
		MOVE_PLAYER = 0,
		OPEN_INVENTORY,
		OPEN_SHEET
	};

	MessageInput(int type);
	~MessageInput();
};

