#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

int main() {

    struct Hero_t heros;
    initHero(&heros, "Peter", 300, 100);

    struct Charakter_t charakter;
    initCharacter(&charakter, "Paulo", 50, 100);


    fight(&heros, &charakter);

    struct Item_t item;
    initItem(&item, "Schwert", 100);

    addItem(&heros, &item);

    initCharacter(&charakter, "Susi", 100, 100);

    fight(&heros, &charakter);

    initItem(&item, "Heiltrank", 50);

    addItem(&heros, &item);

    sellItem(&heros, 1);
    sellItem(&heros, 2);
    

    return 0;
}
