#ifndef CAT_H
#define CAT_H
#include "Pet.h"


class Cat : public Pet {
private:
    bool isDeclawed;

public:
    Cat();

    Cat(string name, int food, int happiness, int sickness);

    void setDeclawed(bool);

    bool getDeclawed();

    // Override base virtual functions
    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    ~Cat();
};

#endif //CAT_H
