#ifndef BUNNY_H
#define BUNNY_H
#include "Pet.h"


class Bunny : public Pet {
private:
    int fluffy;

public:
    Bunny();

    Bunny(string name, int food, int happiness, int sickness, int fluffy);

    void setFluffy(int fluffy);

    int getFluffy();

    // Override base virtual functions
    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    void printStatus();

    ~Bunny();
};

#endif //BUNNY_H
