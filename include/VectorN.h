//
// Created by Michael Adeyelure on 20/08/2026.
//

#ifndef VECTORS_AND_MATRICES_LIB_VECTOR_H
#define VECTORS_AND_MATRICES_LIB_VECTOR_H

#include<array>

template<size_t N>

struct VectorN {
    std::array<double, N> data{};
    VectorN() = default;

    VectorN(const std::initializer_list<double>& list) {
        std::size_t i = 0;
        for (double val : list) {
            if (i < N) {
                data[i++] = val;
            }
        }
    }

    //Compound Arithmetic Operators
    constexpr VectorN<N>& operator+=(const VectorN& rhs) {
        size_t i = 0;
        for (const double val : data) {
            data[i] += rhs.data[i];
            i++;
        }

        return *this;
    }


    constexpr VectorN<N>& operator -=(const VectorN& rhs) {
        size_t i = 0;
        for (const double val : data) {
            data[i] -= rhs.data[i];
            i++;
        }

        return *this;
    }


    constexpr VectorN<N>& operator *=(const double scalar) {
        size_t i = 0;
        for (const double val : data) {
            data[i] *= scalar;
            i++;
        }

        return *this;
    }


    constexpr VectorN<N>& operator /=(const double scalar) {
        double inv = 1.0/scalar;

        return *this *= inv;
    }


    //Binary Arithmetic Operators
    [[nodiscard]] friend constexpr VectorN<N> operator+(VectorN lhs, const VectorN& rhs) {
        return lhs += rhs;
    }


    [[nodiscard]] friend constexpr VectorN<N> operator-(VectorN lhs, const VectorN& rhs) {
        return lhs -= rhs;
    }


    [[nodiscard]] friend constexpr VectorN<N> operator*(VectorN lhs, const double scalar) {
        return lhs *= scalar;
    }


    [[nodiscard]] friend constexpr VectorN<N> operator*(const double scalar,  VectorN rhs) {
        return rhs * scalar;
    }


    [[nodiscard]] friend constexpr VectorN<N> operator/(VectorN lhs, const double scalar) {
        return lhs /= scalar;
    }

    [[nodiscard]] friend constexpr bool operator==(const VectorN& lhs, const VectorN& rhs) {
        if (rhs.data != lhs.data) {
            return false;
        }

        return true;
    }


    constexpr VectorN<N> operator-() {
        return *this * -1;
    }

    [[nodiscard]] constexpr double magnitudeSqd() const{
        double result = 0;

        for (const double i : data) {
            result += i * i;
        }

        return result;
    }

    [[nodiscard]] constexpr VectorN<N> unitVector() const {
        return *this / std::sqrt(magnitudeSqd());
    }

    constexpr VectorN<N> normalise() {
        *this /= std::sqrt(magnitudeSqd());

        return *this;
    }


    [[nodiscard]] constexpr double dot(const VectorN& other) const {
        double result = 0;

        for (size_t i = 0; i < data.size(); i++) {
            result += (data[i] * other.data[i]);
        }

        return result;
    }

    [[nodiscard]] constexpr VectorN<3> cross(const VectorN& other)  const {
        return VectorN<3> {
            (data[1] * other.data[2]) - (data[2] * other.data[1]),
            (data[2] * other.data[0]) - (data[0] * other.data[2]),
            (data[0] * other.data[1]) - (data[1] * other.data[0])
        };
    }
};

#endif //VECTORS_AND_MATRICES_LIB_VECTOR_H
