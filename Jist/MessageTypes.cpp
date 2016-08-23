#include "MessageTypes.h"

std::unordered_map<std::string, int> MessageTypes::map;

MessageTypes::MessageTypes()
{
}


MessageTypes::~MessageTypes()
{
}

void MessageTypes::Init()
{
	map.insert({ "open_inventory", OPEN_INVENTORY });
	map.insert({ "move_player", MOVE_PLAYER });
	map.insert({ "open_character_sheet", OPEN_CHARACTER_SHEET });
}

int MessageTypes::GetAsInt(std::string msgType)
{
	std::unordered_map<std::string, int>::iterator i = map.find(msgType);
	if (i == map.end()) { return -1; }
	return i->second;
	return -1;
}
