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
