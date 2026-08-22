//
// Created by Michael Adeyelure on 21/08/2026.
//

#include <gtest/gtest.h>
#include "../include/Matrix.h"

TEST(MatrixOperators, GetRowVector_ReturnsRowVector) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    VectorN<2> v1  ({1, 1});

    EXPECT_EQ(M.getRowVector(0), v1);
}

TEST(MatrixOperators, GetColumnVector_ReturnsColumnVector) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    VectorN<2> v1  ({1, 1});

    EXPECT_EQ(M.getColumnVector(0), v1);
}

TEST(MatrixArithmetic, CompoundAddition_ReturnsSum) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    Matrix<2, 2> A ({2, 2, 2, 2});
    EXPECT_EQ(M += M, A);
}

TEST(MatrixArithmetic, CompoundSubtraction_ReturnsSum) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    Matrix<2, 2> A ({0, 0, 0, 0});
    EXPECT_EQ(M -= M, A);
}

TEST(MatrixArithmetic, CompoundMultiplicationByScalar_ReturnsProduct) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    Matrix<2, 2> A ({2, 2, 2, 2});
    EXPECT_EQ(M *= 2, A);
}

TEST(MatrixArithmetic, CompoundDivision_ReturnsProduct) {
    Matrix<2, 2> M ({1, 1, 1, 1});
    Matrix<2, 2> A ({2, 2, 2, 2});
    EXPECT_EQ(M /= 0.5, A);
}

TEST(MatrixArithmetic, BinaryAddition_ReturnsSum) {
    Matrix<2, 2> A({1, 1, 1, 1});
    Matrix<2, 2> B({2, 2, 2, 2});
    EXPECT_EQ(A + A, B);
}

TEST(MatrixArithmetic, BinarySubtraction_ReturnsSum) {
    Matrix<2, 2> A({1, 1, 1, 1});
    Matrix<2, 2> B({0, 0, 0, 0});
    EXPECT_EQ(A - A, B);
}

TEST(MatrixArithmetic, BinaryScalarMultiplicationRight_ReturnsProduct) {
    Matrix<2, 2> A({1, 1, 1, 1});
    Matrix<2, 2> B({2, 2, 2, 2});
    EXPECT_EQ(A * 2, B);
}

TEST(MatrixArithmetic, BinaryScalarMultiplicationLeft_ReturnsProduct) {
    Matrix<2, 2> A({1, 1, 1, 1});
    Matrix<2, 2> B({2, 2, 2, 2});
    EXPECT_EQ(2 * A, B);
}

TEST(MatrixArithmetic, BinaryScalarDivision_ReturnsProduct) {
    Matrix<2, 2> A({1, 1, 1, 1});
    Matrix<2, 2> B({2, 2, 2, 2});
    EXPECT_EQ(A / 0.5, B);
}
