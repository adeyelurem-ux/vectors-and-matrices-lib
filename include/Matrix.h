//
// Created by Michael Adeyelure on 21/08/2026.
//

#ifndef VECTORS_AND_MATRICES_LIB_MATRIX_H
#define VECTORS_AND_MATRICES_LIB_MATRIX_H

#include "VectorN.h"

template<size_t N, size_t M>

struct Matrix {
    std::array<double, N * M> data{};

    Matrix() = default;


    Matrix(const std::initializer_list<double>& list) {
        size_t i = 0;
        for (double val : list) {
            if (i < N * M) {
                data[i++] = val;
            }
        }
    }

    
    [[nodiscard]] constexpr VectorN<M> getRowVector(const size_t row_index) const {
        VectorN<M> row;

        const size_t start_index = row_index * M;
        for (size_t i = 0; i < M; ++i) {
            row.data[i] = data[start_index + i];
        }

        return row;
    }


    [[nodiscard]] constexpr VectorN<N> getColumnVector(const size_t column_index) const {
        VectorN<N> column;

        const size_t start_index = column_index;
        for (size_t i = 0; i < N; ++i) {
            column.data[i] = data[column_index + i * M];
        }

        return column;
    }


    constexpr Matrix<N, M> operator-() const {
        return *this * -1;
    }


    constexpr Matrix<N, M>& operator+=(const Matrix<N, M>& rhs) {
        size_t i = 0;
        for (double val : data) {
            data[i] += rhs.data[i];
            i++;
        }
        
        return *this;
    }
    
    
    constexpr Matrix<N, M>& operator-=(const Matrix<N, M>& rhs) {
        size_t i = 0;
        for (double val : data) {
            data[i] -= rhs.data[i];
            i++;
        }
        
        return *this;
    }
    
    
    constexpr Matrix<N, M>& operator*=(const double scalar) {
        size_t i = 0;
        for ([[maybe_unused]] double val : data) {
            data[i] *= scalar;
            i++;
        }
        
        return *this;
    }
    
    
    constexpr Matrix<N, M>& operator/=(const double scalar) {
        double inv = 1.0/scalar;
        *this *= inv;
        
        return *this;
    }


    [[nodiscard]] friend constexpr Matrix<N, M> operator+(Matrix<N, M> lhs, const Matrix<N, M>& rhs) {
        return lhs += rhs;
    }


    [[nodiscard]] friend constexpr Matrix<N, M> operator-(Matrix<N, M> lhs, const Matrix<N, M>& rhs) {
        return lhs -= rhs;
    }


    [[nodiscard]] friend constexpr Matrix<N, M> operator*(Matrix<N, M> lhs, const double scalar) {
        return lhs *= scalar;
    }


    [[nodiscard]] friend constexpr Matrix<N, M> operator*(const double scalar, Matrix<N, M> rhs) {
        return rhs *= scalar;
    }


    template<size_t P>
    [[nodiscard]] friend constexpr Matrix<N, P> operator*(const Matrix<N, M>& lhs, const Matrix<M, P>& rhs) {
        Matrix<N, P> result{};

        size_t i = 0;
        for (size_t r = 0; r < N; ++r) {
            for (size_t c = 0; c < P; ++c) {
                result.data[i] = lhs.getRowVector(r).dot(rhs.getColumnVector(c));
                i++;
            }
        }

        return result;
    }

    
    [[nodiscard]] friend constexpr Matrix<N, M> operator/(Matrix<N, M> lhs, const double scalar) {
        double inv = 1.0/scalar;
        return lhs *= inv;
    }


    [[nodiscard]] friend constexpr bool operator==(const Matrix & lhs, const Matrix & rhs) {
        if (lhs.data != rhs.data) {
            return false;
        }

        return true;
    }
};

#endif //VECTORS_AND_MATRICES_LIB_MATRIX_H
