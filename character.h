
#ifndef MDS2HW1_CHARACTER_H
#define MDS2HW1_CHARACTER_H
#include <iostream>
#include "hero.h"
#include "item.h"

struct Charakter_t {
    std::string name;
    int leben;
    int gold;
    struct Item_t inventar[10];
};

void initCharacter(struct Charakter_t* charakter, char* name, int health, int gold);

void attack(struct Charakter_t* character, struct Hero_t* hero);



#endif //MDS2HW1_CHARACTER_H
