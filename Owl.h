#ifndef OWL_H
#define OWL_H
#include "Pet.h"

class Owl : public Pet {
private:
    bool owlsEye;

public:
    Owl();

    Owl(string name);

    Owl(string name, int food, int happiness, int sickness, int bagEgg);

    void setOwlsEye(bool);

    bool getOwlsEye();

    // Override base virtual functions
    string getType();

    void feed(int);

    void play(int);

    void bathe(int);

    void heal();

    void badOutcome();

    ~Owl();
};

#endif //OWL_H
