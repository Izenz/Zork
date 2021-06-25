#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
using namespace std;

World::World() {

    // Rooms
    Room* mountains = new Room("Mountain Range", "Up in the mountains you leave behind a magnificent view of the meadow and what seems to be a small house past it.\nYou keep exploring the mountains and you see a cave to the north.\nInside the cave you see a huge, ancient door. It's locked.");
    Room* gmeadow = new Room("Green Meadow", "A green meadow extends before you under the blue sky.\nYou see a muddy road to the west and the mountains far on the east");
    Room* lhouse = new Room("Lonely House", "An old house. It looks abandoned and the door is opened.\nYou go in and see old furniture covered in webs, and a small chest that has no lock.\nThere are stairs leading below the house to your left.");
    Room* gbasement = new Room("Gloomy Basement", "It's the basement of the house. There are no windows and the only light is the one coming from the door in the floor above.\nYou can barely see anything but you see something that resembles a key hanging from the wall in front of you.");
    Room* sdungeon = new Room("Secret Dungeon", "After opening the door you see a stair made of stones going down into pitch black darkness.\nYou dont have anything to light the way but you still decide to go down slowly.\nAfter a moment you start to see a light in front of you, you reach a room where the light falls from a hole in the ceiling.\n You take a look around you and you see piles of gold and jewels! you found a treasure!.");

    m_Entities.push_back(mountains);
    m_Entities.push_back(gmeadow);
    m_Entities.push_back(lhouse);
    m_Entities.push_back(gbasement);
    m_Entities.push_back(sdungeon);

    // Exits & Keys
    Exit* mountToMeadow = new Exit("Mountain path", "A path going up the mountains, it's going to be a long walk...", mountains, gmeadow, "east", mountains, false, nullptr);
    Exit* meadowToMount = new Exit("Mountain path", "A path going up the mountains, it's going to be a long walk...", gmeadow, mountains, "west", gmeadow, false, nullptr);

    Exit* meadowToHouse = new Exit("Muddy road", "A muddy road, looks like it rained not long ago.", gmeadow, lhouse, "east", gmeadow, false, nullptr);
    Exit* houseToMeadow = new Exit("Muddy road", "A muddy road, looks like it rained not long ago.", lhouse, gmeadow, "west", lhouse, false, nullptr);

    Exit* houseToBasem = new Exit("House stairs", "Stairs going down", lhouse, gbasement, "north", lhouse, false, nullptr);
    Exit* basemToHouse = new Exit("House stairs", "Stairs going down", gbasement, lhouse, "south", gbasement, false, nullptr);

    Item* dungeonKey = new Item("Key", "It looks old and is heavy.", gbasement, itemType::KEY);

    Exit* mountToDung = new Exit("Mountain cave", "A small cave with a huge door made of stone.", mountains, sdungeon, "north", mountains, true, dungeonKey);
    Exit* DungToMount = new Exit("Mountain cave", "A small cave with a huge door made of stone.", sdungeon, mountains, "south", sdungeon, false, dungeonKey);

    // Items
    Item* woodenChest = new Item("Chest", "It's a chest made of wood, it is not locked.", lhouse, itemType::CHEST);

    Item* welcomeRing = new Item("Ring", "It's a silver ring.", woodenChest, itemType::GEAR);
    Item* silverCoin = new Item("Coin", "It's a coin made of silver.", woodenChest, itemType::OBJECT);

    // Creatures
    m_Player = new Player("Treasure hunter", "Looking for treasure and adventure!", gmeadow);
    m_Entities.push_back(m_Player);
}

World::~World() {
    /*for (Entity* entity : m_Entities) {
        delete entity;
    }
    m_Entities.clear();*/
}

bool World::ExecuteCommand(const vector<string>& command){

    switch (command.size()) {
    case 1:
        if (!_stricmp(command[0].c_str(), "look")) {
            m_Player->Look();
        }
        else if (!_stricmp(command[0].c_str(), "inventory")) {
            m_Player->ShowInventory();
        }
        else if (!_stricmp(command[0].c_str(), "quit")) {
            return false;
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
                cout << " You didn't move." << endl;
            }
        }
        else if (!_stricmp(command[0].c_str(), "look")) {
            if (m_Player->Look(command)) {}
            else
                cout << "You don't see anything like that around." << endl;
        }
        else if (!_stricmp(command[0].c_str(), "drop")) {
            if (m_Player->Drop(command)) {
                cout << "Dropped. " << endl;
            }
            else {
                cout << "You dont have that item in you." << endl;
            }
        }
        else if (!_stricmp(command[0].c_str(), "take")) {
            if (m_Player->Take(command)) {
                cout << "Taken." << endl;
            }
            else {
                cout << "Such item does not exist in this room." << endl;
            }
        }
        else if (!_stricmp(command[0].c_str(), "open")) {
            if (m_Player->Open(command)) {
            }
            else {
                cout << "You dont have that item in you." << endl;
            }
        }
        else if (!_stricmp(command[0].c_str(), "lock")) {
            if (m_Player->Lock(command)) {}
        }
        else if (!_stricmp(command[0].c_str(), "unlock")) {
            if (m_Player->Unlock(command)) {}
        }
        else {
            cout << "I did not understand that command." << endl;
        }
        break;
    case 4:
        if ((!_stricmp(command[0].c_str(), "store") && (!_stricmp(command[2].c_str(), "in")))) {
            if (m_Player->Store(command)) {}
            else {
                cout << "You can not do that." << endl;
            }
        }
        break;
    default:
        cout << "I did not understand that." << endl;
        break;
    }

    return true;
}