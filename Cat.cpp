#include "Cat.h"

Cat::Cat() : Pet("Wilbur", 0, 0, 0) {
    this->isDeclawed = false;
}

Cat::Cat(string name, int food, int happiness, int sickness) : Pet(name, food, happiness, sickness) {
    this->isDeclawed = false;
}

void Cat::setDeclawed(bool isDeclawed) {
    this->isDeclawed = isDeclawed;
}

bool Cat::getDeclawed() {
    return this->isDeclawed;
}

// Override base virtual functions
void Cat::feed(int option) {
    if (option == 1) {
        cout << "Feeding " << getName() << " some kibble. He munches on a few." << endl;
        setFood(getFood() + 1);
    } else if (option == 2) {
        cout << "Feeding " << getName() << " a canned food. He goes nuts for it!" << endl;
        setFood(getFood() + 2);
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Feeding " << getName() << " some veggies. He looks at you with disdain and swipes at you." << endl;
        setFood(getFood() + 1);
        // Scratch
    } else {
        cout << "This doesn't look like food..." << endl;
    }
}

// TODO: Scratch
void Cat::play(int option) {
    if (option == 1) {
        cout << "Giving " << getName() << " a feather wand. He's curious, but not that into it." << endl;
        setHappiness(getHappiness() + 1);
    } else if (option == 2) {
        cout << "Giving " << getName() << " a mouse toy. He loves it!" << endl;
        setHappiness(getHappiness() + 3);
    } else if (option == 3) {
        cout << "You try to tickle " << getName() << "'s tummy. You immediately got scratched." << endl;
        setHappiness(getHappiness() - 1);
        // Scratch
    } else {
        cout << "You don't have anything like that..." << endl;
    }
}

// TODO: add functionality for badEgg
void Cat::bathe(int option) {
    if (option == 1) {
        cout << "You gave " << getName() <<
                " a cold bath. The water touched his paw and he immediately scratched you and ran away." << endl;
        setHappiness(getHappiness() - 3);
        // Scratch
    } else if (option == 2) {
        cout << "You gave " << getName() << " a warm bath. He begrudgingly stayed in the tub and shot you death glares."
                << endl;
    } else {
        cout << "???" << endl;
    }
}

void Cat::heal() {
    cout << "Giving " << getName() << " some meds. He ran right back to his cat tree." << endl;
    setHappiness(getHappiness() - 1);
    setSickness(0);
}

void Cat::printStatus() {
    cout << getName() << "'s status - Food: " << getFood() << ". Happiness: " << getHappiness() <<
            ". Sickness: " << getSickness() << "." << endl;
}

Cat::~Cat() {
    cout << "/\\___/\\" << endl;
    cout << "(>x_x<)" << endl;
    cout << "(\")(\")_/" << endl << endl;
}
