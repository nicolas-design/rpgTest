
#ifndef MDS2HW1_ITEM_H
#define MDS2HW1_ITEM_H
#include <iostream>


class Item {
private:
    std::string bezeichnung;
    int wert;
    bool isValid;

public:
    void initItem(std::string name, int gold);

    void initItem();

    const std::string &getBezeichnung() const;

    int getWert() const;

    bool isValidget() const;

    void setBezeichnung(const std::string &bezeichnung);

    void setWert(int wert);

    void setIsValid(bool isValid);
};



#endif //MDS2HW1_ITEM_H
