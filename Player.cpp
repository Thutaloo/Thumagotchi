#include "Player.h"

Player::Player() {
    name = "";
    badEgg = 0;
    pet = nullptr;
}

Player::Player(string name, int badEgg, Pet *pet) {
    this->name = name;
    this->badEgg = badEgg;
    this->pet = pet;
}

string Player::getName() {
    return name;
}

int Player::getBadEgg() {
    return badEgg;
}

void Player::setBadEgg(int badEgg) {
    this->badEgg = badEgg;
}

void Player::setName(string name) {
    this->name = name;
}

Player::~Player() {
    cout << "ur ded" << endl;
}
