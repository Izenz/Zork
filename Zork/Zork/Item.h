#pragma once
#include <vector>
#include <string>
#include "Entity.h"
using namespace std;

enum class itemType {
    CHEST,
    KEY,
    OBJECT,
    GEAR
};

class Item : public Entity {
public:
    Item(const string& name, const string& desc, Entity* parent, itemType type) : m_ItemType(type), Entity(name, desc, entityType::ITEM, parent) {};
    ~Item();

    bool OpenChest();
    bool UseKey() const;

    itemType m_ItemType;
private:
};
