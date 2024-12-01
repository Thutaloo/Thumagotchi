#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "Bunny.h"
#include "Cat.h"
#include "Owl.h"
#include "Player.h"

using namespace std;

// For generating password
const int RDSTRING_MAX_LENGTH = 10;
const string RDSTRING = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!*#%@";
// Defining specific save file
const string FILE_NAME = "Thumagotchi.txt";

// Functions declaration
// Draws a line (e.g., for visual separation in menus or outputs).
void Line();

// Generates a random alphanumeric string of the length 10 to use as password
string generateRandomString(int length);

// Loads the saved game state from a file and returns a pointer to the loaded Pet object
Pet *LoadGame();

// Saves the current game state to a file.
void SaveGame(Pet *pet);

// Displays the start menu options to the player
void StartMenu();

// Starts a new game by initializing a new Pet object and returning it to the caller
Pet *NewGame();

// Creates a new Pet object based on the player's choice of Pet type
Pet *CreatePet(int);

// Prompts the player for a Pet name. If no name is provided, uses the default name.
string GetPetName(string defaultName);

// Main game loop where the player interacts with the Pet and performs actions like feeding, playing, or bathing
void GamePlay(Pet *pet, Player *player);

// Feeds the Pet, increasing/decreasing its food level and possibly affecting other attributes
void Feed(Pet *pet);

// Allows the player to play with the Pet, increasing/decreasing its happiness but possibly affecting food or sickness levels
void Play(Pet *pet);

// Bathes the Pet, potentially increasing/decreasing happiness and affecting sickness
void Bathe(Pet *pet);

// Immediately ends the game with the worst outcome
void BadOutcome(Pet *pet, Player *player);

// Allows user to see what happens when they finish the game with the best outcome
void Cheat(Pet *pet);

// Not so subtle easter egg
void SomethingCool();

// Clears the input buffer for error handling
void clearInput();

// Ends the game
void EndGame();


// main()
int main() {
    cout << R"( _____                                                                     _____)" << endl;
    cout << R"(( ___ )                                                                   ( ___ ))" << endl;
    cout << R"( |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | )" << endl;
    cout << R"( |   |       __        __   _                            _                 |   | )" << endl;
    cout << R"( |   |       \ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___           |   | )" << endl;
    cout << R"( |   |        \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \          |   | )" << endl;
    cout << R"( |   |         \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |         |   | )" << endl;
    cout << R"( |   |          \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/          |   | )" << endl;
    cout << R"( |   |  _____ _                                       _       _     _   _  |   | )" << endl;
    cout << R"( |   | |_   _| |__  _   _ _ __ ___   __ _  __ _  ___ | |_ ___| |__ (_) | | |   | )" << endl;
    cout << R"( |   |   | | | '_ \| | | | '_ ` _ \ / _` |/ _` |/ _ \| __/ __| '_ \| | | | |   | )" << endl;
    cout << R"( |   |   | | | | | | |_| | | | | | | (_| | (_| | (_) | || (__| | | | | |_| |   | )" << endl;
    cout << R"( |   |   |_| |_| |_|\__,_|_| |_| |_|\__,_|\__, |\___/ \__\___|_| |_|_| (_) |   | )" << endl;
    cout << R"( |   |                                    |___/                            |   | )" << endl;
    cout << R"( |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| )" << endl;
    cout << R"((_____)                                                                   (_____))" << endl
            << endl;

    StartMenu();
    return 0;
}

// Functions implementation
void Line() {
    cout << ">>=================================================================================================<<" <<
            endl;
}

string generateRandomString() {
    string randomString = "";
    int charsLength = RDSTRING.size();

    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < RDSTRING_MAX_LENGTH; i++) {
        randomString += RDSTRING[rand() % charsLength];
    }

    return randomString;
}

