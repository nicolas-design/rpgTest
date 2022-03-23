#include <iostream>
#include "hero.h"
#include "npc.h"
#include "item.h"
#include "sorcerer.h"
#include "fighter.h"

int main() {

    Hero heros("Peter", 300, 100, 10, 10);


    sorcerer charakter("Paulo", 50, 100, 0, 10, 10);


    Item buch;
    buch.initItem("Comic", 20);

    Item trank;
    trank.initItem("Trank", 50);

    charakter.addInventarItem(&trank);
    charakter.addInventarItem(&buch);

    bool win = heros.fight(&charakter, &heros);
    if (win == false){
        return 0;
    }

    Item item;
    item.initItem("Schwert", 100);

    Fighter Susi("Susi", 100, 100, 5, 0, 5);
    Susi.addInventarItem(&item);

    win = heros.fight(&Susi, &heros);

    if (win == false){
        return 0;
    }


    heros.sellItem( 1);

    heros.sellItem( 0);


    return 0;
}
