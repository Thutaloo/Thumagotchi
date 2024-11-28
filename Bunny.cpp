#include "Bunny.h"

Bunny::Bunny() : Pet("Swifty", 0, 0, 0) {
    this->rabbitsFoot = false;
}

Bunny::Bunny(string name, int food, int happiness, int sickness) : Pet(name, food, happiness, sickness) {
    this->rabbitsFoot = false;
}

void Bunny::setRabbitsFoot(bool rabbitsFoot) {
    this->rabbitsFoot = rabbitsFoot;
}
bool Bunny::getRabbitsFoot() {
    return this->rabbitsFoot;
}

// Override base virtual functions
void Bunny::feed(int option) {
    if (option == 1) {
        cout << "Feeding " << getName() << " a carrot. Tasty, but not very nutritious." << endl;
        setFood(getFood() + 1);
        setHappiness(getHappiness() + 2);
    } else if (option == 2) {
        cout << "Feeding " << getName() << " some spring mix. Her favorite!" << endl;
        setFood(getFood() + 2);
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Feeding " << getName() << " some meat. She got sick.." << endl;
        setSickness(getSickness() + 2);
    } else {
        cout << "This doesn't look like food..." << endl;
    }
}

void Bunny::play(int option) {
    if (option == 1) {
        cout << "Giving " << getName() << " a treat ball. She loves the treats!" << endl;
        setFood(getFood() + 1);
        setHappiness(getHappiness() + 2);
    } else if (option == 2) {
        cout << "Giving " << getName() << " a foraging toy. She seems happy." << endl;
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Tickling " << getName() << ". She's loving the attention." << endl;
        setHappiness(getHappiness() + 3);
    } else {
        cout << "You don't have anything like that..." << endl;
    }
}

// TODO: add functionality for badEgg
void Bunny::bathe(int option) {
    if (option == 1 || option == 2) {
        cout << "You gave " << getName() << " a bath. It stressed her out." << endl;
        setHappiness(getHappiness() - 3);
        setSickness(getSickness() + 2);
        // Bite
    } else {
        cout << "???" << endl;
    }
}

void Bunny::heal() {
    cout << "Giving " << getName() << " some meds. She starts hopping around again." << endl;
    setSickness(0);
}

Bunny::~Bunny() {
    cout << " (\\_/)" << endl;
    cout << " (x-x)" << endl;
    cout << "C(\")(\")" << endl << endl;
}
