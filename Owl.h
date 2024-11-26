#ifndef OWL_H
#define OWL_H
#include "Pet.h"


class Owl : public Pet {
private:
public:
    Owl();

    Owl(string name, int food, int happiness, int sickness);

    // Override base virtual functions
    void feed(int);

    void play(int);

    void bathe(int);

    void fluff();

    void heal();

    void printStatus();

    ~Owl();
};

#endif //OWL_H
