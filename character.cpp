#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "hero.h"
#include "item.h"



void Charakter::initCharacter(const std::string name, int health, int gold){
    this->name=name;
    this->leben=health;
    this->gold= gold;
    for (int i = 0; i < 10; ++i) {
        this->inventar[i].setIsValid(false);
    }
}

void Charakter::attack(class Hero* hero){
    srand((unsigned) time(0));
    int num = 5 + (rand() % 10);
    int leben = hero->getLeben()-num;
    hero->setLeben(leben);
    std::cout << this->name << " trifft " << hero->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

int Charakter::addInventarItem(Item* item){
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget() == false){
            this->inventar[i].setBezeichnung( item->getBezeichnung()) ;
            this->inventar[i].setWert(item->getWert()) ;
            this->inventar[i].setIsValid(item->isValidget()) ;
            std::cout << "Gegenstand " << item->getBezeichnung() << " wurde zum Inventar von Feind "<< this->name <<" hinzugefuegt." << std::endl;
            return i+1;
        }
    }
    return -1;
}

Item Charakter::removeInventarItem(int slot){
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


int Charakter::getLeben() const {
    return leben;
}

void Charakter::setLeben(int leben) {
    Charakter::leben = leben;
}

const std::string &Charakter::getName() const {
    return name;
}

int Charakter::getRandomItemSlot(){
    int arrCount=0;
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget()== true){
            arrCount++;
        }
    }
    if (arrCount == 0){
        return -1;
    }
    int arr[arrCount];
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (this->inventar[i].isValidget()== true){
            arr[count] = i;
            count++;
        }
    }
    int num = 0;
    if (arrCount > 1) {
        srand((unsigned) time(0));
        num = rand() % (arrCount);
    }

    return arr[num];
}
