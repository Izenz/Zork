#include "Creature.h"
#include "Room.h"
#include <iostream>
using namespace std;

void Creature::Look() const {
    cout << m_Name << " : " << m_Description << endl;
}

void Creature::Attack(const int& attackPower) {
    if (IsAlive()) {
        m_CurrentHP -= attackPower;
        if (m_CurrentHP <= 0) {
            cout << m_Name << " has been defeated!" << endl;
            m_Name += "'s Corpse";
        }
            
    }
    else {
        cout << m_Name << " is already dead." << endl;
    }
}

bool Creature::IsAlive() const {
    if (m_CurrentHP > 0)
        return true;

    return false;
}