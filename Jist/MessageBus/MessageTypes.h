#pragma once
#include <unordered_map>

class MessageTypes
{
public:
	enum
	{
		DOOR_OPENED,

		ENTITY_KILLED,
		ENTITY_MOVED,

		GAME_EXITED,

		INTERACT,
		ITEM_DROPPED,

		MOVE_PLAYER,

		OPEN_CHARACTER_SHEET,
		OPEN_INVENTORY,

		WINDOW_CLOSED
	};

	
	MessageTypes();
	~MessageTypes();

	void Init();

	int GetAsInt(std::string msgType);

private:
	static std::unordered_map<std::string, int> map;
};

