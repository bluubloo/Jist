#pragma once
#include <unordered_map>

class MessageTypes
{
public:
	enum
	{
		MOVE_PLAYER = 0,
		OPEN_INVENTORY,
		OPEN_CHARACTER_SHEET
	};

	
	MessageTypes();
	~MessageTypes();

	void Init();

	int GetAsInt(std::string msgType);

private:
	static std::unordered_map<std::string, int> map;
};

