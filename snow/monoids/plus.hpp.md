---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: Segment Tree (Point Set and Range Sum)
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/monoids/plus.hpp\"\n\nnamespace snow {\n\n    template\
    \ < typename T >\n    struct plus_monoid {\n        using value_type = T;\n  \
    \      static value_type e() { return T(); };\n        static value_type op(value_type\
    \ l, value_type r){ return l + r; };\n    };\n\n} // namespace snow\n"
  code: "#pragma once\n\nnamespace snow {\n\n    template < typename T >\n    struct\
    \ plus_monoid {\n        using value_type = T;\n        static value_type e()\
    \ { return T(); };\n        static value_type op(value_type l, value_type r){\
    \ return l + r; };\n    };\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/monoids/plus.hpp
  requiredBy:
  - snow/graph/tree/euler-tour-path.hpp
  timestamp: '2021-03-21 08:45:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/vertex_add_path_sum_2.test.cpp
  - test/oj/vertex_add_path_sum.test.cpp
  - test/oj/vertex_add_subtree_sum_2.test.cpp
  - test/oj/vertex_add_subtree_sum.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: snow/monoids/plus.hpp
layout: document
redirect_from:
- /library/snow/monoids/plus.hpp
- /library/snow/monoids/plus.hpp.html
title: snow/monoids/plus.hpp
---
