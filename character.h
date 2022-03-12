
#ifndef MDS2HW1_CHARACTER_H
#define MDS2HW1_CHARACTER_H
#include <iostream>
#include "hero.h"
#include "item.h"

class Charakter {
private:
    std::string name;
    int leben;
    int gold;
    Item inventar[10];

public:
    void initCharacter(const std::string name, int health, int gold);

    void attack(class Hero* hero);

    int getLeben() const;

    void setLeben(int leben);

    const std::string &getName() const;

    Item removeInventarItem(int slot);

    int addInventarItem( Item* item);

    int getRandomItemSlot();
};




#endif //MDS2HW1_CHARACTER_H
