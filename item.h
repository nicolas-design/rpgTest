
#ifndef MDS2HW1_ITEM_H
#define MDS2HW1_ITEM_H
#include <iostream>
#include "exception.h"


class Item {
private:
    std::string bezeichnung;
    int wert;
    bool isValid;

public:
    Item(const std::string &bezeichnung, int wert);

    Item();


    const std::string &getBezeichnung() const;

    int getWert() const;

    bool isValidget() const;

    void setBezeichnung(const std::string &bezeichnung);

    void setWert(int wert);

    void setIsValid(bool isValid);
};

std::ostream& operator<<(std::ostream& out, const Item& i);

#endif //MDS2HW1_ITEM_H
