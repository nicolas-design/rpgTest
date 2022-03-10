#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

int main() {

    Hero heros;
    heros.initHero("Peter", 300, 100);

    Charakter charakter;
    charakter.initCharacter("Paulo", 50, 100);

    bool win = heros.fight(&charakter, &heros);
    if (win == false){
        return 0;
    }

    Item item;
    item.initItem("Schwert", 100);

    heros.addItem(&item);

    charakter.initCharacter("Susi", 100, 100);

    win = heros.fight(&charakter, &heros);

    if (win == false){
        return 0;
    }

    item.initItem( "Heiltrank", 50);

    heros.addItem(&item);

    heros.sellItem( 1);
    heros.sellItem( 2);


    return 0;
}
