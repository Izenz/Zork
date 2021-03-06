#pragma once
#include "Creature.h"
#include <vector>
class Item;
using namespace std;

class Player : public Creature {
public:
    Player(const string& name, const string& desc, Room* startingPoint) : Creature(name, desc, entityType::PLAYER, startingPoint) {};
    ~Player();
    void ShowInventory() const;
    bool IsInInventory(const Item* itemToFind) const;

    bool Go(const vector<string>& command);
    bool Drop(const vector<string>& command);
    bool Take(const vector<string>& command);
    bool Open(const vector<string>& command);
    bool Look(const vector<string>& command) const ;
    bool Store(const vector<string>& command);
    bool Lock(const vector<string>& command) const;
    bool Unlock(const vector<string>& command) const;
    void Look() const;
};