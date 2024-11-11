#include <stdio.h>
#include <iostream>

class Weapon {
public:
    Weapon() = default;
    virtual ~Weapon() = default;

    // 純粋仮想関数
    virtual void Attack() = 0;

protected:
    const char* name;
};

class Sword : public Weapon {
public:
    Sword() { name = "剣"; }
    void Attack() override {
        printf("%s で 斬撃！\n",name);
    }
};

class Bow : public Weapon {
public:
    Bow() { name = "弓"; }
    void Attack() override {
        printf("%s で 射撃！\n",name);
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
