#include "UI.h"

using namespace Hypex_Hypocycloid;

UI::UI() {
    this->hypocycloid = new Hypocycloid();
}

void UI::printMenu() {
    std::cout << "0) Exit" << std::endl;
    std::cout << "1) Set parameters" << std::endl;
    std::cout << "2) get radii" << std::endl;
    std::cout << "3) get Type of hypocycloid" << std::endl;
    std::cout << "4) get position by angle" << std::endl;
    std::cout << "5) get the radius of curvature" << std::endl;
    std::cout << "6) get the sectorial area of the hypocycloid by angle" << std::endl;
}

int UI::chooseAction(int start, int end) {
    int choice;
    std::string errMessage;
    errMessage = "";
    do {
        choice = getValue<int>();
        std::cout << errMessage << std::endl;
        errMessage = "Wrong input! Choice must be > 0 and < 6";
    } while (choice < start || choice > end);
    return choice;
}

void UI::setParameters() {
    double a, R, r;
    std::cout << "Enter parameters: R, r, a" << std::endl;
    std::cin >> R >> r >> a;
    this->hypocycloid->setRStationary(R);
    this->hypocycloid->setRMoving(r);
    this->hypocycloid->setA(a);
}

void UI::getType() {
    HypocycloidType::Type type = this->hypocycloid->getType();
    std::cout << "type: " << HypocycloidType::toString(type) << std::endl;
}

void UI::getPosition() {
    double t;
    std::cout << "Enter the angle" << std::endl;
    std::cin >> t;
    Position *pos = this->hypocycloid->getPosition(t);
    std::cout << "x: " << pos->x << " | y: " << pos->y << std::endl;
    delete pos;
}

void UI::getRadii() {
    std::cout << "R: " << this->hypocycloid->getRStationary() << " | r: " << this->hypocycloid->getRMoving()
              << std::endl;
}

void UI::getCurve() {
    double t;
    std::cout << "Enter the angle" << std::endl;
    std::cin >> t;
    std::cout << "Radius of curvature: " << this->hypocycloid->getCurve(t) << std::endl;
}

void UI::getSectorArea() {
    double t;
    std::cout << "Enter the angle" << std::endl;
    std::cin >> t;
    std::cout << "Sector area: " << this->hypocycloid->getSectorArea(t) << std::endl;
}

void UI::run() {
    int choice;
    do {
        printMenu();
        choice = chooseAction(0, 6);
        switch (choice) {
            case 0: {
                delete this->hypocycloid;
                break;
            }
            case 1: {
                setParameters();
                break;
            }
            case 2: {
                getRadii();
                break;
            }
            case 3: {
                getType();
                break;
            }
            case 4: {
                try {
                    getPosition();
                } catch (ParametersError &err) {
                    std::cout << "[ERROR] " << err.what() << std::endl;
                }
                break;
            }
            case 5: {
                try {
                    getCurve();
                } catch (ParametersError &err) {
                    std::cout << "[ERROR] " << err.what() << std::endl;
                }
                break;
            }
            case 6: {
                try {
                    getSectorArea();
                } catch (ParametersError &err) {
                    std::cout << "[ERROR] " << err.what() << std::endl;
                }
                break;
            }
            default: {
                break;
            }
        }
    } while (choice != 0);
}
