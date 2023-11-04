#include "gtest/gtest.h"
#include "../includes/vec2.h"

TEST(Vec2Test, DefaultConstructor) {
    vec2 v;
    EXPECT_EQ(v.x(), 0.0);
    EXPECT_EQ(v.y(), 0.0);
}

TEST(Vec2Test, CustomConstructor) {
    vec2 v(1.0, 2.0);
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 2.0);
}

TEST(Vec2Test, OperatorMinus) {
    vec2 v(1.0, 2.0);
    vec2 neg_v = -v;
    EXPECT_EQ(neg_v.x(), -1.0);
    EXPECT_EQ(neg_v.y(), -2.0);
}

TEST(Vec2Test, OperatorIndex) {
    vec2 v(1.0, 2.0);
    EXPECT_EQ(v[0], 1.0);
    EXPECT_EQ(v[1], 2.0);
}

TEST(Vec2Test, OperatorPlusEquals) {
    vec2 v1(1.0, 2.0);
    vec2 v2(3.0, 4.0);
    v1 += v2;
    EXPECT_EQ(v1.x(), 4.0);
    EXPECT_EQ(v1.y(), 6.0);
}

TEST(Vec2Test, OperatorTimesEquals) {
    vec2 v(1.0, 2.0);
    v *= 2.0;
    EXPECT_EQ(v.x(), 2.0);
    EXPECT_EQ(v.y(), 4.0);
}

TEST(Vec2Test, OperatorDivideEquals) {
    vec2 v(2.0, 4.0);
    v /= 2.0;
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 2.0);
}

TEST(Vec2Test, Length) {
    vec2 v(3.0, 4.0);
    EXPECT_EQ(v.length(), 5.0);
}

TEST(Vec2Test, LengthSquared) {
    vec2 v(3.0, 4.0); 
    EXPECT_EQ(v.length_squared(), 25.0);
}