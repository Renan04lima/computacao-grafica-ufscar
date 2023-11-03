#include "gtest/gtest.h"
#include "../includes/vec3.h"

TEST(Vec3Test, DefaultConstructor) {
    vec3 v;
    EXPECT_EQ(v.x(), 0.0);
    EXPECT_EQ(v.y(), 0.0);
    EXPECT_EQ(v.z(), 0.0);
}

TEST(Vec3Test, CustomConstructor) {
    vec3 v(1.0, 2.0, 3.0);
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 2.0);
    EXPECT_EQ(v.z(), 3.0);
}

TEST(Vec3Test, OperatorMinus) {
    vec3 v(1.0, 2.0, 3.0);
    vec3 neg_v = -v;
    EXPECT_EQ(neg_v.x(), -1.0);
    EXPECT_EQ(neg_v.y(), -2.0);
    EXPECT_EQ(neg_v.z(), -3.0);
}

TEST(Vec3Test, OperatorIndex) {
    vec3 v(1.0, 2.0, 3.0);
    EXPECT_EQ(v[0], 1.0);
    EXPECT_EQ(v[1], 2.0);
    EXPECT_EQ(v[2], 3.0);
}

TEST(Vec3Test, OperatorPlusEquals) {
    vec3 v1(1.0, 2.0, 3.0);
    vec3 v2(4.0, 5.0, 6.0);
    v1 += v2;
    EXPECT_EQ(v1.x(), 5.0);
    EXPECT_EQ(v1.y(), 7.0);
    EXPECT_EQ(v1.z(), 9.0);
}

TEST(Vec3Test, OperatorTimesEquals) {
    vec3 v(1.0, 2.0, 3.0);
    v *= 2.0;
    EXPECT_EQ(v.x(), 2.0);
    EXPECT_EQ(v.y(), 4.0);
    EXPECT_EQ(v.z(), 6.0);
}

TEST(Vec3Test, OperatorDivideEquals) {
    vec3 v(2.0, 4.0, 6.0);
    v /= 2.0;
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 2.0);
    EXPECT_EQ(v.z(), 3.0);
}

TEST(Vec3Test, Length) {
    vec3 v(1.0, 2.0, 2.0);
    EXPECT_EQ(v.length(), 3.0);
}

TEST(Vec3Test, LengthSquared) {
    vec3 v(1.0, 2.0, 2.0); 
    EXPECT_EQ(v.length_squared(), 9.0);
}



