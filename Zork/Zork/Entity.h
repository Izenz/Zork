
#include <string>
#include <list>
using namespace std;

class Entity {
    protected:
        string m_Name;
        string m_Description;
        list<Entity*> m_Contains;
    private:
        virtual void Update();
};
