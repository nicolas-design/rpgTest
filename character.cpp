#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "hero.h"
#include "item.h"



void Charakter::initCharacter(std::string name, int health, int gold){
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

int Charakter::getLeben() const {
    return leben;
}

void Charakter::setLeben(int leben) {
    Charakter::leben = leben;
}

const std::string &Charakter::getName() const {
    return name;
}
