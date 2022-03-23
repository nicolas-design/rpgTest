#include <iostream>
#include "charakter.h"
#include "item.h"

Character::Character(const std::string &name, int leben, int gold, int armor, int magicResistance) : name(name), leben(leben), gold(gold), armor(armor), magicResistance(magicResistance) {
    for (int i = 0; i < 10; ++i) {
        this->inventar[i].setIsValid(false);
    }
}

const std::string &Character::getName() const {
    return name;
}

int Character::getLeben() const {
    return leben;
}

int Character::getGold() const {
    return gold;
}

void Character::setLeben(int leben) {
    Character::leben = leben;
}

void Character::setGold(int gold) {
    Character::gold = gold;
}

int Character::addInventarItem(Item* item){
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget() == false){
            this->inventar[i].setBezeichnung( item->getBezeichnung()) ;
            this->inventar[i].setWert(item->getWert()) ;
            this->inventar[i].setIsValid(item->isValidget()) ;
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zum Inventar von "<< this->name <<" hinzugefuegt." << std::endl;
            return i+1;
        }
    }
    return -1;
}

Item Character::removeInventarItem(int slot){
    Item item;
    if (slot < 0 || slot > 10){
        return item;
    }
    if (this->inventar[slot].isValidget()== true){
        std::cout << "Gegenstand " << this->inventar[slot].getBezeichnung() << " wurde aus Inventar von " << this->name << " entfernt" << std::endl;
        item = this->inventar[slot];
        this->inventar[slot].initItem();
        return item;
    }
    return item;
}

Item Character::getInvenarItem(int slot) {
    return this->inventar[slot];
}

