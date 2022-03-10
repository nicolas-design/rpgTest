#include <iostream>
#include "item.h"


void Item::initItem(std::string name, int gold){
    this->bezeichnung = name;
    this->wert = gold;
    this->isValid = true;
}

void Item::initItem(){
    this->isValid = false;
}

const std::string &Item::getBezeichnung() const {
    return bezeichnung;
}

int Item::getWert() const {
    return wert;
}

bool Item::isValidget() const {
    return isValid;
}

void Item::setBezeichnung(const std::string &bezeichnung) {
    Item::bezeichnung = bezeichnung;
}

void Item::setWert(int wert) {
    Item::wert = wert;
}

void Item::setIsValid(bool isValid) {
    Item::isValid = isValid;
}
