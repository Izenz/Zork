#include <iostream>
#include "World.h"
#include "Utils.h"
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    World world;
    string playerInput;
    vector<string> command;
    command.reserve(5);

    cout << "Welcome to Zork!" << endl;
    command.push_back("look");
    world.ExecuteCommand(command);


    while (true)
    {
        playerInput.clear();
        command.clear();

        cout << "> ";
        getline(cin, playerInput);

        for_each(playerInput.begin(), playerInput.end(), [](char& c) {
            c = tolower(c);
        });

        Tokenize(playerInput, command);

        world.ExecuteCommand(command);
    }

}

