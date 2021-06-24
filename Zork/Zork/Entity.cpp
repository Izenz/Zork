#include "Entity.h"
#include <iostream>
using namespace std;

Entity::Entity(const string& name, const string& description, entityType type, Entity* parent) {
    m_Name = name;
    m_Description = description;
    m_Type = type;
    ChangeParent(parent);
}

Entity::~Entity() {
    for (auto entity : m_ContainedEntities) {
        delete(entity);
    }
}

Entity* Entity::Find(const string& name)  const {
    for (Entity* entity : m_ContainedEntities) {
        if (!_stricmp(entity->m_Name.c_str(), name.c_str()))
            return entity;
    }
    return nullptr;
}

Entity* Entity::Find(const string& name, const entityType type)  const {
    for (Entity* entity : m_ContainedEntities) {
        if (entity->m_Type == type) {
            if (!_stricmp(entity->m_Name.c_str(), name.c_str()))
                return entity;
        }
    }
    return nullptr;
}

void Entity::FindAll(const entityType type, list<Entity*>& entitiesFound) const {
    for (Entity* entity : entitiesFound) {
        if (entity->m_Type == type) {
            entitiesFound.push_back(entity);
        }
    }
}

void Entity::ChangeParent(Entity* new_parent) {
    if (new_parent != NULL) {
        if(m_Parent != NULL)
            m_Parent->m_ContainedEntities.remove(this);
        m_Parent = new_parent;
        m_Parent->m_ContainedEntities.push_back(this);
    }
    
}

void Entity::Update() {

}

void Entity::Look() const {
    cout << "You can not look at " << m_Name << endl;
}

void Entity::Open() {
    cout << "You can not open " << m_Name << endl;
}

void Entity::Take() {
    cout << "You can not take " << m_Name << endl;
}

void Entity::Drop() {
    cout << "You can not drop " << m_Name << endl;
}

void Entity::Put(Entity* container) {
    cout << "You can not put " << m_Name << "into " << container->m_Name << endl;
}

void Entity::Talk() {
    cout << "You can not talk to " << m_Name << endl;
}

void Entity::Attack() {
    cout << "You can not attack " << m_Name << endl;
}

void Entity::Go() {
    cout << "You can not go to " << m_Name << endl;
}

