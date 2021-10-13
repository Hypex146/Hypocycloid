#include "Hypocycloid.h"

using namespace Hypex_Hypocycloid;

Position::Position(double x, double y) {
    this->x = x;
    this->y = y;
}

Position::Position() {
    this->x = 0;
    this->y = 0;
}

ParametersError::ParametersError(const std::string &messageError) {
    this->messageError = messageError;
}

const char *ParametersError::what() const noexcept {
    return this->messageError.c_str();
}

std::string HypocycloidType::toString(HypocycloidType::Type type) {
    std::string string;
    switch (type) {
        case NORMAL: {
            string = "Normal";
            break;
        }
        case SHORTENED: {
            string = "Shortened";
            break;
        }
        case ELONGATED: {
            string = "Elongated";
            break;
        }
    }
    return string;
}

Hypocycloid::Hypocycloid() {
    this->rStationary = 0;
    this->rMoving = 0;
    this->a = 1;
    this->type = HypocycloidType::NORMAL;
}

Hypocycloid::Hypocycloid(double rStationary, double rMoving, double a) {
    this->rStationary = rStationary;
    this->rMoving = rMoving;
    this->a = a;
    this->type = HypocycloidType::NORMAL;
    updateType();
}

void Hypocycloid::updateType() {
    if (std::abs(getA()) < 1) { this->type = HypocycloidType::SHORTENED; }
    else if (std::abs(getA()) > 1) { this->type = HypocycloidType::ELONGATED; }
    else { this->type = HypocycloidType::NORMAL; }
}

double Hypocycloid::getRMoving() const {
    return this->rMoving;
}

double Hypocycloid::getRStationary() const {
    return this->rStationary;
}

double Hypocycloid::getA() const {
    return this->a;
}

void Hypocycloid::setRMoving(double newValue) {
    this->rMoving = newValue;
}

void Hypocycloid::setRStationary(double newValue) {
    this->rStationary = newValue;
}

void Hypocycloid::setA(double newValue) {
    this->a = newValue;
    updateType();
}

HypocycloidType::Type Hypocycloid::getType() const {
    return this->type;
}

void Hypocycloid::checkParameters() const {
    if (getRMoving() <= 0 || getRStationary() <= 0) { throw ParametersError("Error in parameters! R or r <= 0"); }
    if (getRMoving() == getRStationary()) { throw ParametersError("Error in parameters! R = r"); }
}

Position *Hypocycloid::getPosition(double t) const {
    checkParameters();
    auto *position = new Position();
    double k = getRStationary() / getRMoving();
    double r = getRMoving();
    position->x = r * (k - 1) * (cos(t) + a * cos((k - 1) * t) / (k - 1));
    position->y = r * (k - 1) * (sin(t) - a * sin((k - 1) * t) / (k - 1));
    return position;
}

double Hypocycloid::getCurve(double t) const {
    checkParameters();
    double r = getRMoving();
    double R = getRStationary();
    double d = getA() * getRMoving();
    double rCurve;
    rCurve = (R - r) * pow((pow(r, 2) + pow(d, 2) - 2 * d * r * cos((R * t) / (-r))), 1.5);
    rCurve /= std::abs(pow(-r, 3) + pow(d, 2) * (R - r) - d * r * (R - 2 * r) * cos((R * t) / (-r)));
    return std::abs(rCurve);
}

double Hypocycloid::getSectorArea(double t) const {
    checkParameters();
    double r = getRMoving();
    double R = getRStationary();
    double d = getA() * getRMoving();
    double S;
    S = (R - r) / 2;
    S *= (R - r + (pow(d, 2) / (-r))) * t - ((-d * (R - 2 * r)) / R) * sin((R * t) / (-r));
    return std::abs(S);
}

