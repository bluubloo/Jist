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
	map.insert({ "door_opened", DOOR_OPENED });

	map.insert({ "entity_killed", ENTITY_KILLED });
	map.insert({ "entity_moved", ENTITY_MOVED });

	map.insert({ "interact", INTERACT });
	map.insert({ "item_dropped", ITEM_DROPPED });

	map.insert({ "move_player", MOVE_PLAYER });

	map.insert({ "open_character_sheet", OPEN_CHARACTER_SHEET });
	map.insert({ "open_inventory", OPEN_INVENTORY });
}

int MessageTypes::GetAsInt(std::string msgType)
{
	std::unordered_map<std::string, int>::iterator i = map.find(msgType);
	if (i == map.end()) { return -1; }
	return i->second;
	return -1;
}
