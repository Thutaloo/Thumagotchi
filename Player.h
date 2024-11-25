#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int badEgg;
public:
    Player();
    Player(string);
    string getName();
    int getBadEgg();
    void setBadEgg(int);
    void setName(string);
};

#endif //PLAYER_H
