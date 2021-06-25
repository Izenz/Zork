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
        if (chosenPath->m_IsLocked) {
            cout << "The door is locked.";
            return false;
        }
        else{
            ChangeParent(chosenPath->m_Destination);
            m_CurrentLocation = chosenPath->m_Destination;
        }
        return true;
    }
    else {
        cout << "There's nothing there.";
        return false;
    }
        
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
    // Try looking items on inventory
    Entity* entityToLook = Find(command[1]);
    if (entityToLook != NULL) {
        cout << entityToLook->m_Name << endl;
        cout << entityToLook->m_Description << endl;
        return true;
    }
    else {
        // Try looking on current room
        entityToLook = m_CurrentLocation->Find(command[1]);
        if (entityToLook != NULL) {
            cout << entityToLook->m_Name << endl;
            cout << entityToLook->m_Description << endl;
            return true;
        }
        else {
            return false;
        }
    }
}

bool Player::Lock(const vector<string>& command) const {
    Exit* chosenPath = (Exit*)m_CurrentLocation->GetExit(command[1]);
    bool hasKey = false;
    if (chosenPath != NULL) {
        if (chosenPath->m_ExitKey != NULL)
            hasKey = IsInInventory(chosenPath->m_ExitKey);

        if (!chosenPath->m_IsLocked) {
            if (hasKey) {
                chosenPath->LockExit();
            }
            else {
                cout << "You dont have the key to this exit." << endl;
                return false;
            }
        }
        else {
            cout << "This exit is already locked." << endl;
            return false;
        }
    }
    else {
        cout << "There's nothing there." << endl;
        return false;
    }
}

bool Player::Unlock(const vector<string>& command) const {
    Exit* chosenPath = (Exit*)m_CurrentLocation->GetExit(command[1]);
    bool hasKey = false;
    if (chosenPath != NULL) {
        if (chosenPath->m_ExitKey != NULL)
            hasKey = IsInInventory(chosenPath->m_ExitKey);

        if (chosenPath->m_IsLocked) {
            if (hasKey) {
                chosenPath->UnlockExit();
            }
            else {
                cout << "You dont have the key to this exit." << endl;
                return false;
            }
        }
        else {
            cout << "This exit is already unlocked." << endl;
            return false;
        }
    }
    else {
        cout << "There's nothing there." << endl;
        return false;
    }
}

bool Player::Open(const vector<string>& command) {
    Item* itemToOpen = (Item*)Find(command[1]);
    if (itemToOpen != NULL) {
        itemToOpen->OpenChest();
        return true;
    }
    else
        return false;
}

bool Player::Store(const vector<string>& command) {
    Item* itemToStore = (Item*)Find(command[1]);
    Item* storageItem = (Item*)Find(command[3]);

    if (!_stricmp(command[1].c_str(), command[3].c_str())) {
        cout << "Are you trying to store an object inside itself?. ";
        return false;
    }
    else if (itemToStore != NULL && storageItem != NULL && storageItem->m_ItemType == itemType::CHEST) {
        itemToStore->ChangeParent(storageItem);
        cout << "You stored " << itemToStore->m_Name << " inside " << storageItem->m_Name << endl;
        return true;
    }
    else {
        return false;
    }
}

void Player::Look() const {
    cout << m_CurrentLocation->m_Name << endl;
    cout << m_CurrentLocation->m_Description << endl;
}

bool Player::IsInInventory(const Item* itemToFind) const {
    for (Entity* item : m_ContainedEntities) {
        if (item->m_Name == itemToFind->m_Name) {
            return true;
        }
    }
    return false;
}
