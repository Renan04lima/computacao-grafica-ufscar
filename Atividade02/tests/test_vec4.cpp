#include "gtest/gtest.h"
#include "../includes/vec4.h"

TEST(Vec4Test, DefaultConstructor) {
    vec4 v;
    EXPECT_EQ(v.x(), 0.0);
    EXPECT_EQ(v.y(), 0.0);
    EXPECT_EQ(v.z(), 0.0);
    EXPECT_EQ(v.w, 1.0);
}

TEST(Vec4Test, CustomConstructor) {
    vec4 v(1.0, 2.0, 3.0, 4.0);
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 2.0);
    EXPECT_EQ(v.z(), 3.0);
    EXPECT_EQ(v.w, 4.0);
}

TEST(Vec4Test, CopyConstructor) {
    vec4 v1(1.0, 2.0, 3.0, 4.0);
    vec4 v2(v1);
    EXPECT_EQ(v2.x(), 1.0);
    EXPECT_EQ(v2.y(), 2.0);
    EXPECT_EQ(v2.z(), 3.0);
    EXPECT_EQ(v2.w, 4.0);
}

TEST(Vec4Test, EqualityOperator) {
    vec4 v1(1.0, 2.0, 3.0, 4.0);
    vec4 v2(1.0, 2.0, 3.0, 4.0);
    vec4 v3(2.0, 3.0, 4.0, 5.0);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}