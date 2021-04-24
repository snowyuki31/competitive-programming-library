---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: Cumurative Sum (2D)
  - icon: ':heavy_check_mark:'
    path: test/aoj/2320.test.cpp
    title: Doubling
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_4_B.test.cpp
    title: Binary Search
  - icon: ':heavy_check_mark:'
    path: test/oj/tree_diameter.test.cpp
    title: Tree Diameter
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_path_sum.test.cpp
    title: Vertex Add Path Sum (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_path_sum_2.test.cpp
    title: Vertex Add Path Sum (Heavy Light Decomposition ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_subtree_sum.test.cpp
    title: Vertex Add Subtree Sum (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_subtree_sum_2.test.cpp
    title: Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0517.test.cpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1065.test.cpp
    title: Dijkstra (decimal floating point ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/io/helper.hpp\"\n#include <iostream>\n#include <vector>\n\
    #include <set>\n\ntemplate< typename T1, typename T2 >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::pair< T1, T2 > &p) {\n    os << p.first <<\
    \ \" \" << p.second;\n    return os;\n}\n\ntemplate< typename T1, typename T2\
    \ >\nstd::istream &operator >> (std::istream &is, std::pair< T1, T2 > &p) {\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate< typename T1, typename\
    \ T2, typename T3 >\nstd::ostream &operator << (std::ostream &os, const std::tuple<\
    \ T1, T2, T3 > &t) {\n    auto &[a, b, c] = t;\n    os << a << \" \" << b << \"\
    \ \" << c;\n    return os;\n}\n\ntemplate< typename T1, typename T2, typename\
    \ T3 >\nstd::istream &operator >> (std::istream &is, std::tuple< T1, T2, T3 >\
    \ &t) {\n    auto &[a, b, c] = t;\n    is >> a >> b >> c;\n    return is;\n}\n\
    \ntemplate< typename T >\nstd::ostream &operator << (std::ostream &os, const std::vector<\
    \ T > &v){\n    for (int i = 0; i < (int)v.size(); ++i) {\n        os << v[i]\
    \ << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate<\
    \ typename T >\nstd::istream &operator >>  (std::istream &is, std::vector< T >\
    \ &v){\n    for(T &in : v) is >> in;\n    return is;\n}\n\ntemplate< typename\
    \ T >\nstd::ostream &operator << (std::ostream &os, const std::set< T > &st){\n\
    \    int ct = 0;\n    for(auto& s : st) os << s << (++ct != (int)st.size() ? \"\
    \ \" : \"\");\n    return os;\n}\n\ntemplate<class... T>\nvoid input(T&... a){\n\
    \    (std::cin >> ... >> a);\n}\n\nvoid print() {\n    std::cout << '\\n';\n}\n\
    template<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n    std::cout\
    \ << a;\n    (std::cout << ... << (std::cout << ' ', b));\n    std::cout << '\\\
    n';\n}\n\nint drop() {\n    std::cout << '\\n';\n    exit(0);\n}\ntemplate<class\
    \ T, class... Ts>\nint drop(const T& a, const Ts&... b){\n    std::cout << a;\n\
    \    (std::cout << ... << (std::cout << ' ', b));\n    std::cout << '\\n';\n \
    \   exit(0);\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <set>\n\n\
    template< typename T1, typename T2 >\nstd::ostream &operator << (std::ostream\
    \ &os, const std::pair< T1, T2 > &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\n\ntemplate< typename T1, typename T2 >\nstd::istream &operator\
    \ >> (std::istream &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {\n    auto\
    \ &[a, b, c] = t;\n    os << a << \" \" << b << \" \" << c;\n    return os;\n\
    }\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::istream &operator\
    \ >> (std::istream &is, std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b, c] =\
    \ t;\n    is >> a >> b >> c;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::vector< T > &v){\n    for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n        os << v[i] << (i + 1 != v.size() ? \"\
    \ \" : \"\");\n    }\n    return os;\n}\n\ntemplate< typename T >\nstd::istream\
    \ &operator >>  (std::istream &is, std::vector< T > &v){\n    for(T &in : v) is\
    \ >> in;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::set< T > &st){\n    int ct = 0;\n    for(auto&\
    \ s : st) os << s << (++ct != (int)st.size() ? \" \" : \"\");\n    return os;\n\
    }\n\ntemplate<class... T>\nvoid input(T&... a){\n    (std::cin >> ... >> a);\n\
    }\n\nvoid print() {\n    std::cout << '\\n';\n}\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    std::cout << a;\n    (std::cout <<\
    \ ... << (std::cout << ' ', b));\n    std::cout << '\\n';\n}\n\nint drop() {\n\
    \    std::cout << '\\n';\n    exit(0);\n}\ntemplate<class T, class... Ts>\nint\
    \ drop(const T& a, const Ts&... b){\n    std::cout << a;\n    (std::cout << ...\
    \ << (std::cout << ' ', b));\n    std::cout << '\\n';\n    exit(0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: snow/io/helper.hpp
  requiredBy: []
  timestamp: '2021-04-21 03:38:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1065.test.cpp
  - test/yukicoder/0517.test.cpp
  - test/oj/vertex_add_path_sum_2.test.cpp
  - test/oj/vertex_add_path_sum.test.cpp
  - test/oj/vertex_add_subtree_sum_2.test.cpp
  - test/oj/tree_diameter.test.cpp
  - test/oj/vertex_add_subtree_sum.test.cpp
  - test/aoj/ALDS1_4_B.test.cpp
  - test/aoj/0560.test.cpp
  - test/aoj/2320.test.cpp
documentation_of: snow/io/helper.hpp
layout: document
redirect_from:
- /library/snow/io/helper.hpp
- /library/snow/io/helper.hpp.html
title: snow/io/helper.hpp
---
