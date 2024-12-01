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
    int badEgg;
public:
    Pet();

    Pet(string);

    Pet(string name, int food, int happiness, int sickness, int badEgg);

    void setName(string name);

    void setFood(int food);

    void setHappiness(int happiness);

    void setSickness(int sickness);

    void setBadEgg(int badEgg);

    string getName();

    int getFood();

    int getHappiness();

    int getSickness();

    int getBadEgg();

    int checkStatus();

    void printStatus();

    // Base virtual functions
    virtual string getType() = 0;

    virtual void feed(int) = 0;

    virtual void play(int) = 0;

    virtual void bathe(int) = 0;

    virtual void heal() = 0;

    virtual void badOutcome() = 0;

    virtual ~Pet();
};


#endif //PET_H
