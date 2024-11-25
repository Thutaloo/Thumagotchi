#include "Bunny.h"

Bunny::Bunny() : Pet() {
    this->fluffy = 0;
}

Bunny::Bunny(string name, int food, int happiness, int sickness, int fluffy) : Pet(name, food, happiness, sickness) {
    this->fluffy = fluffy;
}

void Bunny::setFluffy(int fluffy) {
    if (this->fluffy + fluffy < 0) {
        this->fluffy = 0;
    } else if (this->fluffy + fluffy > 5) {
        this->fluffy = 5;
    } else {
        this->fluffy = this->fluffy + fluffy;
    }
}

int Bunny::getFluffy() {
    return this->fluffy;
}

// Override base virtual functions
void Bunny::feed(int option) {
    if (option == 1) {
        cout << "Feeding " << getName() << " a carrot. Tasty, but not very nutritious." << endl;
        setFood(getFood() + 1);
        setHappiness(getHappiness() + 2);
    } else if (option == 2) {
        cout << "Feeding " << getName() << " some spring mix. Delicious and nutritious!" << endl;
        setFood(getFood() + 2);
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Feeding " << getName() << " some meat. Wait, that doesn't seem right..." << endl;
        setSickness(getSickness() + 2);
    } else {
        cout << "This doesn't look like food..." << endl;
    }
}

void Bunny::play(int option) {
    if (option == 1) {
        cout << "Giving " << getName() << " a treat ball." << endl;
        setFood(getFood() + 1);
        setHappiness(getHappiness() + 2);
    } else if (option == 2) {
        cout << "Giving " << getName() << " a foraging toy." << endl;
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "Tickling " << getName() << ". She's loving the attention." << endl;
        setHappiness(getHappiness() + 3);
    } else {
        cout << "You don't have anything like that..." << endl;
    }
}

void Bunny::bathe(int option) {
}

void Bunny::heal() {
    cout << "Giving " << getName() << " some meds. Colors are returning to her face." << endl;
    setSickness(0);
}

void Bunny::printStatus() {
    cout << getName() << "'s status - Food: " << getFood() << ". Happiness: " << getHappiness() <<
            ". Sickness: " << getSickness() << ". Fluffiness: " << fluffy << "." <<
            endl;
}

Bunny::~Bunny() {
    cout << " (\\_/)" << endl;
    cout << " (x-x)" << endl;
    cout << "C(\")(\")" << endl << endl;
}
