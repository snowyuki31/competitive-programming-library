#pragma once
#include <cassert>
#include <iostream>
#include <vector>
#include <utility>

namespace snow {

/**
 * @brief Matrix template
 * 
 * @tparam T 
 */
template< typename T >
struct Matrix{
    std::vector<std::vector<T>> mat;
    constexpr Matrix(int N = 1, int M = 1, T val = 0) noexcept : mat(N, std::vector<T>(M, val)) {}
    constexpr Matrix(std::vector<std::vector<T>> v) noexcept: mat(v) {}

    size_t size() const { return mat.size(); }
    std::pair<size_t, size_t> shape() const { return {mat.size(), mat[0].size()}; }

    constexpr Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A; }
    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this) -= A; }
    constexpr Matrix operator*(const Matrix &A) const noexcept { return Matrix(*this) *= A; }

    constexpr Matrix& operator+=(const Matrix &A) noexcept{
        auto [N, M] = A.shape();
        for (int i = 0; i < (int)N; ++i)
            for (int j = 0; j < (int)M; ++j)
                mat[i][j] += A[i][j];
        return *this;
    }

    constexpr Matrix& operator-=(const Matrix &A) noexcept{
        auto [N, M] = A.shape();
        for (int i = 0; i < (int)N; ++i)
            for (int j = 0; j < (int)M; ++j)
                mat[i][j] -= A[i][j];
        return *this;
    }

    constexpr Matrix& operator*=(const Matrix &A) noexcept{
        auto [N, M] = this->shape();
        auto [M_, K] = A.shape();
        assert(M == M_);
        Matrix<T> res(N, K);
        for (int i = 0; i < (int)N; ++i) 
            for (int j = 0; j < (int)M; ++j)
                for (int k = 0; k < (int)K; ++k) 
                    res[i][k] += mat[i][j] * A[j][k];
        mat = res.mat;
        return *this;
    }

    constexpr std::vector<T> operator*(const std::vector<T> &v) noexcept{
        auto [N, M] = shape();
        std::vector<T> ret(N);
        for(int i = 0; i < (int)N; ++i)
            for(int j = 0; j < (int)M; ++j)
                ret[i] += mat[i][j] * v[j];
        return ret;
    }

    Matrix<T> pow(long long X) noexcept{
        auto [N, M] = this->shape();
        Matrix<T> res(N, M);
        Matrix<T> B(mat);
        for (int i = 0; i < (int)mat.size(); ++i) res[i][i] = 1;
        while(X){
            if(X & 1) res = res * B;
            B *= B;
            X >>= 1;
        }
        return res;
    }
    
    std::vector<T> &operator[](int i) { return mat[i]; }
    const std::vector<T> &operator[](int i) const { return mat[i]; }

    friend std::ostream& operator << (std::ostream& os, const Matrix<T> &M){
        for (int i = 0; i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ? "" : "\n");
        return os;
    }

};


} // namespace snow