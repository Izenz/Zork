#include <list>

class Entity;

using namespace std;

class World {
public:
private:
    list<Entity*> m_Entities;
};