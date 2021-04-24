---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/geometry/area.hpp
    title: "Area (\u591A\u89D2\u5F62\u306E\u9762\u7A4D)"
  - icon: ':heavy_check_mark:'
    path: snow/geometry/ccw.hpp
    title: Counter-Clockwise
  - icon: ':heavy_check_mark:'
    path: snow/geometry/convex-hull.hpp
    title: "Convex-Hull (\u51F8\u5305)"
  - icon: ':heavy_check_mark:'
    path: snow/geometry/rotating-calipers.hpp
    title: "Rotating-Calipers (\u6700\u9060\u70B9\u5BFE)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: Counter-Clockwise
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: Area
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: Convex-Hull
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: Diameter of a Convex Polygon
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/geometry/template.hpp\"\n#include <iostream>\n#include\
    \ <complex>\n#include <utility>\n\nnamespace geometry {\n\nconstexpr long double\
    \ EPS = 1e-12;\n\ntemplate < typename T >\nstruct Point {\n    std::complex<T>\
    \ data;\n\n    Point() : data(0, 0) {}\n    Point(T a, T b) : data(a, b) {}\n\
    \    Point(std::complex<T> c) : data(c) {}\n\n    constexpr T real() const noexcept{\
    \ return data.real(); }\n    constexpr T imag() const noexcept { return data.imag();\
    \ }\n    constexpr Point operator+ (const Point &r) const noexcept { return Point(*this)\
    \ += r; }\n    constexpr Point operator- (const Point &r) const noexcept { return\
    \ Point(*this) -= r; }\n    constexpr Point operator* (const Point &r) const noexcept\
    \ { return Point(*this) *= r; }\n    constexpr Point operator/ (const Point &r)\
    \ const noexcept { return Point(*this) /= r; }\n    constexpr bool operator==(const\
    \ Point &x) const noexcept { return this->data == x.data; }\n    constexpr bool\
    \ operator!=(const Point &x) const noexcept { return !(*this == x); }\n    constexpr\
    \ bool operator< (const Point &x) const noexcept { return this->real() < x.real()\
    \ || (!(x.real() < this->real()) && this->imag() < x.imag()); }\n    constexpr\
    \ bool operator>=(const Point &x) const noexcept { return !(*this < x); }\n  \
    \  constexpr bool operator> (const Point &x) const noexcept { return x < *this;\
    \ }\n    constexpr bool operator<=(const Point &x) const noexcept { return !(*this\
    \ > x); }\n    \n    constexpr Point& operator+=(const Point &x) noexcept {\n\
    \        this->data += x.data;\n        return *this;\n    }\n    constexpr Point&\
    \ operator-=(const Point &x) noexcept {\n        this->data -= x.data;\n     \
    \   return *this;\n    }\n    constexpr Point& operator*=(const Point &x) noexcept\
    \ {\n        this->data *= x.data;\n        return *this;\n    }\n    constexpr\
    \ Point& operator/=(const Point &x) noexcept {\n        this->data /= x.data;\n\
    \        return *this;\n    }\n\n    friend constexpr std::ostream& operator<<\
    \ (std::ostream& os, const Point& x) noexcept {\n        os << x.real() << \"\
    \ \" << x.imag();\n        return os;\n    }\n    friend constexpr std::istream&\
    \ operator>>(std::istream& is, Point& x) noexcept {\n        T a, b;\n       \
    \ is >> a >> b;\n        x = Point(a, b);\n        return is;\n    }\n\n    template\
    \ <std::size_t N>\n    T get() const{\n        if constexpr (N == 0) return data.real();\n\
    \        else return data.imag();\n    }\n};\n\ntemplate < typename T>\nT abs(const\
    \ Point<T> &x) { return abs(x.data); }\n\ntemplate < typename T>\nT arg(const\
    \ Point<T> &x) { return arg(x.data); }\n\ntemplate < typename T>\nT norm(const\
    \ Point<T> &x) { return norm(x.data); }\n\ntemplate < typename T>\nPoint<T> conj(const\
    \ Point<T> &x) { return Point<T>(conj(x.data)); }\n\ntemplate < typename T>\n\
    Point<T> proj(const Point<T> &x) { return Point<T>(proj(x.data)); }\n\ntemplate\
    \ < typename T >\nT cross(const Point<T> &a, const Point<T> &b){ return a.real()\
    \ * b.imag() - a.imag() * b.real(); }\n\ntemplate < typename T >\nT dot(const\
    \ Point<T> &a, const Point<T> &b){ return a.real() * b.real() + a.imag() * b.imag();\
    \ }\n\n} // namespace geometry\n\nnamespace std {\n    template< typename T >\n\
    \    struct tuple_size<geometry::Point<T>> : integral_constant<size_t, 2> {};\n\
    \n    template< size_t N, typename T >\n    struct tuple_element<N, geometry::Point<T>>\
    \ { using type = T; };\n\n} // namespace std\n"
  code: "#pragma once\n#include <iostream>\n#include <complex>\n#include <utility>\n\
    \nnamespace geometry {\n\nconstexpr long double EPS = 1e-12;\n\ntemplate < typename\
    \ T >\nstruct Point {\n    std::complex<T> data;\n\n    Point() : data(0, 0) {}\n\
    \    Point(T a, T b) : data(a, b) {}\n    Point(std::complex<T> c) : data(c) {}\n\
    \n    constexpr T real() const noexcept{ return data.real(); }\n    constexpr\
    \ T imag() const noexcept { return data.imag(); }\n    constexpr Point operator+\
    \ (const Point &r) const noexcept { return Point(*this) += r; }\n    constexpr\
    \ Point operator- (const Point &r) const noexcept { return Point(*this) -= r;\
    \ }\n    constexpr Point operator* (const Point &r) const noexcept { return Point(*this)\
    \ *= r; }\n    constexpr Point operator/ (const Point &r) const noexcept { return\
    \ Point(*this) /= r; }\n    constexpr bool operator==(const Point &x) const noexcept\
    \ { return this->data == x.data; }\n    constexpr bool operator!=(const Point\
    \ &x) const noexcept { return !(*this == x); }\n    constexpr bool operator< (const\
    \ Point &x) const noexcept { return this->real() < x.real() || (!(x.real() < this->real())\
    \ && this->imag() < x.imag()); }\n    constexpr bool operator>=(const Point &x)\
    \ const noexcept { return !(*this < x); }\n    constexpr bool operator> (const\
    \ Point &x) const noexcept { return x < *this; }\n    constexpr bool operator<=(const\
    \ Point &x) const noexcept { return !(*this > x); }\n    \n    constexpr Point&\
    \ operator+=(const Point &x) noexcept {\n        this->data += x.data;\n     \
    \   return *this;\n    }\n    constexpr Point& operator-=(const Point &x) noexcept\
    \ {\n        this->data -= x.data;\n        return *this;\n    }\n    constexpr\
    \ Point& operator*=(const Point &x) noexcept {\n        this->data *= x.data;\n\
    \        return *this;\n    }\n    constexpr Point& operator/=(const Point &x)\
    \ noexcept {\n        this->data /= x.data;\n        return *this;\n    }\n\n\
    \    friend constexpr std::ostream& operator<< (std::ostream& os, const Point&\
    \ x) noexcept {\n        os << x.real() << \" \" << x.imag();\n        return\
    \ os;\n    }\n    friend constexpr std::istream& operator>>(std::istream& is,\
    \ Point& x) noexcept {\n        T a, b;\n        is >> a >> b;\n        x = Point(a,\
    \ b);\n        return is;\n    }\n\n    template <std::size_t N>\n    T get()\
    \ const{\n        if constexpr (N == 0) return data.real();\n        else return\
    \ data.imag();\n    }\n};\n\ntemplate < typename T>\nT abs(const Point<T> &x)\
    \ { return abs(x.data); }\n\ntemplate < typename T>\nT arg(const Point<T> &x)\
    \ { return arg(x.data); }\n\ntemplate < typename T>\nT norm(const Point<T> &x)\
    \ { return norm(x.data); }\n\ntemplate < typename T>\nPoint<T> conj(const Point<T>\
    \ &x) { return Point<T>(conj(x.data)); }\n\ntemplate < typename T>\nPoint<T> proj(const\
    \ Point<T> &x) { return Point<T>(proj(x.data)); }\n\ntemplate < typename T >\n\
    T cross(const Point<T> &a, const Point<T> &b){ return a.real() * b.imag() - a.imag()\
    \ * b.real(); }\n\ntemplate < typename T >\nT dot(const Point<T> &a, const Point<T>\
    \ &b){ return a.real() * b.real() + a.imag() * b.imag(); }\n\n} // namespace geometry\n\
    \nnamespace std {\n    template< typename T >\n    struct tuple_size<geometry::Point<T>>\
    \ : integral_constant<size_t, 2> {};\n\n    template< size_t N, typename T >\n\
    \    struct tuple_element<N, geometry::Point<T>> { using type = T; };\n\n} //\
    \ namespace std"
  dependsOn: []
  isVerificationFile: false
  path: snow/geometry/template.hpp
  requiredBy:
  - snow/geometry/convex-hull.hpp
  - snow/geometry/ccw.hpp
  - snow/geometry/rotating-calipers.hpp
  - snow/geometry/area.hpp
  timestamp: '2021-04-24 10:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_4_A.test.cpp
documentation_of: snow/geometry/template.hpp
layout: document
redirect_from:
- /library/snow/geometry/template.hpp
- /library/snow/geometry/template.hpp.html
title: snow/geometry/template.hpp
---
