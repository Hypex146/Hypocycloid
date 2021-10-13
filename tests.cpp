#include <gtest/gtest.h>
#include "Hypocycloid.h"

using namespace Hypex_Hypocycloid;

class HypocycloidTests : public ::testing::Test {
protected:
    Hypocycloid *hypocycloid;

    void SetUp() override {
        hypocycloid = new Hypocycloid();
    }

    void TearDown() override {
        delete hypocycloid;
    }

    void setParameters(double R, double r, double a) {
        hypocycloid->setRStationary(R);
        hypocycloid->setRMoving(r);
        hypocycloid->setA(a);
    }

public:
    ~HypocycloidTests() override = default;

};

TEST(HypocycloidTypeTests, typeToString) {
    EXPECT_EQ(HypocycloidType::toString(HypocycloidType::ELONGATED), "Elongated");
    EXPECT_EQ(HypocycloidType::toString(HypocycloidType::NORMAL), "Normal");
    EXPECT_EQ(HypocycloidType::toString(HypocycloidType::SHORTENED), "Shortened");
}

TEST(HypocycloidConstructorTests, ZeroParameter) {
    Hypocycloid hypocycloid;
    EXPECT_EQ(hypocycloid.getRStationary(), 0);
    EXPECT_EQ(hypocycloid.getRMoving(), 0);
    EXPECT_EQ(hypocycloid.getA(), 1);
    EXPECT_EQ(hypocycloid.getType(), HypocycloidType::NORMAL);
}

TEST(HypocycloidConstructorTests, TreeParameter_1) {
    Hypocycloid hypocycloid = Hypocycloid(0, 0, 1);
    EXPECT_EQ(hypocycloid.getRStationary(), 0);
    EXPECT_EQ(hypocycloid.getRMoving(), 0);
    EXPECT_EQ(hypocycloid.getA(), 1);
    EXPECT_EQ(hypocycloid.getType(), HypocycloidType::NORMAL);
}

TEST(HypocycloidConstructorTests, TreeParameter_2) {
    Hypocycloid hypocycloid = Hypocycloid(4, 2, 3);
    EXPECT_EQ(hypocycloid.getRStationary(), 4);
    EXPECT_EQ(hypocycloid.getRMoving(), 2);
    EXPECT_EQ(hypocycloid.getA(), 3);
    EXPECT_EQ(hypocycloid.getType(), HypocycloidType::ELONGATED);
}

TEST(HypocycloidConstructorTests, TreeParameter_3) {
    Hypocycloid hypocycloid = Hypocycloid(6.9, 2.5, 0.2);
    EXPECT_EQ(hypocycloid.getRStationary(), 6.9);
    EXPECT_EQ(hypocycloid.getRMoving(), 2.5);
    EXPECT_EQ(hypocycloid.getA(), 0.2);
    EXPECT_EQ(hypocycloid.getType(), HypocycloidType::SHORTENED);
}

TEST(HypocycloidConstructorTests, СopyСonstructor_1) {
    Hypocycloid hypocycloid = Hypocycloid(6.9, 2.5, 0.2);
    Hypocycloid copy = Hypocycloid(hypocycloid);
    EXPECT_EQ(copy.getRStationary(), 6.9);
    EXPECT_EQ(copy.getRMoving(), 2.5);
    EXPECT_EQ(copy.getA(), 0.2);
    EXPECT_EQ(copy.getType(), HypocycloidType::SHORTENED);
}

TEST(HypocycloidConstructorTests, СopyСonstructor_2) {
    Hypocycloid hypocycloid = Hypocycloid(0.6, 12, 4);
    Hypocycloid copy = Hypocycloid(hypocycloid);
    EXPECT_EQ(copy.getRStationary(), 0.6);
    EXPECT_EQ(copy.getRMoving(), 12);
    EXPECT_EQ(copy.getA(), 4);
    EXPECT_EQ(copy.getType(), HypocycloidType::ELONGATED);
}

TEST(HypocycloidConstructorTests, СopyСonstructor_3) {
    Hypocycloid hypocycloid;
    Hypocycloid copy = Hypocycloid(hypocycloid);
    EXPECT_EQ(copy.getRStationary(), 0);
    EXPECT_EQ(copy.getRMoving(), 0);
    EXPECT_EQ(copy.getA(), 1);
    EXPECT_EQ(copy.getType(), HypocycloidType::NORMAL);
}

TEST(HypocycloidOperatorTests, СopyOperator_1) {
    Hypocycloid hypocycloid;
    Hypocycloid copy = Hypocycloid(5, 5, 5);
    copy = hypocycloid;
    EXPECT_EQ(copy.getRStationary(), 0);
    EXPECT_EQ(copy.getRMoving(), 0);
    EXPECT_EQ(copy.getA(), 1);
    EXPECT_EQ(copy.getType(), HypocycloidType::NORMAL);
}

