
#ifndef MDS2HW1_HERO_H
#define MDS2HW1_HERO_H
#include <iostream>
#include "character.h"
#include "item.h"

class Hero {
private:
    std::string name;
    int leben;
    int gold;
    Item inventar[10];
    Item ausruestung[2];


public:
    void initHero(const std::string name, const int health, const int gold);

    void attack(class Charakter* enemy);

    void sellItem(const int index);

    bool fight(Charakter* enemy, Hero* hero);

    int addInventarItem( Item* item);

    int addEquipmentItem(const Item* item);

    Item removeInventarItem(int slot);

    Item removeEquipmentItem(int slot);

    int getLeben() const;

    void setLeben(int leben);

    const std::string &getName() const;
};

#endif //MDS2HW1_HERO_H
