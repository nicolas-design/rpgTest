
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
    void initHero(std::string name, int health, int gold);

    void attack(class Charakter* enemy);

    void sellItem( int index);

    bool fight(Charakter* enemy, Hero* hero);

    void addItem( Item* item);

    int getLeben() const;

    void setLeben(int leben);

    const std::string &getName() const;
};

#endif //MDS2HW1_HERO_H
