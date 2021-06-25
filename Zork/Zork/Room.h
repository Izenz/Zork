#pragma once
#include "Entity.h"
class Exit;
#include <list>
using namespace std;

enum class exitTypes
{
    NORTH,
    EAST,
    WEST,
    SOUTH
};

class Room : public Entity {
public:
    Room(const string name, const string desc) : Entity(name, desc, entityType::ROOM) {};
    ~Room();
    Exit* GetExit(const string& orientation);
    void Look();
};