Pet *LoadGame() {
    Pet *pet;
    string line, name, type, password;
    int food, happiness, sickness, badEgg, count = 0;

    ifstream file(FILE_NAME);

    // Checks if file is opened correctly
    if (!file.is_open()) {
        cerr << "Error opening file " << FILE_NAME << endl;
        exit(1);
    }
    cout << "Please enter the password to your saved game: ";
    cin >> password;

    // Get file input based on name
    while (getline(file, line)) {
        if (line == password) {
            count++;
            getline(file, name);
            getline(file, type);
            file >> food >> happiness >> sickness >> badEgg;
            break;
        }
    }

    if (count == 0) {
        cout << "That save does not exist. Did you forget your password?" << endl;
        StartMenu();
    }

    // Create pet based on type
    if (type == "Bunny") {
        pet = new Bunny(name, food, happiness, sickness, badEgg);
    } else if (type == "Cat") {
        pet = new Cat(name, food, happiness, sickness, badEgg);
    } else if (type == "Owl") {
        pet = new Owl(name, food, happiness, sickness, badEgg);
    } else {
        pet = nullptr;
    }

    pet->printStatus();

    file.close();

    return pet;
}

void SaveGame(Pet *pet) {
    string password = generateRandomString();
    ofstream file;

    file.open(FILE_NAME, ios::app);

    if (!file.is_open()) {
        cerr << "Error opening file " << FILE_NAME << endl;
        exit(1);
    }

    file << password << endl << pet->getName() << endl << pet->getType() << endl << pet->getFood() << endl << pet->
            getHappiness() << endl << pet->
            getSickness() << endl << pet->getBadEgg() << endl << endl;

    Line();
    cout << "Game saved in 'Thumagotchi.txt'. Your password for this save is: " << password << endl << endl;
    cout << "Please keep this password if you'd like to continue this save in the future." << endl <<
            "Thu is not responsible for lost passwords. You've been warned." << endl;

    file.close();
}

void StartMenu() {
    Player *player;
    Pet *pet;
    int option;

    do {
        Line();
        cout << "1. NEW GAME\n2. LOAD GAME\n3. EXIT\n4. See something cool\n";

        cout << "Select: ";

        cin >> option;
        clearInput();

        switch (option) {
            case 1:
                pet = NewGame();
                player = new Player(pet);
                break;
            case 2:
                pet = LoadGame();
                player = new Player(pet);
                break;
            case 3:
                cout << "Thanks for playing Thumagotchi. See you again soon!" << endl;
                pet = nullptr;
                player = nullptr;

                break;
            case 4:
                SomethingCool();
                pet = nullptr;
                player = nullptr;
                break;
            default:
                pet = nullptr;
                player = nullptr;
                cout << "Invalid input" << endl;
        }

        if (option != 1 && option != 2 && option != 3 && option != 4)
            cout << "Please choose a valid option." << endl;
    } while (option != 1 && option != 2 && option != 3 && option != 4);

    do {
        GamePlay(pet, player);
    } while (pet != nullptr && pet->checkStatus() != 1 && pet->checkStatus() != 2 && pet->checkStatus() != 3);

    if (pet != nullptr && player != nullptr) {
        if (pet->checkStatus() == 2) {
            Line();
            if (pet->getType() == "Bunny") {
                cout << " (\\_/)" << " \3" << endl;
                cout << " (^u^)" << endl;
                cout << "C(\")(\")" << "  " << endl << endl;
            } else if (pet->getType() == "Cat") {
                cout << "/\\___/\\" << " \3" << endl;
                cout << "(>^W^<)" << endl;
                cout << "(\")(\")_/" << "  " << endl << endl;
            } else if (pet->getType() == "Owl") {
                cout << " _____" << endl;
                cout << "(^ v ^)" << " \3" << endl;
                cout << "((___))" << endl;
                cout << "  ^ ^  " << "  " << endl << endl;
            }

            cout << "You've been taking really good care of " << pet->getName() <<
                    ".\nThe two of you look forward to a happy future together." << endl;
            Line();
            EndGame();
        } else if (pet->checkStatus() == 1) {
            Line();
            if (pet->getType() == "Bunny") {
                cout << " (\\_/)" << " \3" << endl;
                cout << " (^u^)" << endl;
                cout << "C(\")(\")" << "  " << endl << endl;
            } else if (pet->getType() == "Cat") {
                cout << "/\\___/\\" << " \3" << endl;
                cout << "(>^W^<)" << endl;
                cout << "(\")(\")_/" << "  " << endl << endl;
            } else if (pet->getType() == "Owl") {
                cout << " _____" << endl;
                cout << "(^ v ^)" << " \3" << endl;
                cout << "((___))" << endl;
                cout << "  ^ ^  " << "  " << endl << endl;
            }
            cout << "You're the best owner " << pet->getName() <<
                    " could've asked for." << endl;
            cout << pet->getName() << " gave you this for being a good egg." << endl;
            player->printGoodEgg();
            Line();
            EndGame();
        } else if (pet->checkStatus() == 3) {
            Line();
            // Art by Jonathon R. Oglesbee
            cout << R"(                                 [O])" << endl;
            cout << R"(                                 [O])" << endl;
            cout << R"(                                 [O])" << endl;
            cout << R"(          ____   /`  ___          ||)" << endl;
            cout << R"(      ___/O|__\_/_  /___\         ||)" << endl;
            cout << R"(     /_____\__/___/|x===o|        ||)" << endl;
            cout << R"(______(o)_______(o)||___||________||________)" << endl;
            cout << R"(       ________  ~.>\`    '    ________)" << endl;
            cout << R"( .  '  \__[]__/  '  ^^   .  .  \[]____/ ')" << endl;
            cout << R"(       //\__/\\  '    ((())    /_/o\\\)" << endl;
            cout << R"(  '.   ( o__o )       aa((((    <_  )/)" << endl;
            cout << R"(        \ __ /  .  '  \-(((( .   \__/   .)" << endl;
            cout << R"( .     __\__/___      / /\\(     /   \)" << endl;
            cout << R"(      /| \||/  |\    ( ( //  .  ||PD|| '  .)" << endl;
            cout << R"(     / |  \/  @| \    \ //      ||  ||)" << endl;
            cout << R"(    /  |_  __  |\ \   /[__]   ' ||  ||  .)" << endl;
            cout << R"(.   \____|//_| |/ /  /_____\    ||__||)" << endl;
            cout << R"(       |       |\/    | | | .   | / \|)" << endl;
            cout << R"(       |_______|/     | | |     |_\\\|   .)" << endl;
            cout << R"(        |     | .   ' |_|_|      |   |)" << endl;
            cout << R"( .'     |  |  |      <-<--/      |   |)" << endl;
            cout << R"(        |  |  |  '  '  .      '  |   |  '  ')" << endl;
            cout << R"(  .     |__|__|                  |___|)" << endl;
            cout << R"(       (__) (__)      .  '      (____)  .    )" << endl << endl;
            cout << "You've been neglecting " << pet->getName() << endl;
            cout << "Someone reported you to the police. They've taken " << pet->getName() <<
                    " to a safe home." << endl;
            cout << "You've been arrested, and the prison's Cat Pal program excluded you." << endl;
            exit(0);
        }
    }

    delete pet;
    delete player;
}

