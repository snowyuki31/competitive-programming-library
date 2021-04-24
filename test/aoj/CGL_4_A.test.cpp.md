---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/geometry/ccw.hpp
    title: Counter-Clockwise
  - icon: ':heavy_check_mark:'
    path: snow/geometry/convex-hull.hpp
    title: Convex-Hull
  - icon: ':heavy_check_mark:'
    path: snow/geometry/template.hpp
    title: snow/geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja
    document_title: Convex-Hull
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja
  bundledCode: "#line 1 \"test/aoj/CGL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja\"\
    \n#include <algorithm>\n#include <iostream>\n#include <utility>\n#line 2 \"snow/geometry/convex-hull.hpp\"\
    \n#include <vector>\n#line 2 \"snow/geometry/geometry\"\n\n#line 3 \"snow/geometry/template.hpp\"\
    \n#include <complex>\n#line 5 \"snow/geometry/template.hpp\"\n\nnamespace geometry\
    \ {\n\nconstexpr long double EPS = 1e-12;\n\ntemplate < typename T >\nstruct Point\
    \ {\n    std::complex<T> data;\n\n    Point() : data(0, 0) {}\n    Point(T a,\
    \ T b) : data(a, b) {}\n    Point(std::complex<T> c) : data(c) {}\n\n    constexpr\
    \ T real() const noexcept{ return data.real(); }\n    constexpr T imag() const\
    \ noexcept { return data.imag(); }\n    constexpr Point operator+ (const Point\
    \ &r) const noexcept { return Point(*this) += r; }\n    constexpr Point operator-\
    \ (const Point &r) const noexcept { return Point(*this) -= r; }\n    constexpr\
    \ Point operator* (const Point &r) const noexcept { return Point(*this) *= r;\
    \ }\n    constexpr Point operator/ (const Point &r) const noexcept { return Point(*this)\
    \ /= r; }\n    constexpr bool operator==(const Point &x) const noexcept { return\
    \ this->data == x.data; }\n    constexpr bool operator!=(const Point &x) const\
    \ noexcept { return !(*this == x); }\n    constexpr bool operator< (const Point\
    \ &x) const noexcept { return this->real() < x.real() || (!(x.real() < this->real())\
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
    \ namespace std\n#line 3 \"snow/geometry/ccw.hpp\"\n\nnamespace geometry {\n\n\
    enum CCW_RESULT { CCW = +1, CW = -1, BACK = +2, FRONT = -2, ON = 0 };\n\n/**\n\
    \ * @brief Counter-Clockwise\n * \n */\ntemplate< typename T >\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C){\n    B -= A, C -= A;\n    if(cross(B, C) > EPS)\
    \ return CCW;\n    if(cross(B, C) < -EPS) return CW;\n    if(dot(B, C) < 0) return\
    \ BACK;\n    if(norm(B) < norm(C)) return FRONT;\n    return ON;\n}\n\n} // namespace\
    \ geometry\n#line 5 \"snow/geometry/convex-hull.hpp\"\n\nnamespace geometry {\n\
    \n/**\n * @brief Convex-Hull\n * \n */\ntemplate < typename T >\nstd::vector<Point<T>>\
    \ convex_hull(std::vector<Point<T>> X){\n    std::sort(X.begin(), X.end());\n\
    \    int k = 0;\n    int n = X.size();\n    std::vector<Point<T>> res(2 * n);\n\
    \    for(int i = 0; i < n; ++i){\n        while(k > 1 and ccw(res[k - 2], res[k\
    \ - 1], X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    for(int i = n\
    \ - 2, t = k; i >= 0; --i){\n        while(k > t and ccw(res[k - 2], res[k - 1],\
    \ X[i]) == CW) --k;\n        res[k++] = X[i];\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}\n\n} // namespace geometry\n#line 6 \"test/aoj/CGL_4_A.test.cpp\"\
    \n\n/**\n * @brief Convex-Hull\n */\nint main() {\n    int N;\n    std::cin >>\
    \ N;\n    std::vector<geometry::Point<long double>> points(N);\n    for (int i\
    \ = 0; i < N; ++i) std::cin >> points[i];\n\n    auto ret = geometry::convex_hull(points);\n\
    \    \n    int min_pos;\n    int x = 1e6, y = 1e6;\n    for (int i = 0; i < (int)ret.size();\
    \ ++i){\n        auto [a, b] = ret[i];\n        if(b < y or (b == y and a < x))\
    \ x = a, y = b, min_pos = i;\n    }\n\n    std::rotate(ret.begin(), ret.begin()\
    \ + min_pos, ret.end());\n\n    std::cout << ret.size() << '\\n';\n    for(auto\
    \ r : ret) std::cout << r << '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja\"\
    \n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include \"snow/geometry/convex-hull.hpp\"\
    \n\n/**\n * @brief Convex-Hull\n */\nint main() {\n    int N;\n    std::cin >>\
    \ N;\n    std::vector<geometry::Point<long double>> points(N);\n    for (int i\
    \ = 0; i < N; ++i) std::cin >> points[i];\n\n    auto ret = geometry::convex_hull(points);\n\
    \    \n    int min_pos;\n    int x = 1e6, y = 1e6;\n    for (int i = 0; i < (int)ret.size();\
    \ ++i){\n        auto [a, b] = ret[i];\n        if(b < y or (b == y and a < x))\
    \ x = a, y = b, min_pos = i;\n    }\n\n    std::rotate(ret.begin(), ret.begin()\
    \ + min_pos, ret.end());\n\n    std::cout << ret.size() << '\\n';\n    for(auto\
    \ r : ret) std::cout << r << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - snow/geometry/convex-hull.hpp
  - snow/geometry/template.hpp
  - snow/geometry/ccw.hpp
  isVerificationFile: true
  path: test/aoj/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2021-04-24 10:08:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_A.test.cpp
- /verify/test/aoj/CGL_4_A.test.cpp.html
title: Convex-Hull
---