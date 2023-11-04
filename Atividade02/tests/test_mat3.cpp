#include "gtest/gtest.h"
#include "../includes/mat3.h"
#include "../includes/vec3.h"

TEST(Mat3Test, DefaultConstructor) {
    mat3 m;
    EXPECT_EQ(m[0].x(), 0.0);
    EXPECT_EQ(m[0].y(), 0.0);
    EXPECT_EQ(m[0].z(), 0.0);
    EXPECT_EQ(m[1].x(), 0.0);
    EXPECT_EQ(m[1].y(), 0.0);
    EXPECT_EQ(m[1].z(), 0.0);
    EXPECT_EQ(m[2].x(), 0.0);
    EXPECT_EQ(m[2].y(), 0.0);
    EXPECT_EQ(m[2].z(), 0.0);
}

TEST(Mat3Test, CustomConstructor) {
    vec3 row0(1.0, 2.0, 3.0);
    vec3 row1(4.0, 5.0, 6.0);
    vec3 row2(7.0, 8.0, 9.0);
    mat3 m(row0, row1, row2);
    EXPECT_EQ(m[0].x(), 1.0);
    EXPECT_EQ(m[0].y(), 2.0);
    EXPECT_EQ(m[0].z(), 3.0);
    EXPECT_EQ(m[1].x(), 4.0);
    EXPECT_EQ(m[1].y(), 5.0);
    EXPECT_EQ(m[1].z(), 6.0);
    EXPECT_EQ(m[2].x(), 7.0);
    EXPECT_EQ(m[2].y(), 8.0);
    EXPECT_EQ(m[2].z(), 9.0);
}

TEST(Mat3Test, OperatorIndex) {
    vec3 row0(1.0, 2.0, 3.0);
    vec3 row1(4.0, 5.0, 6.0);
    vec3 row2(7.0, 8.0, 9.0);
    mat3 m(row0, row1, row2);
    EXPECT_EQ(m[0].x(), 1.0);
    EXPECT_EQ(m[0].y(), 2.0);
    EXPECT_EQ(m[0].z(), 3.0);
    EXPECT_EQ(m[1].x(), 4.0);
    EXPECT_EQ(m[1].y(), 5.0);
    EXPECT_EQ(m[1].z(), 6.0);
    EXPECT_EQ(m[2].x(), 7.0);
    EXPECT_EQ(m[2].y(), 8.0);
    EXPECT_EQ(m[2].z(), 9.0);
}

TEST(Mat3Test, OperatorOutput) {
    vec3 row0(1.0, 2.0, 3.0);
    vec3 row1(4.0, 5.0, 6.0);
    vec3 row2(7.0, 8.0, 9.0);
    mat3 m(row0, row1, row2);
    std::ostringstream out;
    out << m;
    std::string expected_output = "1 2 3\n4 5 6\n7 8 9\n";
    EXPECT_EQ(out.str(), expected_output);
}