Pet *NewGame() {
    Pet *pet;
    int option;

    Line();

    cout << R"( _____                                              _____ )" << endl;
    cout << R"(( ___ )                                            ( ___ ))" << endl;
    cout << R"( |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | )" << endl;
    cout << R"( |   |     _       _             _   _              |   | )" << endl;
    cout << R"( |   |    / \   __| | ___  _ __ | |_(_) ___  _ __   |   | )" << endl;
    cout << R"( |   |   / _ \ / _` |/ _ \| '_ \| __| |/ _ \| '_ \  |   | )" << endl;
    cout << R"( |   |  / ___ \ (_| | (_) | |_) | |_| | (_) | | | | |   | )" << endl;
    cout << R"( |   | /_/   \_\__,_|\___/| .__/ \__|_|\___/|_| |_| |   | )" << endl;
    cout << R"( |   |       / ___|| |__  |_|_| | |_ ___ _ __       |   | )" << endl;
    cout << R"( |   |       \___ \| '_ \ / _ \ | __/ _ \ '__|      |   | )" << endl;
    cout << R"( |   |        ___) | | | |  __/ | ||  __/ |         |   | )" << endl;
    cout << R"( |   |       |____/|_| |_|\___|_|\__\___|_|         |   | )" << endl;
    cout << R"( |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| )" << endl;
    cout << R"((_____)                                            (_____))" << endl
            << endl;

    do {
        cout << "Take a look at all the wonderful pets we have!" << endl
                << endl;
        cout << "1. BUNNY\n (\\_/)\n ('^')\nC(\")(\")" << endl
                << endl;
        cout << "2. CAT\n/\\___/\\\n(>'W'<)\n(\")_(\")_/" << endl
                << endl;
        cout << "3. OWL\n _____\n(o v o)\n((___))\n  ^ ^  " << endl
                << endl;
        cout << "4. LEAVE SHELTER" << endl
                << endl;
        cout << "Which pet will you be taking home with you today? Select: ";

        cin >> option;
        clearInput();

        switch (option) {
            case 1:
                pet = CreatePet(1);
                break;
            case 2:
                pet = CreatePet(2);
                break;
            case 3:
                pet = CreatePet(3);
                break;
            case 4:
                cout << "Thank you for visiting us. Come back again soon!" << endl;
                exit(0);
            default:
                pet = nullptr;
                cout << "Hmm, never heard of that breed before..." << endl;
        }

        if (option != 1 && option != 2 && option != 3 && option != 4)
            cout << "Please choose a valid option.";
    } while (option != 1 && option != 2 && option != 3 && option != 4);

    return pet;
}

