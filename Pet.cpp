#include "Pet.h"

Pet::Pet() {
    name = "";
    food = 2;
    happiness = 2;
    sickness = 0;
    badEgg = 0;
}

Pet::Pet(string name) {
    this->name = name;
    food = 2;
    happiness = 2;
    sickness = 0;
    badEgg = 0;
}

Pet::Pet(string name, int food, int happiness, int sickness, int badEgg) {
    this->name = name;
    this->food = food;
    this->happiness = happiness;
    this->sickness = sickness;
    this->badEgg = badEgg;
}

void Pet::setName(string name) {
    this->name = name;
}

void Pet::setFood(int food) {
    if (food <= 0) {
        cout << name << " is starving." << endl;
        this->food = 0;
    } else if (food >= 5) {
        cout << name << " is full." << endl;
        this->food = 5;
    } else {
        this->food = food;
    }
}

void Pet::setHappiness(int happiness) {
    if (happiness <= 0) {
        cout << name << " is really unhappy." << endl;
        this->happiness = 0;
    } else if (happiness >= 5) {
        cout << name << " is glowing with happiness." << endl;
        this->happiness = 5;
    } else {
        this->happiness = happiness;
    }
}

void Pet::setSickness(int sickness) {
    if (sickness <= 0) {
        cout << name << " is super healthy." << endl;
        this->sickness = 0;
    } else if (sickness >= 5) {
        cout << name << " is really sick. Please administer medicine." << endl;
        this->sickness = 5;
    } else {
        this->sickness = sickness;
    }
}

void Pet::setBadEgg(int badEgg) {
    if (badEgg <= 0) {
        this->badEgg = 0;
    } else if (badEgg >= 5) {
        this->badEgg = 5;
    } else {
        this->badEgg = badEgg;
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

int Pet::getBadEgg() {
    return badEgg;
}

int Pet::checkStatus() {
    int status;
    if (food == 5 && happiness == 5 && sickness == 0) {
        if (badEgg == 0) {
            status = 1;
        } else {
            status = 2;
        }
    } else if (food == 0 && happiness == 0 && sickness == 5) {
        status = 3;
    } else {
        status = 4;
    }

    return status;
}
void Pet::printStatus() {
    cout << name << "'s status - Food: " << food << " | Happiness: " << happiness <<
            " | Sickness: " << sickness << endl;
    cout << "Player's status - Bad Egg: " << badEgg << endl;
}

Pet::~Pet() {
    cout << "(Game Over)" << endl;
}
