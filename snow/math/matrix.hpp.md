---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/matrix.hpp\"\n#include <vector>\n#include <utility>\n\
    \nnamespace snow {\n\ntemplate< typename T >\nstruct Matrix{\n    std::vector<std::vector<T>>\
    \ mat;\n    constexpr Matrix(int n = 1, int m = 1, T v = 0) noexcept : mat(n,\
    \ std::vector<T>(m, v)) {}\n    constexpr Matrix(std::vector<std::vector<T>> v)\
    \ noexcept: mat(v) {}\n\n    size_t size() const { return mat.size(); }\n    std::pair<size_t,\
    \ size_t> shape() const { return {mat.size(), mat[0].size()}; }\n\n    constexpr\
    \ Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A;\
    \ }\n    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this)\
    \ -= A; }\n    constexpr Matrix operator*(const Matrix &A) const noexcept { return\
    \ Matrix(*this) *= A; }\n\n    constexpr Matrix& operator+=(const Matrix &A) noexcept{\n\
    \        auto [n, m] = A.shape();\n        for (int i = 0; i < n; ++i)\n     \
    \       for (int j = 0; j < m; ++j)\n                mat[i][j] += A[i][j];\n \
    \       return *this;\n    }\n\n    constexpr Matrix& operator-=(const Matrix\
    \ &A) noexcept{\n        auto [n, m] = A.shape();\n        for (int i = 0; i <\
    \ n; ++i)\n            for (int j = 0; j < m; ++j)\n                mat[i][j]\
    \ -= A[i][j];\n        return *this;\n    }\n\n    constexpr Matrix& operator*=(const\
    \ Matrix &A) noexcept{\n        auto [n, m] = A.shape();\n        Matrix<T> res(n,\
    \ m);\n        for (int i = 0; i < n; ++i) \n            for (int j = 0; j < m;\
    \ ++j)\n                for (int k = 0; k < A.size(); ++k) \n                \
    \    res[i][j] += mat[i][k] * A[k][j];\n        mat = res.mat;\n        return\
    \ *this;\n    }\n\n\n    Matrix<T> pow(long long N) noexcept{\n        auto [n,\
    \ m] = mat.shape();\n        Matrix<T> res(n, m);\n        auto B = A;\n     \
    \   for (int i = 0; i < A.size(); ++i) res[i][i] = 1;\n        while(N){\n   \
    \         if(N & 1) res = res * B;\n            B *= B;\n            n >>= 1;\n\
    \        }\n        return res;\n    }\n    \n    vector<T> &operator[](int i)\
    \ { return mat[i]; }\n    const vector<T> &operator[](int i) const { return mat[i];\
    \ }\n\n    friend ostream& operator << (ostream& os, const Matrix<T> &M){\n  \
    \      for (int i = 0; i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ?\
    \ \"\" : \"\\n\");\n        return os;\n    }\n\n};\n\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace snow {\n\
    \ntemplate< typename T >\nstruct Matrix{\n    std::vector<std::vector<T>> mat;\n\
    \    constexpr Matrix(int n = 1, int m = 1, T v = 0) noexcept : mat(n, std::vector<T>(m,\
    \ v)) {}\n    constexpr Matrix(std::vector<std::vector<T>> v) noexcept: mat(v)\
    \ {}\n\n    size_t size() const { return mat.size(); }\n    std::pair<size_t,\
    \ size_t> shape() const { return {mat.size(), mat[0].size()}; }\n\n    constexpr\
    \ Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A;\
    \ }\n    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this)\
    \ -= A; }\n    constexpr Matrix operator*(const Matrix &A) const noexcept { return\
    \ Matrix(*this) *= A; }\n\n    constexpr Matrix& operator+=(const Matrix &A) noexcept{\n\
    \        auto [n, m] = A.shape();\n        for (int i = 0; i < n; ++i)\n     \
    \       for (int j = 0; j < m; ++j)\n                mat[i][j] += A[i][j];\n \
    \       return *this;\n    }\n\n    constexpr Matrix& operator-=(const Matrix\
    \ &A) noexcept{\n        auto [n, m] = A.shape();\n        for (int i = 0; i <\
    \ n; ++i)\n            for (int j = 0; j < m; ++j)\n                mat[i][j]\
    \ -= A[i][j];\n        return *this;\n    }\n\n    constexpr Matrix& operator*=(const\
    \ Matrix &A) noexcept{\n        auto [n, m] = A.shape();\n        Matrix<T> res(n,\
    \ m);\n        for (int i = 0; i < n; ++i) \n            for (int j = 0; j < m;\
    \ ++j)\n                for (int k = 0; k < A.size(); ++k) \n                \
    \    res[i][j] += mat[i][k] * A[k][j];\n        mat = res.mat;\n        return\
    \ *this;\n    }\n\n\n    Matrix<T> pow(long long N) noexcept{\n        auto [n,\
    \ m] = mat.shape();\n        Matrix<T> res(n, m);\n        auto B = A;\n     \
    \   for (int i = 0; i < A.size(); ++i) res[i][i] = 1;\n        while(N){\n   \
    \         if(N & 1) res = res * B;\n            B *= B;\n            n >>= 1;\n\
    \        }\n        return res;\n    }\n    \n    vector<T> &operator[](int i)\
    \ { return mat[i]; }\n    const vector<T> &operator[](int i) const { return mat[i];\
    \ }\n\n    friend ostream& operator << (ostream& os, const Matrix<T> &M){\n  \
    \      for (int i = 0; i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ?\
    \ \"\" : \"\\n\");\n        return os;\n    }\n\n};\n\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/matrix.hpp
  requiredBy: []
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/math/matrix.hpp
layout: document
redirect_from:
- /library/snow/math/matrix.hpp
- /library/snow/math/matrix.hpp.html
title: snow/math/matrix.hpp
---
