#pragma once
#include "Entity.h"
class Room;
using namespace std;


class Exit : public Entity {
public:
	Exit(const string name, const string desc, Room* source, Room* destination, const string& dir, Entity* parent) : m_Source(source), m_Destination(destination), m_Direction(dir), Entity(name, desc, entityType::EXIT, parent) {};
	~Exit();
	string GetExitDirection() const;
	void Update() override;
	
	Room* m_Source;
	Room* m_Destination;
	string m_Direction;
};