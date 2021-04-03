#pragma once
#include <iostream>
#include <vector>
#include <utility>

namespace snow {

template< typename T >
struct Matrix{
    std::vector<std::vector<T>> mat;
    constexpr Matrix(int n = 1, int m = 1, T v = 0) noexcept : mat(n, std::vector<T>(m, v)) {}
    constexpr Matrix(std::vector<std::vector<T>> v) noexcept: mat(v) {}

    size_t size() const { return mat.size(); }
    std::pair<size_t, size_t> shape() const { return {mat.size(), mat[0].size()}; }

    constexpr Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A; }
    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this) -= A; }
    constexpr Matrix operator*(const Matrix &A) const noexcept { return Matrix(*this) *= A; }

    constexpr Matrix& operator+=(const Matrix &A) noexcept{
        auto [n, m] = A.shape();
        for (int i = 0; i < (int)n; ++i)
            for (int j = 0; j < (int)m; ++j)
                mat[i][j] += A[i][j];
        return *this;
    }

    constexpr Matrix& operator-=(const Matrix &A) noexcept{
        auto [n, m] = A.shape();
        for (int i = 0; i < (int)n; ++i)
            for (int j = 0; j < (int)m; ++j)
                mat[i][j] -= A[i][j];
        return *this;
    }

    constexpr Matrix& operator*=(const Matrix &A) noexcept{
        auto [n, m] = A.shape();
        Matrix<T> res(n, m);
        for (int i = 0; i < (int)n; ++i) 
            for (int j = 0; j < (int)m; ++j)
                for (int k = 0; k < (int)A.size(); ++k) 
                    res[i][j] += mat[i][k] * A[k][j];
        mat = res.mat;
        return *this;
    }

    constexpr std::vector<T> operator*(const std::vector<T> &v) noexcept{
        auto [n, m] = shape();
        std::vector<T> ret(n);
        for(int i = 0; i < (int)n; ++i)
            for(int j = 0; j < (int)m; ++j)
                ret[i] += mat[i][j] * v[j];
        return ret;
    }

    Matrix<T> pow(long long N) noexcept{
        auto [n, m] = shape();
        Matrix<T> res(n, m);
        Matrix<T> B(mat);
        for (int i = 0; i < (int)mat.size(); ++i) res[i][i] = 1;
        while(N){
            if(N & 1) res = res * B;
            B *= B;
            N >>= 1;
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