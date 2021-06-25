#pragma once
#include "Entity.h"
class Room;
class Item;
using namespace std;


class Exit : public Entity {
public:
	Exit(const string name, const string desc, Room* source, Room* destination, const string& dir, Entity* parent, bool locked, Item* exitKey) : m_Source(source), m_Destination(destination), m_Direction(dir), m_IsLocked(locked), m_ExitKey(exitKey), Entity(name, desc, entityType::EXIT, parent) {};
	~Exit();
	string GetExitDirection() const;
	void LockExit();
	void UnlockExit();
	
	Room* m_Source;
	Room* m_Destination;
	string m_Direction;
	bool m_IsLocked;
	Item* m_ExitKey;
};