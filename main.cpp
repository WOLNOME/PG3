#include <stdio.h>
#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword() { name = "Sword"; }
    void Attack() override {
        printf("%s attacks with a slash!\n", name);
    }
};

class Bow : public Weapon {
public:
    Bow() { name = "Bow"; }
    void Attack() override {
        printf("%s shoots an arrow!\n", name);
    }
};

int main() {
    Weapon* sword = new Sword();
    Weapon* bow = new Bow();

    sword->Attack(); 
    bow->Attack();  

    delete sword;
    delete bow;
    return 0;
}