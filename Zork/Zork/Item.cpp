#include "Item.h"
#include "Entity.h"
#include <iostream>
using namespace std;

Item::~Item() {

}

bool Item::OpenChest() {
    if (m_ItemType == itemType::CHEST) {
        for (auto contents : m_ContainedEntities) {
            cout << "Found: " << contents->m_Name << endl;
            contents->ChangeParent(m_Parent);
        }
        return true;
    }
    else {
        return false;
    }
}

bool Item::UseKey() const {
    return true;
}