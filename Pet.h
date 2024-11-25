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
};


#endif //PET_H
