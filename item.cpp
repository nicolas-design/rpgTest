#include <iostream>
#include "item.h"

struct Item_t item;

void initItem(struct Item_t* item, char* name, int gold){
    item->bezeichnung= name;
    item->wert = gold;
    item->isValid = true;
}

void initItem(struct Item_t* gegenstand){
    gegenstand->isValid = false;
}