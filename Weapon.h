#pragma once
#include <iostream>

class Weapon {
public:
    Weapon() = default;
    virtual ~Weapon() = default;

    // 純粋仮想関数 (抽象メソッド)
    virtual void Attack() = 0;

protected:
    const char* name;
};