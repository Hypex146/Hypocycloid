#ifndef HYPEX_HYPOCYCLOID_H
#define HYPEX_HYPOCYCLOID_H

#include <iostream>
#include <cmath>

namespace Hypex_Hypocycloid {

    typedef struct Position {
        double x, y;

        Position(double x, double y);

        Position();

        ~Position() = default;
    } Position;


    class ParametersError : public std::exception {
    private:
        std::string messageError;
    public:
        explicit ParametersError(const std::string &messageError);

        [[nodiscard]] const char *what() const noexcept override;
    };


    class HypocycloidType {
    public:
        enum Type {
            NORMAL,
            SHORTENED,
            ELONGATED,
        };

        static std::string toString(HypocycloidType::Type type);
    };


    class Hypocycloid {
    private:
        double rStationary, rMoving, a;

        HypocycloidType::Type type;

        void updateType();

        void checkParameters() const;

    public:
        Hypocycloid();

        Hypocycloid(double rStationary, double rMoving, double a = 1);

        Hypocycloid(const Hypocycloid &object) = default;

        Hypocycloid& operator=(const Hypocycloid &object) = default;

        virtual ~Hypocycloid() = default;

        [[nodiscard]] double getRStationary() const;

        void setRStationary(double newValue);

        [[nodiscard]] double getRMoving() const;

        void setRMoving(double newValue);

        [[nodiscard]] double getA() const;

        void setA(double newValue);

        [[nodiscard]] HypocycloidType::Type getType() const;

        [[nodiscard]] Position *getPosition(double t) const;

        [[nodiscard]] double getCurve(double t) const;

        [[nodiscard]] double getSectorArea(double t) const;

    };

}

#endif //HYPEX_HYPOCYCLOID_H
