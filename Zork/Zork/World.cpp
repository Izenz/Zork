#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include <iostream>
using namespace std;

World::World() {
    int playerHp = 20, playerAtk = 5;

    // Rooms
    Room* mountains = new Room("Mountain Range", "desc");
    Room* gmeadow = new Room("Green Meadow", "desc");
    Room* lhouse = new Room("Lonely House", "desc");
    Room* gbasement = new Room("Gloomy Basement", "desc");
    Room* sdungeon = new Room("Secret Dungeon", "desc");

    m_Entities.push_back(mountains);
    m_Entities.push_back(gmeadow);
    m_Entities.push_back(lhouse);
    m_Entities.push_back(gbasement);
    m_Entities.push_back(sdungeon);

    // Exits
    Exit* mountToMeadow = new Exit("Mountain path", "asd", mountains, gmeadow, "east", mountains);
    Exit* meadowToMount = new Exit("Mountain path", "", gmeadow, mountains, "west", gmeadow);

    Exit* meadowToHouse = new Exit("Muddy road", "asd", gmeadow, lhouse, "east", gmeadow);
    Exit* houseToMeadow = new Exit("Muddy road", "", lhouse, gmeadow, "west", lhouse);

    Exit* houseToBasem = new Exit("House stairs", "asd", lhouse, gbasement, "north", lhouse);
    Exit* basemToHouse = new Exit("House stairs", "", gbasement, lhouse, "south", gbasement);

    Exit* mountToDung = new Exit("Mountain cave", "asd", mountains, sdungeon, "north", mountains);
    Exit* DungToMount = new Exit("Mountain cave", "", sdungeon, mountains, "south", sdungeon);

    // Items

    // Creatures
    m_Player = new Player("", "", gmeadow, playerHp, playerAtk);
    m_Entities.push_back(m_Player);
}

World::~World() {
    for (Entity* entity : m_Entities) {
        delete entity;
    }
    m_Entities.clear();
}

void World::ExecuteCommand(const vector<string>& command){
    switch (command.size()) {
    case 1:
        if (!_stricmp(command[0].c_str(), "look")) {
            m_Player->Look();
        }
        else if (!_stricmp(command[0].c_str(), "inventory")) {
            m_Player->ShowInventory();
        }
        else {
            cout << "Try to be more specific." << endl;
        }
        break;
    case 2:
        if (!_stricmp(command[0].c_str(), "go")) {
            if (m_Player->Go(command)) {
                cout << "You traveled to: " << m_Player->m_CurrentLocation->m_Name << endl;
                cout << m_Player->m_CurrentLocation->m_Description << endl;
            }
            else {
                cout << "There's nothing there." << endl;
            }
        }
        else if (!_stricmp(command[0].c_str(), "look")) {
            m_Player->Look(command);
        }
        else if (!_stricmp(command[0].c_str(), "drop")) {
            m_Player->Drop(command);
        }
        else if (!_stricmp(command[0].c_str(), "take")) {
            m_Player->Take(command);
        }
        else {
            cout << "Did you say anything?." << endl;
        }
        break;
    default:
        cout << "I did not understand that." << endl;
    }
}