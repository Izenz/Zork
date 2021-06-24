#pragma once
#include "Entity.h"
class Room;
using namespace std;

class Creature : public Entity{
public:
    Creature(const string& name, const string& desc, const entityType type, Room* location, const int& hp, const int& attack) : 
        m_CurrentLocation(location), m_CurrentHP(hp), m_MaxHP(hp), m_AttackPower(attack), Entity(name, desc, type) {};
    void Look() const;
    void Attack(const int& attackPower);
    bool IsAlive() const;

    Room* m_CurrentLocation;

    int m_CurrentHP;
    int m_MaxHP;
    int m_AttackPower;
};