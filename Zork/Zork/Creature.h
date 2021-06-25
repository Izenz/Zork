#pragma once
#include "Entity.h"
class Room;
using namespace std;

class Creature : public Entity{
public:
    Creature(const string& name, const string& desc, const entityType type, Room* location) : 
        m_CurrentLocation(location), Entity(name, desc, type) {};
    ~Creature();

    Room* m_CurrentLocation;
};