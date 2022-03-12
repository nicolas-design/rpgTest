#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

int main() {

    Hero heros;
    heros.initHero("Peter", 300, 100);

    Charakter charakter;
    charakter.initCharacter("Paulo", 50, 100);

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

    charakter.initCharacter("Susi", 100, 100);
    charakter.addInventarItem(&item);

    win = heros.fight(&charakter, &heros);

    if (win == false){
        return 0;
    }


    heros.sellItem( 1);

    heros.sellItem( 0);


    return 0;
}
