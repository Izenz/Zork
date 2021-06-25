                                              -----------------------------------------------------
                                                                      Zork
                                              -----------------------------------------------------
Author: Joel Herraiz Martí.

This is my very simple version of Zork.

There are five connected rooms, items that can be picked up and dropped, Items that can store other items such as chests and doors that can be closed or open with the right key. The world building is very simple but all the tools to make it bigger and more complex are there. I wish I could have had time to add RPG stats to items and the player and NPCs to converse with. Maybe in future versions...

One of the things I struggled the most with were destructors since I kept getting an exception after quitting the game because I was trying to access objects that were already destroyed. It was the first time I got that kind of error so it took me a while to figure it out.

The commands available on this release are:
  - Look: Gives info of the current room.
  - Look *object name*: Gives info of named object if its within inventory or in the current room.
  - Go *direction*: Tries to move in the specified direction and moves if theres an open door.
  - Take *object name*: Tries to pick up object from the room player is in.
  - Drop *object name*: Drops item from inventory into the player's current room.
  - Open *object name*: Tries to open *object* and adds contents to player's inventory, if there are any.
  - Store *object name 1* in *object name 2*: Tries to store *object 1* in *object 2*.
  - Lock *direction*: Locks a room's exit if the player owns the right key.
  - Unlock *direction*: Unlocks a room's exit if the player owns the right key.
  - Quit: Quits the game.
  - Inventory: Lists all items in inventory.

The story of the game revolves around a treasure hunter trying to find a treasure. The five rooms are distributed like this:

          SECRET DUNGEON                               BASEMENT                                 NORTH
                |                                          |                                      |
                |                                          |                           WEST <-----|------> EAST
                |                                          |                                      |
            MOUNTAINS -------------- MEADOW ------------ HOUSE                                  SOUTH


The Exit to the Secret dungeon is locked, to unlock it the "Key" hidden in the Gloomy Basement is needed.
The main path to win the game would be as follows:
  1. Go East
  2. Go North
  3. Take Key
  4. Go South
  5. Go West
  6. Go West
  7. Unlock North
  8. Go North

There's also a "Chest" that can be taken inside the house. It can be opened to retrieve the two items inside it: a "Ring" and a "Coin". Some items like the ring and the coin do not have use currently and exist solely to ilustrate the usage of chests and other commands.

So the list of items that can be found in the world of this release are:
  - Chest
  - Key
  - Ring (inside Chest)
  - Coin (inside Chest)

Thanks for playing!

MIT License

Copyright (c) [year] [fullname]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
