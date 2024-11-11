#include <stdio.h>
#include <iostream>

class Weapon {
public:
    Weapon() {};
    virtual ~Weapon() {};

    virtual void Attack() {
        printf("%s で攻撃\n", name);
    };

protected:
    const char* name;
};

class Sword : public Weapon {
public:
    Sword() { name = "剣"; }
};

class Bow : public Weapon {
public:
    Bow() { name = "弓"; }
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


