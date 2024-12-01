#ifndef CAT_H
#define CAT_H
#include "Pet.h"


class Cat : public Pet {
private:
    bool isDeclawed;

public:
    Cat();

    Cat(string name);

    Cat(string name, int food, int happiness, int sickness, int badEgg);

    void setDeclawed(bool);

    bool getDeclawed();

    // Override base virtual functions
    string getType();

    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    void badOutcome();

    ~Cat();
};

#endif //CAT_H
