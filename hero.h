
#ifndef MDS2HW1_HERO_H
#define MDS2HW1_HERO_H
#include <iostream>
#include "character.h"
#include "item.h"

struct Hero_t {
    std::string name;
    int leben;
    int gold;
    struct Item_t inventar[10];
    struct Item_t ausruestung[2];
};


void initHero(struct Hero_t* hero, char* name, int health, int gold);

void attack(struct Hero_t* hero, struct Charakter_t* enemy);

void sellItem(struct Hero_t* hero, int index);

bool fight(struct Hero_t* hero, struct Charakter_t* enemy);

void addItem(struct Hero_t* hero, struct Item_t* item);


#endif //MDS2HW1_HERO_H
