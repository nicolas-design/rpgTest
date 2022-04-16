#include <iostream>
#include "item.h"



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
    if (wert < 0){
        throw NegativeNumberException("Item::setWert(): Wert kann nicht negativ sein");
    }
    Item::wert = wert;
}

void Item::setIsValid(bool isValid) {
    Item::isValid = isValid;
}

Item::Item(const std::string &bezeichnung, int wert) : bezeichnung(bezeichnung), wert(wert) {
    if (wert < 0){
        throw NegativeNumberException("Item::Item(): Wert kann nicht negativ sein");
    }
    this->isValid = true;
}

Item::Item() {
    this->isValid = false;
}

std::ostream& operator<<(std::ostream& out, const Item& i) {
    out << i.getBezeichnung() << " (" << i.getWert() << " $)";
    return out;
}