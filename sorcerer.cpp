//
// Created by gadne on 23.03.2022.
//

#include "sorcerer.h"

int sorcerer::getMagicPower() const {
    return magicPower;
}

void sorcerer::setMagicPower(int magicPower) {
    if (magicPower < 0){
        throw NegativeNumberException("Sorcerer::setMagicPower(): Wert kann nicht negativ sein");
    }
    sorcerer::magicPower = magicPower;
}

void sorcerer::attack(class Character* hero){
    int num = this->randomNum(5, 10);
    num = (num + this->getMagicPower()) - hero->getMagicResistance();
    if (num < 0){
        num = 0;
    }
    int leben = hero->getLeben()-num;
    hero->setLeben(leben);
    std::cout << *this << " trifft " << hero->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

sorcerer::sorcerer(const std::string &name, int leben, int gold, int armor, int magicResistance, int magicPower) : Npc(
        name, leben, gold, armor, magicResistance), magicPower(magicPower) {
    if (magicPower < 0){
        throw NegativeNumberException("Sorcerer::Sorcerer(): Wert kann nicht negativ sein");
    }
}
