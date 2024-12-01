#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Pet.h"
using namespace std;

class Player {
private:
    Pet *pet;

public:
    Player();

    Player(Pet *);

    void printGoodEgg();

    void printBadEgg();

    ~Player();
};

#endif //PLAYER_H
