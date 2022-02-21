#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"



void initHero(struct Hero_t* hero, char* name, int health, int gold){
    hero->name=name;
    hero->leben=health;
    hero->gold= gold;
    for (int i = 0; i < 10; ++i) {
        hero->inventar[i].isValid = false;
    }
    for (int i = 0; i < 2; ++i) {
        hero->ausruestung[i].isValid = false;
    }
}

void attack(struct Hero_t* hero, struct Charakter_t* enemy){
    srand((unsigned) time(0));
    int num = 15 + (rand() % 10);
    enemy->leben = enemy->leben - num;
    std::cout << hero->name << " trifft " << enemy->name << " fuer " << num << " Lebenspunkte." << std::endl;
}

void sellItem(struct Hero_t* hero, int index){
    if (hero->inventar[index - 1].isValid){
        hero->gold = hero->gold + hero->inventar[index-1].wert;
        std::cout << hero->name << " verkauft " << hero->inventar[index-1].bezeichnung << " fuer " << hero->inventar[index-1].wert << std::endl;
        initItem(&hero->inventar[index-1]);
    }
}

bool fight(struct Hero_t* hero, struct Charakter_t* enemy){
    while (true){
        attack(hero, enemy);
        if (enemy->leben <= 0){
            std::cout << enemy->name << " fiel in Ohnmacht. " << hero->name << " hat noch " << hero->leben << " Lebenspunkte." << std::endl;
            return true;
        }
        attack(enemy, hero);
        if (hero->leben <= 0){
            std::cout << hero->name << " fällt in Ohnmacht." << std::endl;
            return false;
        }

    }
}

void addItem(struct Hero_t* hero, struct Item_t* item){
    for (int i = 0; i < 10; ++i) {
        if (hero->inventar[i].isValid == false){
            hero->inventar[i].bezeichnung = item->bezeichnung;
            hero->inventar[i].wert = item->wert;
            hero->inventar[i].isValid = item->isValid;
            std::cout << "Gegenstand " << item->bezeichnung << " wurde zum Inventar hinzugefuegt." << std::endl;
            i = 10;
        }
    }
}