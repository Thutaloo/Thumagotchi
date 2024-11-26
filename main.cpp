#include <iostream>
#include "Bunny.cpp"
#include "Cat.cpp"
#include "Owl.cpp"
#include "Player.h"

using namespace std;

// Functions declaration
void Line();

void StartMenu();

void NewGame();

void CreatePet(int);

void BasicInfo();

int main() {
    return 0;
}

// Functions implementation
void Line() {
    cout << ">>=============================================================================<<" << endl;
}

void StartMenu() {
    int option;

    cout << " _____                                                                     _____" << endl;
    cout << "( ___ )                                                                   ( ___ )" << endl;
    cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | " << endl;
    cout << " |   |       __        __   _                            _                 |   | " << endl;
    cout << R"( |   |       \ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___           |   | )" << endl;
    cout << R"( |   |        \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \          |   | )" << endl;
    cout << R"( |   |         \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |         |   | )" << endl;
    cout << R"( |   |          \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/          |   | )" << endl;
    cout << " |   |  _____ _                                       _       _     _   _  |   | " << endl;
    cout << " |   | |_   _| |__  _   _ _ __ ___   __ _  __ _  ___ | |_ ___| |__ (_) | | |   | " << endl;
    cout << R"( |   |   | | | '_ \| | | | '_ ` _ \ / _` |/ _` |/ _ \| __/ __| '_ \| | | | |   | )" << endl;
    cout << " |   |   | | | | | | |_| | | | | | | (_| | (_| | (_) | || (__| | | | | |_| |   | " << endl;
    cout << R"( |   |   |_| |_| |_|\__,_|_| |_| |_|\__,_|\__, |\___/ \__\___|_| |_|_| (_) |   | )" << endl;
    cout << " |   |                                    |___/                            |   | " << endl;
    cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| " << endl;
    cout << "(_____)                                                                   (_____)" << endl
            << endl;

    do {
        Line();
        cout << "1. NEW GAME\n2. LOAD GAME\n3. EXIT\n";

        cout << "Select: ";

        cin >> option;

        switch (option) {
            case 1:
                cout << "Case 1" << endl;
                break;
            case 2:
                cout << "Case 2" << endl;
                break;
            case 3:
                cout << "Thanks for playing Thumagotchi. See you again soon!" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }

        if (option != 1 && option != 2 && option != 3)
            cout << "Please choose a valid option." << endl;
    } while (option != 1 && option != 2 && option != 3);
}

void NewGame() {
    int option;

    Line();

    cout << " _____                                              _____ " << endl;
    cout << "( ___ )                                            ( ___ )" << endl;
    cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | " << endl;
    cout << " |   |     _       _             _   _              |   | " << endl;
    cout << R"( |   |    / \   __| | ___  _ __ | |_(_) ___  _ __   |   | )" << endl;
    cout << R"( |   |   / _ \ / _` |/ _ \| '_ \| __| |/ _ \| '_ \  |   | )" << endl;
    cout << R"( |   |  / ___ \ (_| | (_) | |_) | |_| | (_) | | | | |   | )" << endl;
    cout << R"( |   | /_/   \_\__,_|\___/| .__/ \__|_|\___/|_| |_| |   | )" << endl;
    cout << " |   |       / ___|| |__  |_|_| | |_ ___ _ __       |   | " << endl;
    cout << R"( |   |       \___ \| '_ \ / _ \ | __/ _ \ '__|      |   | )" << endl;
    cout << " |   |        ___) | | | |  __/ | ||  __/ |         |   | " << endl;
    cout << R"( |   |       |____/|_| |_|\___|_|\__\___|_|         |   | )" << endl;
    cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| " << endl;
    cout << "(_____)                                            (_____)" << endl
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
                CreatePet(1);
                break;
            case 2:
                CreatePet(2);
                break;
            case 3:
                CreatePet(3);
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
}

void CreatePet(int option) {
    int choice;
    string name;

    switch (option) {
        case 1:
            cout <<
                    "This little girl is called Swifty, but you can rename her if you'd like.\n (\\_/)\n ('^')\nC(\")(\")\nWhat'll it be?\n1. Let's give her a new name\n2. Swifty is a great name!\nSelect: "
                    << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "What will the new name be? Enter: " << endl;
                    cin.ignore();
                    getline(cin, name);
                case 2:
                default:
                    cout << "Please choose a valid option." << endl;
            }
            break;
        case 2:
            cout <<
                    "This little guy is called Wilbur, but you can rename him if you'd like.\n/\\___/\\\n(>'W'<)\n(\")_(\")_/\nWhat'll it be?\n1. Let's give him a new name\n2. Wilbur is a great name!\nSelect: "
                    << endl;
            break;
        case 3:
            cout <<
                    "This little guy is called Scamp, but you can rename her if you'd like.\n _____\n(o v o)\n((___))\n  ^ ^  \nWhat'll it be?\n1. Let's give him a new name\n2. Scamp is a great name!\nSelect: "
                    << endl;
            break;
        default:
            break;
    }
}