Pet *CreatePet(int option) {
    Pet *pet;
    string name;

    Line();
    switch (option) {
        // Bunny
        case 1:
            cout <<
                    "This little girl is called Swifty, but you can rename her if you'd like.\n (\\_/)\n ('^')\nC(\")(\")\n"
                    << endl;
            name = GetPetName("Swifty");
            pet = new Bunny(name);
            break;
        // Cat
        case 2:
            cout <<
                    "This little guy is called Wilbur, but you can rename him if you'd like.\n/\\___/\\\n(>'W'<)\n(\")_(\")_/\n"
                    << endl;
            name = GetPetName("Wilbur");
            pet = new Cat(name);
            break;
        // Owl
        case 3:
            cout <<
                    "This little guy is called Scamp, but you can rename her if you'd like.\n _____\n(o v o)\n((___))\n  ^ ^  \n"
                    << endl;
            name = GetPetName("Scamp");
            pet = new Owl(name);
            break;
        default:
            pet = nullptr;
            cout << "Error creating pet" << endl;
            break;
    }

    return pet;
}

string GetPetName(string defaultName) {
    int option;
    string name;

    do {
        cout << "What'll it be?\n1. Let's give them a new name\n2. " << defaultName << " is a great name!\nSelect: ";

        cin >> option;
        clearInput();

        switch (option) {
            case 1:
                cout << "What will the new name be? Enter: " << endl;
                cin.ignore();
                getline(cin, name);
                break;
            case 2:
                cout << defaultName << " it is!" << endl;
                name = defaultName;
                break;
            default:
                cout << "Please choose a valid option." << endl;
                break;
        }
    } while (option != 1 && option != 2);

    return name;
}

void GamePlay(Pet *pet, Player *player) {
    int option, exitOption;

    if (pet != nullptr && player != nullptr) {
        do {
            Line();
            cout << "Please choose an interaction.\n1. Feed\n2. Play\n3. Bathe\n4. Heal\n5. Print status\n";

            if (pet->getType() == "Bunny") {
                cout << "6. Get a rabbit's foot\n";
            } else if (pet->getType() == "Cat") {
                cout << "6. Declaw\n";
            } else if (pet->getType() == "Owl") {
                cout << "6. Get an owl's eye\n";
            } else {
                cout << "Error in GamePlay function" << endl;
            }

            cout << "7. Save game\n8. Cheater cheater easy winner\n9. Exit\nSelect: ";
            cin >> option;
            clearInput();

            switch (option) {
                case 1:
                    Feed(pet);
                    break;
                case 2:
                    Play(pet);
                    break;
                case 3:
                    Bathe(pet);
                    break;
                case 4:
                    pet->heal();
                    break;
                case 5:
                    pet->printStatus();
                    break;
                case 6:
                    BadOutcome(pet, player);
                    break;
                case 7:
                    SaveGame(pet);
                    break;
                case 8:
                    Cheat(pet);
                    break;
                case 9:
                    do {
                        cout << "Are you sure you want to quit? All unsaved progress will be gone." << endl;
                        cout << "1. Yes\n2. No\nSelect: ";
                        cin >> exitOption;
                        clearInput();

                        switch (exitOption) {
                            case 1:
                                cout << "Thank you for playing." << endl;
                                exit(0);
                            case 2:
                                continue;
                            default:
                                cout << "Error in GamePlay exit" << endl;
                                break;
                        }
                        if (exitOption != 1 && exitOption != 2)
                            cout << "Please choose a valid option." << endl;
                    } while (exitOption != 1 && exitOption != 2);
                default:
                    break;
            }

            if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 7 &&
                option != 8 && option != 9 && exitOption == 2)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 7 &&
                 option != 8 && option != 9 && exitOption == 2);
    }
}

