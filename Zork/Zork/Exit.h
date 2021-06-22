#include "Entity.h"
class Room;
using namespace std;

class Exit : public Entity {
public:
private:
	enum m_Direction
	{
		North,
		East,
		West,
		South
	};
	Room* m_Source;
	Room* m_Destination;
};