#include "Player.h"
#include "Item.h"
#include "Room.h"
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
    return true;
}

bool Player::Take(const vector<string>& command) {

    Item* objectToTake = (Item*)m_CurrentLocation->Find(command[1], entityType::ITEM);

    if (objectToTake == NULL) {
        cout << "Such item does not exist in this room" << endl;
        return false;
    }
    else {
        objectToTake->ChangeParent(this);
        return true;
        cout << "Taken. " + objectToTake->m_Name + " added to player's inventory." << endl;
    }
    
}

bool Player::Drop(const vector<string>& command) {

    Item* objectToDrop = (Item*)Find(command[1], entityType::ITEM);

    if (objectToDrop == NULL) {
        cout << "Such item does not exist in your inventory" << endl;
        return false;
    }
    else {
        cout << "Dropped " << objectToDrop->m_Name << "into the ground." << endl;
        objectToDrop->ChangeParent(m_CurrentLocation);
        return true;
    }
}

bool Player::Look(const vector<string>& command) const {
    Entity* entityToLook = Find(command[1]);
    
    cout << entityToLook->m_Name << endl;
    cout << entityToLook->m_Description << endl;
    return true;
}

void Player::Look() const {
    cout << m_CurrentLocation->m_Name << endl;
    cout << m_CurrentLocation->m_Description << endl;
}

void Player::Update() {

}