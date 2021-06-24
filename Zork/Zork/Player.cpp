#include "Player.h"
#include "Item.h"
#include "Room.h"
#include "Exit.h"
#include <iostream>
#include <vector>
using namespace std;

Player::~Player() {

}

void Player::ShowInventory() const {
    list<Entity*> inventoryItems;
    Entity::FindAll(entityType::ITEM, inventoryItems);

    if (inventoryItems.size() == 0) {
        cout << "Inventory is empty." << endl;
        return;
    }

    for (Entity* item : inventoryItems) {
        cout << item->m_Name << endl;
    }
}

bool Player::Go(const vector<string>& command) {
    Exit* chosenPath = (Exit*)m_CurrentLocation->GetExit(command[1]);

    if (chosenPath != NULL) {
        ChangeParent(chosenPath->m_Destination);
        m_CurrentLocation = chosenPath->m_Destination;
        return true;
    }
    else
        return false;
}

bool Player::Take(const vector<string>& command) {

    Item* objectToTake = (Item*)m_CurrentLocation->Find(command[1], entityType::ITEM);

    if (objectToTake == NULL) {
        return false;
    }
    else {
        objectToTake->ChangeParent(this);
        return true;
    }
    
}

bool Player::Drop(const vector<string>& command) {

    Item* objectToDrop = (Item*)Find(command[1], entityType::ITEM);

    if (objectToDrop == NULL) {
        return false;
    }
    else {
        objectToDrop->ChangeParent(m_CurrentLocation);
        return true;
    }
}

bool Player::Look(const vector<string>& command) const {
    Entity* entityToLook = Find(command[1]);
    if (entityToLook != NULL) {
        cout << entityToLook->m_Name << endl;
        cout << entityToLook->m_Description << endl;
        return true;
    }
    else
        return false;
    
}

void Player::Look() const {
    cout << m_CurrentLocation->m_Name << endl;
    cout << m_CurrentLocation->m_Description << endl;
}

void Player::Update() {

}