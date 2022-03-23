

#ifndef MDS2HW1_CHARAKTER_H
#define MDS2HW1_CHARAKTER_H
#include <iostream>
#include "item.h"

class Character {
private:
    std::string name;
    int leben;
    int gold;
    Item inventar[10];
    int armor;
    int magicResistance;

public:

    Character(const std::string &name, int leben, int gold, int armor, int magicResistance);

    virtual void attack(Character* enemy) = 0;

    Item removeInventarItem(int slot);

    int addInventarItem( Item* item);

    Item getInvenarItem(int slot);

    const std::string &getName() const;

    int getLeben() const;

    int getGold() const;

    void setLeben(int leben);

    void setGold(int gold);
};

#endif //MDS2HW1_CHARAKTER_H