void Feed(Pet *pet) {
    int option;

    if (pet->getType() == "Bunny") {
        do {
            Line();
            cout << "What would you like to feed " << pet->getName() << "?" << endl;
            cout << "1. Carrot\n2. Spring mix\n3. Meat\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->feed(option);
    } else if (pet->getType() == "Cat") {
        do {
            Line();
            cout << "What would you like to feed " << pet->getName() << "?" << endl;
            cout << "1. Kibble\n2. Canned food\n3. Veggies\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->feed(option);
    } else if (pet->getType() == "Owl") {
        do {
            Line();
            cout << "What would you like to feed " << pet->getName() << "?" << endl;
            cout << "1. Seeds\n2. Cooked chicken\n3. Raw chicken\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->feed(option);
    } else {
        cout << "Error feeding pet" << endl;
    }
}

void Play(Pet *pet) {
    int option;

    if (pet->getType() == "Bunny") {
        do {
            Line();
            cout << "Please pick a toy for " << pet->getName() << endl;
            cout << "1. Treat ball\n2. Foraging toy\n3. I'm gonna tickle her\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->play(option);
    } else if (pet->getType() == "Cat") {
        do {
            Line();
            cout << "Please pick a toy for " << pet->getName() << endl;
            cout << "1. Wand\n2. Mouse\n3. I'm gonna tickle his belly\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->play(option);
    } else if (pet->getType() == "Owl") {
        do {
            Line();
            cout << "Please pick a toy for " << pet->getName() << endl;
            cout << "1. Cheap shredding foraging toy\n2. Woven ball\n3. I'm gonna tickle him\nSelect: ";
            cin >> option;
            clearInput();

            if (option != 1 && option != 2 && option != 3)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2 && option != 3);
        pet->play(option);
    } else {
        cout << "Error playing with pet" << endl;
    }
}

void Bathe(Pet *pet) {
    int option;

    do {
        Line();
        cout << "Please  choose a water temperature for " << pet->getName() << "'s bath" << endl;
        cout << "1. Cold water\n2. Warm water\nSelect: ";
        cin >> option;
        clearInput();

        if (option != 1 && option != 2)
            cout << "Please choose a valid option." << endl;
    } while (option != 1 && option != 2);
    pet->bathe(option);
}

void BadOutcome(Pet *pet, Player *player) {
    int option, option1, option2;

    if (pet->getType() == "Bunny") {
        do {
            Line();
            cout <<
                    "You saw on some sketchy site that a rabbit's foot is good luck, \nso you had an idea of getting one from "
                    << pet->getName() << ".\nAre you sure you want to do this?" << endl;
            cout << "1. Yes\n2. Are you insane? Heck no\nSelect: ";
            cin >> option;
            clearInput();

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        clearInput();

                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
                                    clearInput();

                                    switch (option2) {
                                        case 1:
                                            pet->badOutcome();
                                            player->printBadEgg();
                                            exit(0);
                                        case 2:
                                            break;
                                        default:
                                            cout << "Error getting option2 from BadOutcome()" << endl;
                                            break;
                                    }
                                    if (option2 != 1 && option2 != 2)
                                        cout << "Please choose a valid option." << endl;
                                } while (option2 != 1 && option2 != 2);
                            case 2:
                                break;
                            default:
                                cout << "Error getting option1 from BadOutcome()" << endl;
                                break;
                        }
                        if (option1 != 1 && option1 != 2)
                            cout << "Please choose a valid option." << endl;
                    } while (option1 != 1 && option1 != 2);
                case 2:
                    cout << "Next time don't go on sketchy sites..." << endl;
                    break;
                default:
                    cout << "Error getting option from BadOutcome()" << endl;
                    break;
            }
            if (option != 1 && option != 2)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2);
    } else if (pet->getType() == "Cat") {
        do {
            Line();
            cout <<
                    "You saw on some sketchy site that you should declaw cats so they don't shred up your furnitures,\nso you had an idea to do that with "
                    << pet->getName() << ".\nAre you sure you want to do this?" << endl;
            cout << "1. Yes\n2. Are you insane? Heck no\nSelect: ";
            cin >> option;
            clearInput();

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        clearInput();

                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
                                    clearInput();

                                    switch (option2) {
                                        case 1:
                                            pet->badOutcome();
                                            player->printBadEgg();
                                            exit(0);
                                        case 2:
                                            break;
                                        default:
                                            cout << "Error getting option2 from BadOutcome()" << endl;
                                            break;
                                    }
                                    if (option2 != 1 && option2 != 2)
                                        cout << "Please choose a valid option." << endl;
                                } while (option2 != 1 && option2 != 2);
                            case 2:
                                break;
                            default:
                                cout << "Error getting option1 from BadOutcome()" << endl;
                                break;
                        }
                        if (option1 != 1 && option1 != 2)
                            cout << "Please choose a valid option." << endl;
                    } while (option1 != 1 && option1 != 2);
                case 2:
                    cout << "Next time don't go on sketchy sites..." << endl;
                    break;
                default:
                    cout << "Error getting option from BadOutcome()" << endl;
                    break;
            }
            if (option != 1 && option != 2)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2);
    } else if (pet->getType() == "Owl") {
        do {
            Line();
            cout <<
                    "You saw on some sketchy site that consuming owl's eyes is great for eyesight,\nso you had an idea of getting one from "
                    << pet->getName() << ".\nAre you sure you want to do this?" << endl;
            cout << "1. Yes\n2. Are you insane? Heck no\nSelect: ";
            cin >> option;
            clearInput();

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        clearInput();

                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
                                    clearInput();

                                    switch (option2) {
                                        case 1:
                                            pet->badOutcome();
                                            player->printBadEgg();
                                            exit(0);
                                        case 2:
                                            break;
                                        default:
                                            cout << "Error getting option2 from BadOutcome()" << endl;
                                            break;
                                    }
                                    if (option2 != 1 && option2 != 2)
                                        cout << "Please choose a valid option." << endl;
                                } while (option2 != 1 && option2 != 2);
                            case 2:
                                break;
                            default:
                                cout << "Error getting option1 from BadOutcome()" << endl;
                                break;
                        }
                        if (option1 != 1 && option1 != 2)
                            cout << "Please choose a valid option." << endl;
                    } while (option1 != 1 && option1 != 2);
                case 2:
                    cout << "Next time don't go on sketchy sites..." << endl;
                    break;
                default:
                    cout << "Error getting option from BadOutcome()" << endl;
                    break;
            }
            if (option != 1 && option != 2)
                cout << "Please choose a valid option." << endl;
        } while (option != 1 && option != 2);
    } else {
        cout << "Error in BadOutcome()" << endl;
    }
}

