#pragma once
#include <list>
#include <vector>
class Player;
#include <string>
class Entity;

using namespace std;

class World {
public:
    World();
    ~World();

    bool ExecuteCommand(const vector<string>& command);
private:
    list<Entity*> m_Entities;
    Player* m_Player;
};