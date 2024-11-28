#ifndef OWL_H
#define OWL_H
#include "Pet.h"


class Owl : public Pet {
private:
    bool owlsEye;

public:
    Owl();

    Owl(string name, int food, int happiness, int sickness);

    void setOwlsEye(bool);

    bool getOwlsEye();

    // Override base virtual functions
    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    ~Owl();
};

#endif //OWL_H
