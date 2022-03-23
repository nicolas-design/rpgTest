//
// Created by gadne on 23.03.2022.
//

#ifndef MDS2HW1_FIGHTER_H
#define MDS2HW1_FIGHTER_H
#include <iostream>
#include "npc.h"

class Fighter : public Npc{
private:
    int strength;

public:
    int getStrength() const;

    void setStrength(int strength);

    virtual void attack(Character* hero) override;

    Fighter(const std::string &name, int leben, int gold, int armor, int magicResistance, int strength);
};
#endif //MDS2HW1_FIGHTER_H
