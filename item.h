
#ifndef MDS2HW1_ITEM_H
#define MDS2HW1_ITEM_H
#include <iostream>

struct Item_t {
    std::string bezeichnung;
    int wert;
    bool isValid;
};

void initItem(struct Item_t* item, char* name, int gold);

void initItem(struct Item_t* gegenstand);

#endif //MDS2HW1_ITEM_H
