#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

class Pet {
private:
    string name;
    int food;
    int happiness;
    int sickness;

public:
    Pet();

    Pet(string name, int food, int happiness, int sickness);

    void setName(string name);

    void setFood(int food);

    void setHappiness(int happiness);

    void setSickness(int sickness);

    string getName();

    int getFood();

    int getHappiness();

    int getSickness();

    // Base virtual functions
    virtual void feed(int) = 0;

    virtual void play(int) =0;

    virtual void bathe(int) =0;

    virtual void heal() =0;

    virtual void printStatus() =0;

    virtual ~Pet();
};


#endif //PET_H
