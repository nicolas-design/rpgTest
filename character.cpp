#include <iostream>
#include "character.h"
#include "item.h"

Character::Character(const std::string &name, int leben, int gold, int armor, int magicResistance) : name(name), leben(leben), gold(gold), armor(armor), magicResistance(magicResistance) {
    if (leben <= 0 || gold < 0 || armor < 0 || magicResistance < 0){
        throw NegativeNumberException("Character::Character: Bei der Initialisierung sollen keine negative Zahlen verwendet werden");
    }
    for (int i = 0; i < 10; ++i) {
        this->inventar[i]= nullptr;
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
    if (gold <0){
        throw NegativeNumberException("Gold kann keinen negativen Betrag haben");
    }
    Character::gold = gold;
}

int Character::addInventarItem(Item* item){
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i] == nullptr){
            this->inventar[i] = item;
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zum Inventar von "<< this->name <<" hinzugefuegt." << std::endl;
            return i;
        }
    }
    throw ArrayFullException("Charakter::addInventarItem(): Inventar ist voll");
}

Item* Character::removeInventarItem(int slot){
    Item *item;
    if (slot < 0 || slot > 9){
        throw InvalidIndexException("Character::removeInventarItem(): Index außerhalb vom Bereich 0-9");
    }
    if (this->inventar[slot] != nullptr){
        std::cout << "Gegenstand " << this->inventar[slot]->getBezeichnung() << " wurde aus Inventar von " << this->name << " entfernt" << std::endl;
        item = this->inventar[slot];
        this->inventar[slot] = nullptr;
        return item;
    }
    throw EmptyIndexException("Character::removeInventarItem(): Inventar Index ist leer ");
}

Item* Character::getInvenarItem(int slot) {
    if (slot < 0 || slot > 9){
        throw InvalidIndexException("Character::removeInventarItem(): Index außerhalb vom Bereich 0-9");
    };
    return this->inventar[slot];
}

int Character::randomNum(int unterGrenze, int oberGrenze){
    srand((unsigned) time(0));
    int ob = oberGrenze-unterGrenze;
    int num = unterGrenze + (rand() % ob);
    return num;
}

int Character::getArmor() const {
    return armor;
}

int Character::getMagicResistance() const {
    return magicResistance;
}


std::ostream& operator<<(std::ostream& out, const Character& c) {
    out << c.getName();
    return out;
}