TEST(HypocycloidOperatorTests, СopyOperator_2) {
    Hypocycloid hypocycloid = Hypocycloid(5, 5, 5);
    Hypocycloid copy = Hypocycloid();
    copy = hypocycloid;
    EXPECT_EQ(copy.getRStationary(), 5);
    EXPECT_EQ(copy.getRMoving(), 5);
    EXPECT_EQ(copy.getA(), 5);
    EXPECT_EQ(copy.getType(), HypocycloidType::ELONGATED);
}

TEST(HypocycloidOperatorTests, СopyOperator_3) {
    Hypocycloid hypocycloid = Hypocycloid(7, 0.4, 0.5);
    Hypocycloid copy = Hypocycloid(5, 5, 5);
    copy = hypocycloid;
    EXPECT_EQ(copy.getRStationary(), 7);
    EXPECT_EQ(copy.getRMoving(), 0.4);
    EXPECT_EQ(copy.getA(), 0.5);
    EXPECT_EQ(copy.getType(), HypocycloidType::SHORTENED);
}

TEST_F(HypocycloidTests, GetterSetter_1) {
    hypocycloid->setRStationary(3);
    hypocycloid->setRMoving(2);
    hypocycloid->setA(8);
    EXPECT_EQ(hypocycloid->getRStationary(), 3);
    EXPECT_EQ(hypocycloid->getRMoving(), 2);
    EXPECT_EQ(hypocycloid->getA(), 8);
}

TEST_F(HypocycloidTests, GetterSetter_2) {
    hypocycloid->setRStationary(0.4);
    hypocycloid->setRMoving(1);
    hypocycloid->setA(-0.5);
    EXPECT_EQ(hypocycloid->getRStationary(), 0.4);
    EXPECT_EQ(hypocycloid->getRMoving(), 1);
    EXPECT_EQ(hypocycloid->getA(), -0.5);
}

TEST_F(HypocycloidTests, GetterSetter_3) {
    hypocycloid->setRStationary('a');
    hypocycloid->setRMoving('r');
    hypocycloid->setA('h');
    EXPECT_EQ(hypocycloid->getRStationary(), 97);
    EXPECT_EQ(hypocycloid->getRMoving(), 114);
    EXPECT_EQ(hypocycloid->getA(), 104);
}


TEST_F(HypocycloidTests, GetType_1) {
    setParameters(1, 1, 1);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::NORMAL);
    hypocycloid->setA(1.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::ELONGATED);
}

TEST_F(HypocycloidTests, GetType_2) {
    setParameters(1, 1, 1.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::ELONGATED);
    hypocycloid->setA(0.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
}

TEST_F(HypocycloidTests, GetType_3) {
    setParameters(1, 1, 0.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
    hypocycloid->setA(0);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
}

TEST_F(HypocycloidTests, GetType_4) {
    setParameters(1, 1, 0);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
    hypocycloid->setA(-0.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
}

TEST_F(HypocycloidTests, GetType_5) {
    setParameters(1, 1, -0.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::SHORTENED);
    hypocycloid->setA(-1);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::NORMAL);
}

TEST_F(HypocycloidTests, GetType_6) {
    setParameters(1, 1, -1);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::NORMAL);
    hypocycloid->setA(-1.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::ELONGATED);
}

TEST_F(HypocycloidTests, GetType_7) {
    setParameters(1, 1, -1.5);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::ELONGATED);
    hypocycloid->setA(1);
    EXPECT_EQ(hypocycloid->getType(), HypocycloidType::NORMAL);
}


TEST_F(HypocycloidTests, GetPosition_1) {
    setParameters(3, 1, 1);
    double angle = 1;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 0.664, 0.001);
    EXPECT_NEAR(y, 0.773, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_2) {
    setParameters(3, 1, 1);
    double angle = 2;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -1.485, 0.001);
    EXPECT_NEAR(y, 2.575, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_3) {
    setParameters(3, 1, 1);
    double angle = 0;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 3.0, 0.001);
    EXPECT_NEAR(y, 0.0, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_4) {
    setParameters(3, 1, 1);
    double angle = -1.5;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -0.848, 0.001);
    EXPECT_NEAR(y, -1.853, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_5) {
    setParameters(3, 1, 0.5);
    double angle = 0;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 2.5, 0.001);
    EXPECT_NEAR(y, 0, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_6) {
    setParameters(3, 1, 0.5);
    double angle = -5;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 0.147, 0.001);
    EXPECT_NEAR(y, 1.645, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_7) {
    setParameters(3, 1, 0.5);
    double angle = -5;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 0.147, 0.001);
    EXPECT_NEAR(y, 1.645, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_8) {
    setParameters(3, 1, 0.5);
    double angle = 2.48;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -1.455, 0.001);
    EXPECT_NEAR(y, 1.713, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_9) {
    setParameters(3, 1, 1.7);
    double angle = 3.31;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -0.367, 0.001);
    EXPECT_NEAR(y, -0.897, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_10) {
    setParameters(3, 1, 3.74);
    double angle = -2.92;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 1.427, 0.001);
    EXPECT_NEAR(y, -2.043, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_11) {
    setParameters(3, 1, -0.15);
    double angle = 18.55;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 1.787, 0.001);
    EXPECT_NEAR(y, -0.674, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_12) {
    setParameters(3, 1, 0);
    double angle = 0.34;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 1.885, 0.001);
    EXPECT_NEAR(y, 0.666, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_13) {
    setParameters(4, 3, 1.5);
    double angle = 0.14;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, 5.485, 0.001);
    EXPECT_NEAR(y, -0.070, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_14) {
    setParameters(3, 4, 1.5);
    double angle = -7.18;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -1.958, 0.001);
    EXPECT_NEAR(y, -5.068, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetPosition_15) {
    setParameters(8, 3, -2.79);
    double angle = 15.15;
    Position *position = hypocycloid->getPosition(angle);
    double x = position->x, y = position->y;
    EXPECT_NEAR(x, -12.554, 0.001);
    EXPECT_NEAR(y, 3.626, 0.001);
    delete position;
}

