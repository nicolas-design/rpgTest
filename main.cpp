#include <iostream>
#include "hero.h"
#include "npc.h"
#include "item.h"
#include "sorcerer.h"
#include "fighter.h"
#include "exception.h"

int main() {
    try {
        Hero heros("Peter", 300, 100, 10, 10);


    try {
        sorcerer charakter("Paulo", 50, -10, 0, 10, 10);


        charakter.addInventarItem(new Item("Keule", -60));
        charakter.addInventarItem(new Item("Stift", 10));

        bool win = heros.fight(&charakter, &heros);
        if (win == false) {
            return 0;
        }

    } catch (std::exception &e){
        std::cerr << "Exception bei main: " << e.what() << std::endl;
    }

    try {
        sorcerer charakter("Bobo", 50, 10, 0, 10, 10);


        charakter.addInventarItem(new Item("Keule", 60));
        charakter.addInventarItem(new Item("Sift", 10));

        bool win = heros.fight(&charakter, &heros);
        if (win == false) {
            return 0;
        }

    } catch (std::exception &e){
        std::cerr << "Exception bei main: " << e.what() << std::endl;
    }

    try {
        Fighter Susi("Susi", 100, 100, 5, 0, 5);
        Susi.addInventarItem(new Item("Schwert", 100));

        bool win = heros.fight(&Susi, &heros);

        if (win == false) {
            return 0;
        }
    } catch (std::exception &e){
        std::cerr << "Exception bei main: " << e.what() << std::endl;
    }

    try {
        heros.sellItem(1);

        heros.sellItem(0);
    } catch (std::exception &e){
        std::cerr << "Exception bei main: " << e.what() << std::endl;
    }
    } catch (std::exception &e){
    std::cerr << "Exception bei main: " << e.what() << std::endl;
    return -1;
}


    return 0;
}
