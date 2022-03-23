
#ifndef MDS2HW1_HERO_H
#define MDS2HW1_HERO_H
#include <iostream>
#include "npc.h"
#include "item.h"
#include "charakter.h"

class Hero : public Character {
private:
    Item ausruestung[2];


public:

    Hero(const std::string &name, int leben, int gold, int armor, int magicResistance);

    virtual void attack(Character* enemy) override;

    void sellItem(const int index);

    bool fight(class Npc* enemy, class Hero* hero);

    int addEquipmentItem(const Item* item);

    Item removeEquipmentItem(int slot);

    virtual ~Hero();

};

#endif //MDS2HW1_HERO_H
