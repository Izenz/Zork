#pragma once
#include "Creature.h"
#include <vector>
using namespace std;

class Player : public Creature {
public:
    Player(const string& name, const string& desc, Room* startingPoint, const int& hp, const int& attack) : Creature(name, desc, entityType::PLAYER, startingPoint, hp, attack) {};
    ~Player();
    void ShowInventory() const;
    bool Go(const vector<string>& command);
    bool Drop(const vector<string>& command);
    bool Take(const vector<string>& command);
    bool Look(const vector<string>& command) const ;
    void Look() const;
    void Update() override;
private:
    
};