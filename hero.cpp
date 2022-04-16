#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "npc.h"
#include "item.h"
#include "character.h"




void Hero::attack( Character* enemy){
    int num = this->randomNum(15, 25);
    int leben = enemy->getLeben();
    num = num - enemy->getArmor();
    if (num<0){
        num = 0;
    }
    enemy->setLeben(leben - num);
    std::cout << this->getName() << " trifft " << enemy->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

void Hero::sellItem(const int index){
    if (this->getInvenarItem(index) != nullptr){
        this->setGold(this->getGold() + this->getInvenarItem(index)->getWert());
        std::cout << this->getName() << " verkauft " << this->getInvenarItem(index)->getBezeichnung() << " fuer " << this->getInvenarItem(index)->getWert() << std::endl;
        this->removeInventarItem(index);
    } else {
        throw EmptyIndexException("Hero::sellItem(): Inventar Index ist leer");
    }
}

bool Hero::fight(Npc* enemy, Hero* hero){
    while (true){
        Hero::attack(enemy);
        if (enemy->getLeben() <= 0){
            std::cout << enemy->getName() << " fiel in Ohnmacht. " << this->getName() << " hat noch " << this->getLeben() << " Lebenspunkte." << std::endl;
            this->addInventarItem(enemy->retrieveRandomLoot());
            
            return true;
        }
        enemy->attack(hero);
        if (this->getLeben() <= 0){
            std::cout << this->getName() << " fiel in Ohnmacht." << std::endl;
            return false;
        }

    }
}


int Hero::addEquipmentItem(Item* item){
    for (int i = 0; i < 2; ++i) {
        if (this->ausruestung[i] == nullptr){
            this->ausruestung[i] = item;
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zur Ausrüstung hinzugefuegt." << std::endl;
            return i;
        }
    }
    throw ArrayFullException("Hero::addEquipmentItem(): Equipment Inventar ist voll");
}

Item* Hero::removeEquipmentItem(int slot){
    Item* item;
    if (slot < 0 || slot > 9){
        throw InvalidIndexException("Hero::removeEquipmentItem(): Index ist außeerhalb vom Bereich 0-9");
    }
    if (this->ausruestung[slot] == nullptr){
        throw EmptyIndexException("Hero::removeEquipmentItem(): Ausgewählter Inventar Index ist leer");
    }
    std::cout << "Gegenstand" << this->ausruestung[slot]->getBezeichnung() << "wurde entfernt" << std::endl;
    item = this->ausruestung[slot];
    this->ausruestung[slot] = nullptr;
    return item;
}



Hero::Hero(const std::string &name, int leben, int gold, int armor, int magicResistance) : Character(name, leben,gold, armor, magicResistance){
    for (int i = 0; i < 2; ++i) {
        this->ausruestung[i] = nullptr;
    }
}

Hero::~Hero() {
    std::cout << "Held " << this->getName() << " verabschiedet sich und geht schlafen." << std::endl;
}
