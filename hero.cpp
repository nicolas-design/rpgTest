#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "npc.h"
#include "item.h"
#include "charakter.h"




void Hero::attack( Character* enemy){
    srand((unsigned) time(0));
    int num = 15 + (rand() % 10);
    int leben = enemy->getLeben();
    enemy->setLeben(leben - num);
    std::cout << this->getName() << " trifft " << enemy->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

void Hero::sellItem(const int index){
    if (this->getInvenarItem(index).isValidget()){
        this->setGold(this->getGold() + this->getInvenarItem(index).getWert());
        std::cout << this->getName() << " verkauft " << this->getInvenarItem(index).getBezeichnung() << " fuer " << this->getInvenarItem(index).getWert() << std::endl;
        this->getInvenarItem(index).initItem();
    }
}

bool Hero::fight(Npc* enemy, Hero* hero){
    while (true){
        Hero::attack(enemy);
        if (enemy->getLeben() <= 0){
            std::cout << enemy->getName() << " fiel in Ohnmacht. " << this->getName() << " hat noch " << this->getLeben() << " Lebenspunkte." << std::endl;
            int num = enemy->getRandomItemSlot();
            if (num != -1){
                Item item = enemy->removeInventarItem(num);
                this->addInventarItem(&item);
            }

            return true;
        }
        enemy->attack(hero);
        if (this->getLeben() <= 0){
            std::cout << this->getName() << " fällt in Ohnmacht." << std::endl;
            return false;
        }

    }
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



Hero::Hero(const std::string &name, int leben, int gold, int armor, int magicResistance) : Character(name, leben,gold, armor, magicResistance){
    for (int i = 0; i < 2; ++i) {
        this->ausruestung[i].setIsValid(false);
    }
}
