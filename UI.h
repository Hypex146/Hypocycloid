//
// Created by vlad_ on 12.09.2021.
//

#ifndef LAB_2_UI_H
#define LAB_2_UI_H

#include <iostream>
#include "Hypocycloid.h"

class UI {
private:
    Hypex_Hypocycloid::Hypocycloid *hypocycloid;

    static void printMenu();

    int chooseAction(int start, int end);

    void setParameters();

    void getType();

    void getPosition();

    void getCurve();

    void getRadii();

    void getSectorArea();

    template<typename T>
    int getValueOnce(T *value) {
        std::cin >> *value;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore();
            return -1;
        }
        return 0;
    }

    template<typename T>
    T getValue() {
        T value;
        while (getValueOnce(&value) != 0) {
            std::cout << "Wrong input!" << std::endl;
        }
        return value;
    }

public:
    UI();

    ~UI() = default;

    void run();

};


#endif //LAB_2_UI_H
