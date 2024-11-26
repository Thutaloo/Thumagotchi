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

    Player(string);

    string getName();

    int getBadEgg();

    Pet *getPet();

    void setBadEgg(int);

    void setName(string);

    void setPet(Pet *);

    ~Player();
};

#endif //PLAYER_H