void Cheat(Pet *pet) {
    int option;

    Line();
    cout << "Trying to cheat there, are you? I'll allow it just this once." << endl;

    do {
        cout <<
                "1. Yes please, it's taking too long and I have no patience.\n2. No thanks, I don't need child support, I'm an independent pet owner.\nSelect: ";

        cin >> option;
        clearInput();

        switch (option) {
            case 1:
                pet->setFood(5);
                pet->setHappiness(5);
                pet->setSickness(0);
                pet->setBadEgg(0);
                break;
            case 2:
                cout << "Good for you!" << endl;
                break;
            default:
                cout << "Error getting option from Cheat()" << endl;
                break;
        }

        if (option != 1 && option != 2) {
            cout << "Please choose a valid option." << endl;
        }
    } while (option != 1 && option != 2);
}

void SomethingCool() {
    Line();
    cout << "    ___________________" << endl;
    cout << "   |  _______________  |" << endl;
    cout << "   | |             0 | |" << endl;
    cout << "   | | 80085         | |" << endl;
    cout << "   | |_______________| |" << endl;
    cout << "   |  ___ ___ ___ ___  |" << endl;
    cout << "   | | 7 | 8 | 9 | / | |" << endl;
    cout << "   | |___|___|___|___| |" << endl;
    cout << "   | | 4 | 5 | 6 | x | |" << endl;
    cout << "   | |___|___|___|___| |" << endl;
    cout << "   | | 1 | 2 | 3 | - | |" << endl;
    cout << "   | |___|___|___|___| |" << endl;
    cout << "   | | . | 0 | = | + | |" << endl;
    cout << "   | |___|___|___|___| |" << endl;
    cout << "   |___________________|" << endl;
    cout << "           hehe" << endl;
}

void clearInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void EndGame() {
    cout << "Thanks for playing Thumagotchi! See you again soon!" << endl;
    exit(0);
}
