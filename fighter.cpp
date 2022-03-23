#include "fighter.h"

int Fighter::getStrength() const {
    return strength;
}

void Fighter::setStrength(int strength) {
    Fighter::strength = strength;
}

void Fighter::attack(class Character* hero){
    int num = this->randomNum(5, 10);
    num = (num + this->getStrength()) - hero->getArmor();
    if (num < 0){
        num = 0;
    }
    int leben = hero->getLeben()-num;
    hero->setLeben(leben);
    std::cout << this->getName() << " trifft " << hero->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}

Fighter::Fighter(const std::string &name, int leben, int gold, int armor, int magicResistance, int strength) : Npc(name,
                                                                                                                   leben,
                                                                                                                   gold,
                                                                                                                   armor,
                                                                                                                   magicResistance),
                                                                                                               strength(
                                                                                                                       strength) {}

