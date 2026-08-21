//
// Created by Michael Adeyelure on 21/08/2026.
//

#ifndef VECTORS_AND_MATRICES_LIB_MATRIX_H
#define VECTORS_AND_MATRICES_LIB_MATRIX_H

#include "VectorN.h"

template<size_t N, size_t M>

struct Matrix {
    std::array<double, N * M> data{};

    Matrix() : data(N * M, 0.0){};

    Matrix(const std::initializer_list<double>& list) {
        std::size_t i = 0;
        for (double val : list) {
            if (i < N * M) {
                data[i++] = val;
            }
        }
    }

    [[nodiscard]] constexpr VectorN<M> getRowVector(const std::size_t row_index) const {
        VectorN<M> row;

        const std::size_t start_index = row_index * M;
        for (std::size_t i = 0; i < M; ++i) {
            row.data[i] = data[start_index + i];
        }

        return row;
    }
};

#endif //VECTORS_AND_MATRICES_LIB_MATRIX_H
