#pragma once
#include "Message.h"
#include <iostream>

class System
{
public:
	virtual void HandleMessage(Message *msg);
	
};