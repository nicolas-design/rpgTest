#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"



void Hero::initHero(std::string name, int health, int gold){
    this->name = name;
    this->leben=health;
    this->gold= gold;
    for (int i = 0; i < 10; ++i) {
        this->inventar[i].setIsValid(false);
    }
    for (int i = 0; i < 2; ++i) {
        this->ausruestung[i].setIsValid(false);
    }
}

void Hero::attack(class Charakter* enemy){
    srand((unsigned) time(0));
    int num = 15 + (rand() % 10);
    int leben = enemy->getLeben();
    enemy->setLeben(leben - num);
    std::cout << this->name << " trifft " << enemy->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

void Hero::sellItem(int index){
    if (this->inventar[index - 1].isValidget()){
        this->gold = this->gold + this->inventar[index-1].getWert();
        std::cout << this->name << " verkauft " << this->inventar[index-1].getBezeichnung() << " fuer " << this->inventar[index-1].getWert() << std::endl;
        this->inventar[index-1].initItem();
    }
}

bool Hero::fight(Charakter* enemy, Hero* hero){
    while (true){
        Hero::attack(enemy);
        if (enemy->getLeben() <= 0){
            std::cout << enemy->getName() << " fiel in Ohnmacht. " << this->name << " hat noch " << this->leben << " Lebenspunkte." << std::endl;
            return true;
        }
        enemy->attack(hero);
        if (this->leben <= 0){
            std::cout << this->name << " fällt in Ohnmacht." << std::endl;
            return false;
        }

    }
}

void Hero::addItem(Item* item){
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget() == false){
            this->inventar[i].setBezeichnung( item->getBezeichnung()) ;
            this->inventar[i].setWert(item->getWert()) ;
            this->inventar[i].setIsValid(item->isValidget()) ;
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zum Inventar hinzugefuegt." << std::endl;
            i = 10;
        }
    }
}

int Hero::getLeben() const {
    return leben;
}

void Hero::setLeben(int leben) {
    Hero::leben = leben;
}

const std::string &Hero::getName() const {
    return name;
}
