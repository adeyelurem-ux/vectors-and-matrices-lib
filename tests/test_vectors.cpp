//
// Created by Michael Adeyelure on 20/08/2026.
//

#include <gtest/gtest.h>
#include "../include/VectorN.h"

//Vector Arithmetic Tests

TEST(VectorArithmetic, 2DCompoundAddition_ReturnsSum) {
    VectorN<2> v1 ({1, 2});
    const VectorN<2> v2 ({2, 1});

    v1 += v2;

    const VectorN<2> v3 ({3, 3});

    EXPECT_EQ(v1, v3);
}

TEST(VectorArithmetic, 2DCompoundSubtraction_ReturnsSum) {
    VectorN<2> v1 ({1, 1});
    const VectorN<2> v2 ({1, 1});

    v1 -= v2;

    const VectorN<2> v3 ({0, 0});

    EXPECT_EQ(v1, v3);
}

TEST(VectorArithmetic, 2DCompoundMultiplication_ReturnsProduct) {
    VectorN<2> v1 ({1, 1});

    v1 *= 2;

    const VectorN<2> v2 ({2, 2});

    EXPECT_EQ(v1, v2);
}

TEST(VectorArithmetic, 2DCompoundDivision_ReturnsProduct) {
    VectorN<2> v1 ({1, 1});

    v1 /= 2;

    const VectorN<2> v2 ({0.5, 0.5});

    EXPECT_EQ(v1, v2);
}

TEST(VectorArithmetic, 2DBinaryAddition_ReturnsSum) {
    const VectorN<2> v1 = {1, 1};
    const VectorN<2> v2 = {1, 1};

    const VectorN<2> v3 = {2, 2};

    EXPECT_EQ(v3, (v1+v2));
}

TEST(VectorArithmetic, 2DBinarySubtraction_ReturnsSum) {
    const VectorN<2> v1 = {1, 1};
    const VectorN<2> v2 = {1, 1};

    const VectorN<2> v3 = {0, 0};

    EXPECT_EQ(v3, (v1-v2));
}

TEST(VectorArithmetic, 2DBinaryMultiplication_ReturnsProduct) {
    const VectorN<2> v1 = {1, 1};
    const VectorN<2> v2 = {2, 2};

    EXPECT_EQ((v1 * 2), v2);
    EXPECT_EQ((2 * v1), v2);
}

TEST(VectorArithmetic, 2DBinaryDivision_ReturnsProduct) {
    const VectorN<2> v1 = {1, 1};
    const VectorN<2> v2 = {0.5, 0.5};

    EXPECT_EQ((v1 / 2), v2);
}

TEST(VectorArithmetic, 2DNegation_ReturnsNegative) {
    VectorN<2> v1 = {1, 1};
    const VectorN<2> v2 = {-1, -1};

    EXPECT_EQ((-v1), v2);
}

//Vector Operator Tests

TEST(VectorOperator, DotProduct_ReturnsScalarProduct) {
    const VectorN<3> v1 = {1, 1, 1};

    EXPECT_EQ(v1.dot(v1), 3);
}

TEST(VectorOperator, CrossProduct_ReturnsVectorProduct) {
    const VectorN<3> i = {1, 0, 0};
    const VectorN<3> j = {0, 1, 0};
    const VectorN<3> k = {0, 0, 1};

    EXPECT_EQ(i.cross(j), k);
}
