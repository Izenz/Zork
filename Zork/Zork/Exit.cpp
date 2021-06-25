#include "Exit.h"
#include <iostream>
using namespace std;

Exit::~Exit() {

}

string Exit::GetExitDirection() const {
    return m_Direction;
}

void Exit::LockExit() {
    m_IsLocked = true;
    cout << m_Name << " is now closed." << endl;
}

void Exit::UnlockExit() {
    m_IsLocked = false;
    cout << m_Name << " is now open." << endl;
}


void Exit::Update() {

}

