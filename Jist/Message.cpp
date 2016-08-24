#include "Message.h"



Message::Message(int type, std::list<MessageAttribute> attributes)
{
	MessageType = type;
	Attributes = attributes;
}


Message::~Message()
{
}
