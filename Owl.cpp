#include "Owl.h"

Owl::Owl() : Pet("Scamp", 2, 2, 0, 0) {
    this->owlsEye = false;
}

Owl::Owl(string name) : Pet(name, 2, 2, 0, 0) {
    this->owlsEye = false;
}

Owl::Owl(string name, int food, int happiness, int sickness, int badEgg) : Pet(
    name, food, happiness, sickness, badEgg) {
    this->owlsEye = false;
}

void Owl::setOwlsEye(bool owlsEye) {
    this->owlsEye = owlsEye;
}

bool Owl::getOwlsEye() {
    return this->owlsEye;
}

// Override base virtual functions
string Owl::getType() {
    return "Owl";
}

void Owl::feed(int option) {
    if (option == 1) {
        cout << "Feeding " << getName() << " some seeds. He can't eat it with his beak..." << endl;
        setHappiness(getHappiness() - 1);
        setBadEgg(getBadEgg() + 1);
    } else if (option == 2) {
        cout << "Feeding " << getName() << " some cooked chicken. He doesn't like it much..." << endl;
        setFood(getFood() + 1);
        setHappiness(getHappiness() - 1);
    } else if (option == 3) {
        cout << "Feeding " << getName() << " some raw chicken. He's obsessed with it." << endl;
        setFood(getFood() + 2);
        setHappiness(getHappiness() + 2);
    } else {
        cout << "This doesn't look like food..." << endl;
    }
}

void Owl::play(int option) {
    if (option == 1) {
        cout << "Giving " << getName() <<
                " a cheap shredding-foraging toy. He accidentally swallows some of the fillings." << endl;
        setSickness(getSickness() - 1);
    } else if (option == 2) {
        cout << "Giving " << getName() << " a woven ball. He's having a ball playing with it." << endl;
        setHappiness(getHappiness() + 2);
    } else if (option == 3) {
        cout << "You try to tickle " << getName() << ". He's not that into it, but enjoys the attention." << endl;
        setHappiness(getHappiness() + 1);
    } else {
        cout << "You don't have anything like that..." << endl;
    }
}

void Owl::bathe(int option) {
    if (option == 1) {
        cout << "You gave " << getName() <<
                " a cold bath. He loves the feeling of rain sprinkling on him." << endl;
        setHappiness(getHappiness() + 3);
    } else if (option == 2) {
        cout << "You gave " << getName() << " a warm bath. He hates the heat and pecks at you."
                << endl;
        setBadEgg(getBadEgg() + 1);
    } else {
        cout << "???" << endl;
    }
}

void Owl::heal() {
    cout << "Giving " << getName() << " some meds. The pill was too big and he hates it, but he does feel better." <<
            endl;
    setHappiness(getHappiness() - 1);
    setSickness(0);
}

void Owl::badOutcome() {
    this->owlsEye = true;
}

Owl::~Owl() = default;
