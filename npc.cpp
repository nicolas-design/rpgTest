#include <iostream>
#include <cstdlib>
#include <ctime>
#include "npc.h"
#include "hero.h"
#include "item.h"


void Npc::attack(class Character* hero){
    srand((unsigned) time(0));
    int num = 5 + (rand() % 10);
    int leben = hero->getLeben()-num;
    hero->setLeben(leben);
    std::cout << this->getName() << " trifft " << hero->getName() << " fuer " << num << " Lebenspunkte." << std::endl;
}




int Npc::retrieveRandomLoot(){
    int arrCount=0;
    for (int i = 0; i < 10; ++i) {
        if (this->getInvenarItem(i).isValidget()== true){
            arrCount++;
        }
    }
    if (arrCount == 0){
        return -1;
    }
    int arr[arrCount];
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (this->getInvenarItem(i).isValidget()== true){
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

Npc::Npc(const std::string &name, int leben, int gold, int armor, int magicResistance) : Character(name, leben, gold, armor, magicResistance) {}

Npc::~Npc() {
}
