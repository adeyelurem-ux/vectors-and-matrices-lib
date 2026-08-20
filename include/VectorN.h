//
// Created by Michael Adeyelure on 20/08/2026.
//

#ifndef VECTORS_AND_MATRICES_LIB_VECTOR_H
#define VECTORS_AND_MATRICES_LIB_VECTOR_H

#include<complex>

template<size_t N>

struct VectorN {
    std::vector<double> data;
    VectorN() = default;

    VectorN(const std::initializer_list<double>& list) {
        data = list;
    }

    //Compound Arithmetic Operators
    [[nodiscard]] constexpr VectorN operator+=(const VectorN& rhs) {
        size_t i = 0;
        for (const double val : data) {
            data[i] += rhs.data[i];
            i++;
        }

        return *this;
    }


    [[nodiscard]] constexpr VectorN operator -=(const VectorN& rhs) {
        size_t i = 0;
        for (double val : data) {
            val -= rhs.data[i];
            i++;
        }

        return *this;
    }


    [[nodiscard]] constexpr VectorN operator *=(const double scalar) {
        size_t i = 0;
        for (const double val : data) {
            data[i] *= scalar;
            i++;
        }

        return *this;
    }


    [[nodiscard]] constexpr VectorN operator /=(const double scalar) {
        double inv = 1.0/scalar;

        return *this *= inv;
    }


    //Binary Arithmetic Operators
    [[nodiscard]] friend constexpr VectorN operator+(const VectorN& lhs, const VectorN& rhs) {
        return lhs += rhs;
    }


    [[nodiscard]] friend constexpr VectorN operator-(const VectorN& lhs, const VectorN& rhs) {
        return lhs -= rhs;
    }


    [[nodiscard]] friend constexpr VectorN operator*(const VectorN& lhs, const double scalar) {
        return lhs *= scalar;
    }


    [[nodiscard]] friend constexpr VectorN operator*(const double scalar, const VectorN& rhs) {
        return rhs *= scalar;
    }


    [[nodiscard]] friend constexpr VectorN operator/(const VectorN& lhs, const double scalar) {
        return lhs /= scalar;
    }
};

#endif //VECTORS_AND_MATRICES_LIB_VECTOR_H
