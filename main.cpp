#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
void Line();

string generateRandomString(int length);

Pet *LoadGame();

void SaveGame(Pet *pet);

void StartMenu();

Pet *NewGame();

Pet *CreatePet(int);

string GetPetName(string defaultName);

void GamePlay(Pet *pet, Player *player);

void Feed(Pet *pet);

void Play(Pet *pet);

void Bathe(Pet *pet);

void BadOutcome(Pet *pet, Player *player);

void SomethingCool();


// main()
int main() {
    StartMenu();
    return 0;
}

// Functions implementation
void Line() {
    cout << ">>=============================================================================<<" << endl;
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
    int food, happiness, sickness, badEgg;

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
            getline(file, name);
            getline(file, type);
            file >> food >> happiness >> sickness >> badEgg;
        }
    }

    // Create pet based on type
    if (type == "Bunny") {
        pet = new Bunny(name, food, happiness, sickness, badEgg);
    } else if (type == "Cat") {
        pet = new Cat(name, food, happiness, sickness, badEgg);
    } else if (type == "Owl") {
        pet = new Owl(name, food, happiness, sickness, badEgg);
    } else {
        cout << "Error fetching pet type" << endl;
        pet = nullptr;
    }

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
            getSickness() << endl << endl;

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

    cout << R"( _____                                                                     _____)" << endl;
    cout << R"(( ___ )                                                                   ( ___ )" << endl;
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

    do {
        Line();
        cout << "1. NEW GAME\n2. LOAD GAME\n3. EXIT\n4. See something cool\n";

        cout << "Select: ";

        cin >> option;

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

    if (pet != nullptr) {
        if (pet->checkStatus() == 1) {
        } else if (pet->checkStatus() == 2) {
        } else if (pet->checkStatus() == 3) {
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
        switch (option) {
            case 1:
                cout << "What will the new name be? Enter: " << endl;
                cin.ignore();
                getline(cin, name);
            case 2:
                cout << defaultName << " it is!" << endl;
                name = defaultName;
            default:
                cout << "Please choose a valid option." << endl;
        }
    } while (option != 1 && option != 2);

    return name;
}

void GamePlay(Pet *pet, Player *player) {
    int option, exitOption;

    do {
        Line();
        cout << "Please choose an interaction.\n1. Feed\n2. Play\3. Bathe\n4. Heal\n5. Print status\n";

        if (pet->getType() == "Bunny") {
            cout << "6. Get a rabbit's foot\n";
        } else if (pet->getType() == "Cat") {
            cout << "6. Declaw\n";
        } else if (pet->getType() == "Owl") {
            cout << "6. Get an owl's eye\n";
        } else {
            cout << "Error in GamePlay function" << endl;
        }

        cout << "7. Save game\n8. Exit (without saving)\nSelect: ";
        cin >> option;

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
            case 5:
                pet->printStatus();
            case 6:
                BadOutcome(pet, player);
            case 7:
                SaveGame(pet);
            case 8:
                do {
                    cout << "Are you sure you want to quit? All unsaved progress will be gone." << endl;
                    cout << "1. Yes\n2. No\nSelect: ";
                    cin >> exitOption;

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
                cout << "Error in GamePlay function" << endl;
                break;
        }

        if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 7 &&
            option != 8 && exitOption == 2)
            cout << "Please choose a valid option." << endl;
    } while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 7 &&
             option != 8 && exitOption == 2);
}

void Feed(Pet *pet) {
    int option;

    if (pet->getType() == "Bunny") {
        do {
            Line();
            cout << "What would you like to feed " << pet->getName() << "?" << endl;
            cout << "1. Carrot\n2. Spring mix\n3. Meat\nSelect: ";
            cin >> option;

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

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
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

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
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

            switch (option) {
                case 1:
                    do {
                        cout << "Are you sure you're sure?\n1. Yes\n2. I would never do that!\nSelect: ";
                        cin >> option1;
                        switch (option1) {
                            case 1:
                                do {
                                    cout <<
                                            "Are you sure you're sure you're sure?\n1. Yes\n2. For the last time, no!\nSelect: ";
                                    cin >> option2;
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
