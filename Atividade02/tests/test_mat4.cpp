#include "gtest/gtest.h"
#include "../includes/mat4.h"
#include "../includes/vec4.h"

TEST(Mat4Test, DefaultConstructor) {
    mat4 m;
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(m[i].x(), 0.0);
        EXPECT_EQ(m[i].y(), 0.0);
        EXPECT_EQ(m[i].z(), 0.0);
        EXPECT_EQ(m[i].w, 1.0);
    }
}

TEST(Mat4Test, CustomConstructor) {
    vec4 row0(1.0, 2.0, 3.0, 4.0);
    vec4 row1(5.0, 6.0, 7.0, 8.0);
    vec4 row2(9.0, 10.0, 11.0, 12.0);
    vec4 row3(13.0, 14.0, 15.0, 16.0);
    mat4 m(row0, row1, row2, row3);
    EXPECT_EQ(m[0].x(), 1.0);
    EXPECT_EQ(m[0].y(), 2.0);
    EXPECT_EQ(m[0].z(), 3.0);
    EXPECT_EQ(m[0].w, 4.0);
    EXPECT_EQ(m[1].x(), 5.0);
    EXPECT_EQ(m[1].y(), 6.0);
    EXPECT_EQ(m[1].z(), 7.0);
    EXPECT_EQ(m[1].w, 8.0);
    EXPECT_EQ(m[2].x(), 9.0);
    EXPECT_EQ(m[2].y(), 10.0);
    EXPECT_EQ(m[2].z(), 11.0);
    EXPECT_EQ(m[2].w, 12.0);
    EXPECT_EQ(m[3].x(), 13.0);
    EXPECT_EQ(m[3].y(), 14.0);
    EXPECT_EQ(m[3].z(), 15.0);
    EXPECT_EQ(m[3].w, 16.0);
}

TEST(Mat4Test, ElementAccess) {
    vec4 row0(1.0, 2.0, 3.0, 4.0);
    vec4 row1(5.0, 6.0, 7.0, 8.0);
    vec4 row2(9.0, 10.0, 11.0, 12.0);
    vec4 row3(13.0, 14.0, 15.0, 16.0);
    mat4 m(row0, row1, row2, row3);
    EXPECT_EQ(m[0], row0);
    EXPECT_EQ(m[1], row1);
    EXPECT_EQ(m[2], row2);
    EXPECT_EQ(m[3], row3);
}