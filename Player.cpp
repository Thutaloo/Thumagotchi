#include "Player.h"

Player::Player() {
    pet = nullptr;
}

Player::Player(Pet *pet) {
    this->pet = pet;
}

void Player::printGoodEgg() {
    // Art by Hayley Jane Wakenshaw
    cout << R"(  ,'"`.)" << endl;
    cout << R"( /     \)" << endl;
    cout << R"(:       :)" << endl;
    cout << R"(:       :)" << endl;
    cout << R"( `.___,')" << endl;
}

void Player::printBadEgg() {
    cout << R"(                       _____________________)" << endl;
    cout << R"(    /  .       .      (<$$$$$$>#####<::::::>))" << endl;
    cout << R"(   .      .     .  _/~~~~~~~~~~~~~~~~~~~~~~~~~\_   .       .   .   \)" << endl;
    cout << R"(.(          . .  /~                             ~\ . .   .)" << endl;
    cout << R"(  ( . .        .~                                 ~.      .         ))" << endl;
    cout << R"(           ()\/_____                           _____\/()   .    .  ).)" << endl;
    cout << R"((         .-''      ~~~~~~~~~~~~~~~~~~~~~~~~~~~     ``-.  ...)" << endl;
    cout << R"(.  . . .-~              __________________              ~-.  .    /)" << endl;
    cout << R"( .   ..`~~/~~~~~~~~~~~~TTTTTTTTTTTTTTTTTTTT~~~~~~~~~~~~\~~'    . ) .)" << endl;
    cout << R"(    . .| | | #### #### || | | | [] | | | || #### #### | | | .)" << endl;
    cout << R"(   (   ;__\|___________|++++++++++++++++++|___________|/__;.   .)" << endl;
    cout << R"(     .  (~~====___________________________________====~~~))" << endl;
    cout << R"( ( .  .. \------_____________[ POLICE ]__________-------/ ..  .     ))" << endl;
    cout << R"(         .  |      ||         ~~~~~~~~       ||      |)" << endl;
    cout << R"(             \_____/                          \_____/)" << endl << endl;
    cout << "You attempted to do a terrible thing to " << pet->getName() << "." << endl <<
            "You were reported to the police, and they've taken " << pet->getName() <<
            " to a shelter. You got arrested." << endl;
    exit(0);
}

Player::~Player() = default;
