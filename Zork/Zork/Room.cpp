#include "Room.h"
#include "Exit.h"
#include <list>
#include <iostream>
#include <vector>
using namespace std;

Room::~Room() {

}

void Room::Look() {
    for (auto entity : m_ContainedEntities) {
        entity->Look();
    }
}

Exit* Room::GetExit(const string& orientation) {
    for (Entity* entity : m_ContainedEntities) {
        if (entity->m_Type == entityType::EXIT) {
            Exit* ex = (Exit*) entity;
            if (ex->GetExitDirection() == orientation)
                return ex;
        }
    }
    return nullptr;
}
