#include "Item.h"
#include "Entity.h"
#include <iostream>
using namespace std;

Item::~Item() {

}

bool Item::OpenChest() {
    if (m_ItemType == itemType::CHEST) {
        cout << "Opening " << m_Name << "..." << endl;
        
        if (m_ContainedEntities.size() == 0) {
            cout << "It was empty." << endl;
        }
        else {
            for (Entity* contents : m_ContainedEntities) {
                cout << "Found: " << contents->m_Name << endl;
                m_Parent->m_ContainedEntities.push_back(contents);
            }
            m_ContainedEntities.clear();
        }
        return true;
    }
    else {
        cout << "You can not open this item." << endl;
        return false;
    }
}