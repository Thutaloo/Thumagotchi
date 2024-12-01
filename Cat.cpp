#include "Cat.h"

Cat::Cat() : Pet("Wilbur", 2, 2, 0, 0) {
    this->isDeclawed = false;
}

Cat::Cat(string name) : Pet(name, 2, 2, 0, 0) {
    this->isDeclawed = false;
}

Cat::Cat(string name, int food, int happiness, int sickness, int badEgg) : Pet(name, food, happiness, sickness, badEgg) {
    this->isDeclawed = false;
}

void Cat::setDeclawed(bool isDeclawed) {
    this->isDeclawed = isDeclawed;
}

bool Cat::getDeclawed() {
    return this->isDeclawed;
}

// Override base virtual functions
string Cat::getType() {
    return "Cat";
}

void Cat::feed(int option) {
    if (option == 1) {
        cout << "Feeding " << getName() << " some kibble. He munches on a few." << endl;
        setFood(getFood() + 1);
    } else if (option == 2) {
        cout << "Feeding " << getName() << " some canned food. He goes nuts for it!" << endl;
        setFood(getFood() + 2);
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Feeding " << getName() << " some veggies. He looks at you with disdain and swipes at you." << endl;
        setFood(getFood() + 1);
        setBadEgg(getBadEgg() + 1);
    } else {
        cout << "This doesn't look like food..." << endl;
    }
}

void Cat::play(int option) {
    if (option == 1) {
        cout << "Giving " << getName() << " a feather wand. He's curious, but not that into it." << endl;
        setFood(getFood() - 1);
        setHappiness(getHappiness() + 1);
    } else if (option == 2) {
        cout << "Giving " << getName() << " a mouse toy. He loves it!" << endl;
        setFood(getFood() - 1);
        setHappiness(getHappiness() + 3);
    } else if (option == 3) {
        cout << "You try to tickle " << getName() << "'s tummy. You immediately got scratched." << endl;
        setHappiness(getHappiness() - 1);
        setBadEgg(getBadEgg() + 1);
    } else {
        cout << "You don't have anything like that..." << endl;
    }
}

void Cat::bathe(int option) {
    if (option == 1) {
        cout << "You gave " << getName() <<
                " a cold bath. The water touched his paw and he immediately scratched you and ran away." << endl;
        setHappiness(getHappiness() - 3);
        setBadEgg(getBadEgg() + 2);
    } else if (option == 2) {
        cout << "You gave " << getName() << " a warm bath. He begrudgingly stayed in the tub and shot you death glares."
                << endl;
    } else {
        cout << "???" << endl;
    }
}

void Cat::heal() {
    cout << "Giving " << getName() << " some meds. He ran right back to his cat tree." << endl;
    setHappiness(getHappiness() - 2);
    setSickness(0);
}

void Cat::badOutcome() {
    this->isDeclawed = true;
}

Cat::~Cat() = default;
