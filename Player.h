#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Pet.h"
using namespace std;

class Player {
private:
    string name;
    int badEgg;
    Pet *pet;

public:
    Player();

    Player(string, int, Pet*);

    string getName();

    int getBadEgg();

    void setBadEgg(int);

    void setName(string);

    ~Player();
};

#endif //PLAYER_H