TEST_F(HypocycloidTests, GetCurve_1) {
    setParameters(8, 3, -2.79);
    double angle = 15.15;
    double rCurve = hypocycloid->getCurve(angle);
    EXPECT_NEAR(rCurve, 3.510, 0.001);
}

TEST_F(HypocycloidTests, GetCurve_2) {
    setParameters(4, 1, 7.58);
    double angle = 1.5;
    double rCurve = hypocycloid->getCurve(angle);
    EXPECT_NEAR(rCurve, 5.564, 0.001);
}

TEST_F(HypocycloidTests, GetCurve_3) {
    setParameters(2, 8, -1.2);
    double angle = 75.6;
    double rCurve = hypocycloid->getCurve(angle);
    EXPECT_NEAR(rCurve, 15.279, 0.001);
}

TEST_F(HypocycloidTests, GetCurve_4) {
    setParameters(5.2, 1.2, 42);
    double angle = 4.89;
    double rCurve = hypocycloid->getCurve(angle);
    EXPECT_NEAR(rCurve, 52.370, 0.001);
}

TEST_F(HypocycloidTests, GetCurve_5) {
    setParameters(1, 4.5, 0.33);
    double angle = -41.23;
    double rCurve = hypocycloid->getCurve(angle);
    EXPECT_NEAR(rCurve, 4.891, 0.001);
}

TEST_F(HypocycloidTests, GetSectorArea_1) {
    setParameters(1, 4.5, 0.33);
    double angle = -41.23;
    double area = hypocycloid->getSectorArea(angle);
    EXPECT_NEAR(area, 282.496, 0.001);
}

TEST_F(HypocycloidTests, GetSectorArea_2) {
    setParameters(7, 4.9, 1);
    double angle = 1.58;
    double area = hypocycloid->getSectorArea(angle);
    EXPECT_NEAR(area, 3.053, 0.001);
}

TEST_F(HypocycloidTests, GetSectorArea_3) {
    setParameters(3, 14, 0.58);
    double angle = 71.59;
    double area = hypocycloid->getSectorArea(angle);
    EXPECT_NEAR(area, 6051.95, 0.001);
}

TEST_F(HypocycloidTests, GetSectorArea_4) {
    setParameters(5, 4.5, 1.85);
    double angle = -6.24;
    double area = hypocycloid->getSectorArea(angle);
    EXPECT_NEAR(area, 22.238, 0.001);
}

TEST_F(HypocycloidTests, GetSectorArea_5) {
    setParameters(18, 4, 5.74);
    double angle = -0.94;
    double area = hypocycloid->getSectorArea(angle);
    EXPECT_NEAR(area, 695.96, 0.001);
}

TEST_F(HypocycloidTests, CatchThrow_1) {
    setParameters(0, 1, 1);
    ASSERT_THROW(hypocycloid->getCurve(0), ParametersError);
}

TEST_F(HypocycloidTests, CatchThrow_2) {
    setParameters(1, 0, 1);
    ASSERT_THROW(hypocycloid->getCurve(0), ParametersError);
}

TEST_F(HypocycloidTests, CatchThrow_3) {
    setParameters(5, 5, 1);
    ASSERT_THROW(hypocycloid->getCurve(0), ParametersError);
}

TEST_F(HypocycloidTests, CatchThrow_4) {
    setParameters(0, 0, 1);
    ASSERT_THROW(hypocycloid->getCurve(0), ParametersError);
}

TEST_F(HypocycloidTests, CatchThrow_5) {
    setParameters(-5, 1, 1);
    ASSERT_THROW(hypocycloid->getCurve(0), ParametersError);
}
