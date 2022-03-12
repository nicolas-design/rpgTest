#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"



void Hero::initHero(const std::string name, const int health, const int gold){
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

void Hero::sellItem(const int index){
    if (this->inventar[index].isValidget()){
        this->gold = this->gold + this->inventar[index].getWert();
        std::cout << this->name << " verkauft " << this->inventar[index].getBezeichnung() << " fuer " << this->inventar[index].getWert() << std::endl;
        this->inventar[index].initItem();
    }
}

bool Hero::fight(Charakter* enemy, Hero* hero){
    while (true){
        Hero::attack(enemy);
        if (enemy->getLeben() <= 0){
            std::cout << enemy->getName() << " fiel in Ohnmacht. " << this->name << " hat noch " << this->leben << " Lebenspunkte." << std::endl;
            int num = enemy->getRandomItemSlot();
            if (num != -1){
                Item item = enemy->removeInventarItem(num);
                this->addInventarItem(&item);
            }

            return true;
        }
        enemy->attack(hero);
        if (this->leben <= 0){
            std::cout << this->name << " fällt in Ohnmacht." << std::endl;
            return false;
        }

    }
}

int Hero::addInventarItem(Item* item){
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget() == false){
            this->inventar[i].initItem(item->getBezeichnung(), item->getWert());
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zum Inventar hinzugefuegt." << std::endl;
            return i;
        }
    }
    return -1;
}

int Hero::addEquipmentItem(const Item* item){
    for (int i = 0; i < 2; ++i) {
        if (this->ausruestung[i].isValidget() == false){
            this->ausruestung[i].initItem(item->getBezeichnung(), item->getWert());
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zur Ausrüstung hinzugefuegt." << std::endl;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot){
    Item item;
    if (slot < 0 || slot > 10){
        return item;
    }
    if (this->inventar[slot].isValidget()== false){
        return item;
    }
    std::cout << "Gegenstand " << this->inventar[slot].getBezeichnung() << " wurde entfernt" << std::endl;
    item = this->inventar[slot];
    this->inventar[slot].initItem();
    return item;
}

Item Hero::removeEquipmentItem(int slot){
    Item item;
    if (slot < 0 || slot > 10){
        return item;
    }
    if (this->ausruestung[slot].isValidget()== false){
        return item;
    }
    std::cout << "Gegenstand" << this->ausruestung[slot].getBezeichnung() << "wurde entfernt" << std::endl;
    item = this->ausruestung[slot];
    this->ausruestung[slot].initItem();
    return item;
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
