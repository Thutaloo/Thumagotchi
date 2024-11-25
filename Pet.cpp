#include "Pet.h"

Pet::Pet() {
    name = "";
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
    this->food = food;
}

void Pet::setHappiness(int happiness) {
    this->happiness = happiness;
}

void Pet::setSickness(int sickness) {
    this->sickness = sickness;
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
