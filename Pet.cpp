#include "Pet.h"

Pet::Pet() {
    name = "";
    food = 0;
    happiness = 0;
    sickness = 0;
}

Pet::Pet(string name) {
    this->name = name;
    food = 0;
    happiness = 0;
    sickness = 0;
}

Pet::Pet(string name, int food, int happiness, int sickness) {
    this->name = name;
    this->food = food;
    this->happiness = happiness;
    this->sickness = sickness;
}

void Pet::setName(string name) {
    this->name = name;
}

void Pet::setFood(int food) {
    if (this->food + food < 0) {
        cout << name << " is starving." << endl;
        this->food = 0;
    } else if (this->food + food > 5) {
        cout << name << " is full." << endl;
        this->food = 5;
    } else {
        this->food = this->food + food;
    }
}

void Pet::setHappiness(int happiness) {
    if (this->happiness + happiness < 0) {
        cout << name << " is really unhappy." << endl;
        this->happiness = 0;
    } else if (this->happiness + happiness > 5) {
        cout << name << " is glowing with happiness." << endl;
        this->happiness = 5;
    } else {
        this->happiness = this->happiness + happiness;
    }
}

void Pet::setSickness(int sickness) {
    if (this->sickness + sickness < 0) {
        cout << name << " is super healthy." << endl;
        this->sickness = 0;
    } else if (this->sickness + sickness > 5) {
        cout << name << " is really sick. Please administer medicine." << endl;
        this->sickness = 5;
    } else {
        this->sickness = this->sickness + sickness;
    }
}

string Pet::getName() {
    return name;
}

int Pet::getFood() {
    return food;
}

int Pet::getHappiness() {
    return happiness;
}

int Pet::getSickness() {
    return sickness;
}

void Pet::printStatus() {
    cout << name << "'s status - Food: " << food << ". Happiness: " << happiness <<
            ". Sickness: " << sickness << "." << endl;
}

Pet::~Pet() {
    cout << "        ." << endl;
    cout << "       -|-" << endl;
    cout << "        |" << endl;
    cout << "    .-'~~~`-." << endl;
    cout << "  .'         `." << endl;
    cout << "  |  R  I  P  |" << endl;
    cout << "  |           |" << endl;
    cout << "  |           |  " << endl;
    cout << "\\|           |//" << endl << endl;
}
