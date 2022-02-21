#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "hero.h"
#include "item.h"



void initCharacter(struct Charakter_t* charakter, char* name, int health, int gold){
    charakter->name=name;
    charakter->leben=health;
    charakter->gold= gold;
    for (int i = 0; i < 10; ++i) {
        charakter->inventar[i].isValid = false;
    }
}

void attack(struct Charakter_t* character, struct Hero_t* hero){
    srand((unsigned) time(0));
    int num = 5 + (rand() % 10);
    hero->leben = hero->leben - num;
    std::cout << character->name << " trifft " << hero->name << " fuer " << num << " Lebenspunkte." << std::endl;
}