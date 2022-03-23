

#ifndef MDS2HW1_SORCERER_H
#define MDS2HW1_SORCERER_H
#include <iostream>
#include "npc.h"
class sorcerer : public Npc{
private:
    int magicPower;

public:
    int getMagicPower() const;

    virtual void attack(Character* hero) override;

    void setMagicPower(int magicPower);

    sorcerer(const std::string &name, int leben, int gold, int armor, int magicResistance, int magicPower);
};
#endif //MDS2HW1_SORCERER_H
