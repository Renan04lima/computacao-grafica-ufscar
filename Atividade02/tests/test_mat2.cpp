#include "gtest/gtest.h"
#include "../includes/mat2.h"
#include "../includes/vec2.h"

TEST(Mat2Test, DefaultConstructor) {
    mat2 m;
    EXPECT_EQ(m[0].x(), 0.0);
    EXPECT_EQ(m[0].y(), 0.0);
    EXPECT_EQ(m[1].x(), 0.0);
    EXPECT_EQ(m[1].y(), 0.0);
}

TEST(Mat2Test, CustomConstructor) {
    vec2 row0(1.0, 2.0);
    vec2 row1(3.0, 4.0);
    mat2 m(row0, row1);
    EXPECT_EQ(m[0].x(), 1.0);
    EXPECT_EQ(m[0].y(), 2.0);
    EXPECT_EQ(m[1].x(), 3.0);
    EXPECT_EQ(m[1].y(), 4.0);
}

TEST(Mat2Test, OperatorIndex) {
    vec2 row0(1.0, 2.0);
    vec2 row1(3.0, 4.0);
    mat2 m(row0, row1);
    EXPECT_EQ(m[0].x(), 1.0);
    EXPECT_EQ(m[0].y(), 2.0);
    EXPECT_EQ(m[1].x(), 3.0);
    EXPECT_EQ(m[1].y(), 4.0);
}

TEST(Mat2Test, OperatorOutput) {
    vec2 row0(1.0, 2.0);
    vec2 row1(3.0, 4.0);
    mat2 m(row0, row1);
    std::ostringstream out;
    out << m;
    std::string expected_output = "1 2\n3 4\n";
    EXPECT_EQ(out.str(), expected_output);
}