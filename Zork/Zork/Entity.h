#pragma once
#include <string>
#include <list>
using namespace std;

enum class entityType {
    ENTITY,
    CREATURE,
    EXIT,
    ROOM,
    ITEM,
    NPC,
    PLAYER
};

class Entity {

public:
    Entity(const string& name, const string& description, entityType type) : m_Name(name), m_Description(description), m_Type(type), m_Parent(nullptr) {};
    Entity(const string& name, const string& description, entityType type, Entity* parent);
    ~Entity();

    virtual void Look() const;
    virtual void Open();
    virtual void Take();
    virtual void Drop();
    virtual void Put(Entity* container);
    virtual void Talk();
    virtual void Attack();
    virtual void Go();

    Entity* Find(const string& name) const;
    Entity* Find(const string& name, entityType type) const;
    void FindAll(const entityType type, list<Entity*>& entitiesFound) const;
    void ChangeParent(Entity* new_parent);
    virtual void Update();

    string m_Name;
    string m_Description;
    entityType m_Type;
    list<Entity*> m_ContainedEntities;
    Entity* m_Parent;

};
