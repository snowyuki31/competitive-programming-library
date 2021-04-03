---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327.test.cpp
    title: Matrix
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/matrix.hpp\"\n#include <iostream>\n#include <vector>\n\
    #include <utility>\n\nnamespace snow {\n\ntemplate< typename T >\nstruct Matrix{\n\
    \    std::vector<std::vector<T>> mat;\n    constexpr Matrix(int n = 1, int m =\
    \ 1, T v = 0) noexcept : mat(n, std::vector<T>(m, v)) {}\n    constexpr Matrix(std::vector<std::vector<T>>\
    \ v) noexcept: mat(v) {}\n\n    size_t size() const { return mat.size(); }\n \
    \   std::pair<size_t, size_t> shape() const { return {mat.size(), mat[0].size()};\
    \ }\n\n    constexpr Matrix operator+(const Matrix &A) const noexcept { return\
    \ Matrix(*this) += A; }\n    constexpr Matrix operator-(const Matrix &A) const\
    \ noexcept { return Matrix(*this) -= A; }\n    constexpr Matrix operator*(const\
    \ Matrix &A) const noexcept { return Matrix(*this) *= A; }\n\n    constexpr Matrix&\
    \ operator+=(const Matrix &A) noexcept{\n        auto [n, m] = A.shape();\n  \
    \      for (int i = 0; i < (int)n; ++i)\n            for (int j = 0; j < (int)m;\
    \ ++j)\n                mat[i][j] += A[i][j];\n        return *this;\n    }\n\n\
    \    constexpr Matrix& operator-=(const Matrix &A) noexcept{\n        auto [n,\
    \ m] = A.shape();\n        for (int i = 0; i < (int)n; ++i)\n            for (int\
    \ j = 0; j < (int)m; ++j)\n                mat[i][j] -= A[i][j];\n        return\
    \ *this;\n    }\n\n    constexpr Matrix& operator*=(const Matrix &A) noexcept{\n\
    \        auto [n, m] = A.shape();\n        Matrix<T> res(n, m);\n        for (int\
    \ i = 0; i < (int)n; ++i) \n            for (int j = 0; j < (int)m; ++j)\n   \
    \             for (int k = 0; k < (int)A.size(); ++k) \n                    res[i][j]\
    \ += mat[i][k] * A[k][j];\n        mat = res.mat;\n        return *this;\n   \
    \ }\n\n    constexpr std::vector<T> operator*(const std::vector<T> &v) noexcept{\n\
    \        auto [n, m] = shape();\n        std::vector<T> ret(n);\n        for(int\
    \ i = 0; i < (int)n; ++i)\n            for(int j = 0; j < (int)m; ++j)\n     \
    \           ret[i] += mat[i][j] * v[j];\n        return ret;\n    }\n\n    Matrix<T>\
    \ pow(long long N) noexcept{\n        auto [n, m] = shape();\n        Matrix<T>\
    \ res(n, m);\n        Matrix<T> B(mat);\n        for (int i = 0; i < (int)mat.size();\
    \ ++i) res[i][i] = 1;\n        while(N){\n            if(N & 1) res = res * B;\n\
    \            B *= B;\n            N >>= 1;\n        }\n        return res;\n \
    \   }\n    \n    std::vector<T> &operator[](int i) { return mat[i]; }\n    const\
    \ std::vector<T> &operator[](int i) const { return mat[i]; }\n\n    friend std::ostream&\
    \ operator << (std::ostream& os, const Matrix<T> &M){\n        for (int i = 0;\
    \ i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ? \"\" : \"\\n\");\n \
    \       return os;\n    }\n\n};\n\n\n} // namespace snow\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <utility>\n\
    \nnamespace snow {\n\ntemplate< typename T >\nstruct Matrix{\n    std::vector<std::vector<T>>\
    \ mat;\n    constexpr Matrix(int n = 1, int m = 1, T v = 0) noexcept : mat(n,\
    \ std::vector<T>(m, v)) {}\n    constexpr Matrix(std::vector<std::vector<T>> v)\
    \ noexcept: mat(v) {}\n\n    size_t size() const { return mat.size(); }\n    std::pair<size_t,\
    \ size_t> shape() const { return {mat.size(), mat[0].size()}; }\n\n    constexpr\
    \ Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A;\
    \ }\n    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this)\
    \ -= A; }\n    constexpr Matrix operator*(const Matrix &A) const noexcept { return\
    \ Matrix(*this) *= A; }\n\n    constexpr Matrix& operator+=(const Matrix &A) noexcept{\n\
    \        auto [n, m] = A.shape();\n        for (int i = 0; i < (int)n; ++i)\n\
    \            for (int j = 0; j < (int)m; ++j)\n                mat[i][j] += A[i][j];\n\
    \        return *this;\n    }\n\n    constexpr Matrix& operator-=(const Matrix\
    \ &A) noexcept{\n        auto [n, m] = A.shape();\n        for (int i = 0; i <\
    \ (int)n; ++i)\n            for (int j = 0; j < (int)m; ++j)\n               \
    \ mat[i][j] -= A[i][j];\n        return *this;\n    }\n\n    constexpr Matrix&\
    \ operator*=(const Matrix &A) noexcept{\n        auto [n, m] = A.shape();\n  \
    \      Matrix<T> res(n, m);\n        for (int i = 0; i < (int)n; ++i) \n     \
    \       for (int j = 0; j < (int)m; ++j)\n                for (int k = 0; k <\
    \ (int)A.size(); ++k) \n                    res[i][j] += mat[i][k] * A[k][j];\n\
    \        mat = res.mat;\n        return *this;\n    }\n\n    constexpr std::vector<T>\
    \ operator*(const std::vector<T> &v) noexcept{\n        auto [n, m] = shape();\n\
    \        std::vector<T> ret(n);\n        for(int i = 0; i < (int)n; ++i)\n   \
    \         for(int j = 0; j < (int)m; ++j)\n                ret[i] += mat[i][j]\
    \ * v[j];\n        return ret;\n    }\n\n    Matrix<T> pow(long long N) noexcept{\n\
    \        auto [n, m] = shape();\n        Matrix<T> res(n, m);\n        Matrix<T>\
    \ B(mat);\n        for (int i = 0; i < (int)mat.size(); ++i) res[i][i] = 1;\n\
    \        while(N){\n            if(N & 1) res = res * B;\n            B *= B;\n\
    \            N >>= 1;\n        }\n        return res;\n    }\n    \n    std::vector<T>\
    \ &operator[](int i) { return mat[i]; }\n    const std::vector<T> &operator[](int\
    \ i) const { return mat[i]; }\n\n    friend std::ostream& operator << (std::ostream&\
    \ os, const Matrix<T> &M){\n        for (int i = 0; i < M.size(); ++i) os << M[i]\
    \ << (i == (M.size() - 1) ? \"\" : \"\\n\");\n        return os;\n    }\n\n};\n\
    \n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/matrix.hpp
  requiredBy: []
  timestamp: '2021-04-04 04:21:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1327.test.cpp
documentation_of: snow/math/matrix.hpp
layout: document
redirect_from:
- /library/snow/math/matrix.hpp
- /library/snow/math/matrix.hpp.html
title: snow/math/matrix.hpp
---
