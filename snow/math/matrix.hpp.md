---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: snow/math/gauss_jordan.hpp
    title: Gauss Jordan's Elimination
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327.test.cpp
    title: Matrix
  - icon: ':x:'
    path: test/oj/matrix_product.test.cpp
    title: Matrix Product
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Matrix template
    links: []
  bundledCode: "#line 2 \"snow/math/matrix.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n\nnamespace snow {\n\n/**\n * @brief Matrix\
    \ template\n * \n * @tparam T \n */\ntemplate< typename T >\nstruct Matrix{\n\
    \    std::vector<std::vector<T>> mat;\n    constexpr Matrix(int N = 1, int M =\
    \ 1, T val = 0) noexcept : mat(N, std::vector<T>(M, val)) {}\n    constexpr Matrix(std::vector<std::vector<T>>\
    \ v) noexcept: mat(v) {}\n\n    size_t size() const { return mat.size(); }\n \
    \   std::pair<size_t, size_t> shape() const { return {mat.size(), mat[0].size()};\
    \ }\n\n    constexpr Matrix operator+(const Matrix &A) const noexcept { return\
    \ Matrix(*this) += A; }\n    constexpr Matrix operator-(const Matrix &A) const\
    \ noexcept { return Matrix(*this) -= A; }\n    constexpr Matrix operator*(const\
    \ Matrix &A) const noexcept { return Matrix(*this) *= A; }\n\n    constexpr Matrix&\
    \ operator+=(const Matrix &A) noexcept{\n        auto [N, M] = A.shape();\n  \
    \      for (int i = 0; i < (int)N; ++i)\n            for (int j = 0; j < (int)M;\
    \ ++j)\n                mat[i][j] += A[i][j];\n        return *this;\n    }\n\n\
    \    constexpr Matrix& operator-=(const Matrix &A) noexcept{\n        auto [N,\
    \ M] = A.shape();\n        for (int i = 0; i < (int)N; ++i)\n            for (int\
    \ j = 0; j < (int)M; ++j)\n                mat[i][j] -= A[i][j];\n        return\
    \ *this;\n    }\n\n    constexpr Matrix& operator*=(const Matrix &A) noexcept{\n\
    \        auto [N, M] = this->shape();\n        auto [M_, K] = A.shape();\n   \
    \     assert(M == M_);\n        Matrix<T> res(N, K);\n        for (int i = 0;\
    \ i < (int)N; ++i) \n            for (int j = 0; j < (int)M; ++j)\n          \
    \      for (int k = 0; k < (int)K; ++k) \n                    res[i][k] += mat[i][j]\
    \ * A[j][k];\n        mat = res.mat;\n        return *this;\n    }\n\n    constexpr\
    \ std::vector<T> operator*(const std::vector<T> &v) noexcept{\n        auto [N,\
    \ M] = shape();\n        std::vector<T> ret(N);\n        for(int i = 0; i < (int)N;\
    \ ++i)\n            for(int j = 0; j < (int)M; ++j)\n                ret[i] +=\
    \ mat[i][j] * v[j];\n        return ret;\n    }\n\n    Matrix<T> pow(long long\
    \ X) noexcept{\n        auto [N, M] = this->shape();\n        Matrix<T> res(N,\
    \ M);\n        Matrix<T> B(mat);\n        for (int i = 0; i < (int)mat.size();\
    \ ++i) res[i][i] = 1;\n        while(X){\n            if(X & 1) res = res * B;\n\
    \            B *= B;\n            X >>= 1;\n        }\n        return res;\n \
    \   }\n    \n    std::vector<T> &operator[](int i) { return mat[i]; }\n    const\
    \ std::vector<T> &operator[](int i) const { return mat[i]; }\n\n    friend std::ostream&\
    \ operator << (std::ostream& os, const Matrix<T> &M){\n        for (int i = 0;\
    \ i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ? \"\" : \"\\n\");\n \
    \       return os;\n    }\n\n};\n\n\n} // namespace snow\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    #include <utility>\n\nnamespace snow {\n\n/**\n * @brief Matrix template\n * \n\
    \ * @tparam T \n */\ntemplate< typename T >\nstruct Matrix{\n    std::vector<std::vector<T>>\
    \ mat;\n    constexpr Matrix(int N = 1, int M = 1, T val = 0) noexcept : mat(N,\
    \ std::vector<T>(M, val)) {}\n    constexpr Matrix(std::vector<std::vector<T>>\
    \ v) noexcept: mat(v) {}\n\n    size_t size() const { return mat.size(); }\n \
    \   std::pair<size_t, size_t> shape() const { return {mat.size(), mat[0].size()};\
    \ }\n\n    constexpr Matrix operator+(const Matrix &A) const noexcept { return\
    \ Matrix(*this) += A; }\n    constexpr Matrix operator-(const Matrix &A) const\
    \ noexcept { return Matrix(*this) -= A; }\n    constexpr Matrix operator*(const\
    \ Matrix &A) const noexcept { return Matrix(*this) *= A; }\n\n    constexpr Matrix&\
    \ operator+=(const Matrix &A) noexcept{\n        auto [N, M] = A.shape();\n  \
    \      for (int i = 0; i < (int)N; ++i)\n            for (int j = 0; j < (int)M;\
    \ ++j)\n                mat[i][j] += A[i][j];\n        return *this;\n    }\n\n\
    \    constexpr Matrix& operator-=(const Matrix &A) noexcept{\n        auto [N,\
    \ M] = A.shape();\n        for (int i = 0; i < (int)N; ++i)\n            for (int\
    \ j = 0; j < (int)M; ++j)\n                mat[i][j] -= A[i][j];\n        return\
    \ *this;\n    }\n\n    constexpr Matrix& operator*=(const Matrix &A) noexcept{\n\
    \        auto [N, M] = this->shape();\n        auto [M_, K] = A.shape();\n   \
    \     assert(M == M_);\n        Matrix<T> res(N, K);\n        for (int i = 0;\
    \ i < (int)N; ++i) \n            for (int j = 0; j < (int)M; ++j)\n          \
    \      for (int k = 0; k < (int)K; ++k) \n                    res[i][k] += mat[i][j]\
    \ * A[j][k];\n        mat = res.mat;\n        return *this;\n    }\n\n    constexpr\
    \ std::vector<T> operator*(const std::vector<T> &v) noexcept{\n        auto [N,\
    \ M] = shape();\n        std::vector<T> ret(N);\n        for(int i = 0; i < (int)N;\
    \ ++i)\n            for(int j = 0; j < (int)M; ++j)\n                ret[i] +=\
    \ mat[i][j] * v[j];\n        return ret;\n    }\n\n    Matrix<T> pow(long long\
    \ X) noexcept{\n        auto [N, M] = this->shape();\n        Matrix<T> res(N,\
    \ M);\n        Matrix<T> B(mat);\n        for (int i = 0; i < (int)mat.size();\
    \ ++i) res[i][i] = 1;\n        while(X){\n            if(X & 1) res = res * B;\n\
    \            B *= B;\n            X >>= 1;\n        }\n        return res;\n \
    \   }\n    \n    std::vector<T> &operator[](int i) { return mat[i]; }\n    const\
    \ std::vector<T> &operator[](int i) const { return mat[i]; }\n\n    friend std::ostream&\
    \ operator << (std::ostream& os, const Matrix<T> &M){\n        for (int i = 0;\
    \ i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ? \"\" : \"\\n\");\n \
    \       return os;\n    }\n\n};\n\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/matrix.hpp
  requiredBy:
  - snow/math/gauss_jordan.hpp
  timestamp: '2021-05-13 03:29:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/oj/matrix_product.test.cpp
  - test/aoj/1327.test.cpp
documentation_of: snow/math/matrix.hpp
layout: document
redirect_from:
- /library/snow/math/matrix.hpp
- /library/snow/math/matrix.hpp.html
title: Matrix template
---
