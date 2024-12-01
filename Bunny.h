#ifndef BUNNY_H
#define BUNNY_H
#include "Pet.h"


class Bunny : public Pet {
private:
    bool rabbitsFoot;

public:
    Bunny();

    Bunny(string name);

    Bunny(string name, int food, int happiness, int sickness, int badEgg);

    void setRabbitsFoot(bool);

    bool getRabbitsFoot();

    // Override base virtual functions
    string getType();

    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    void badOutcome();

    ~Bunny();
};

#endif //BUNNY_H
