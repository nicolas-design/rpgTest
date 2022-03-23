
#ifndef MDS2HW1_NPC_H
#define MDS2HW1_NPC_H
#include <iostream>
#include "hero.h"
#include "item.h"
#include "charakter.h"

class Npc : public Character {
private:


public:

    Npc(const std::string &name, int leben, int gold, int armor, int magicResistance);

    virtual void attack(Character* hero) override;

    int getRandomItemSlot();
};




#endif //MDS2HW1_NPC_H
