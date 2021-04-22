---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-lca.hpp
    title: "Euler Tour (Lowest Common Ancestor Query)- \u524D\u51E6\u7406$O(N\\log\
      \ N)$, $O(\\log N)$"
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
  - icon: ':heavy_check_mark:'
    path: snow/monoids/min.hpp
    title: snow/monoids/min.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: Segment Tree (Range Min and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: Segment Tree (Range Add and Range Min)
  - icon: ':heavy_check_mark:'
    path: test/oj/lowest_common_ancestor_1.test.cpp
    title: Lowest Common Ancestor (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_path_sum.test.cpp
    title: Vertex Add Path Sum (Euler Tour ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/utils/pair-wrapper.hpp\"\n\n#include <limits>\n#include\
    \ <utility>\n\nnamespace std {\n\ntemplate <typename T0, typename T1>\nclass numeric_limits<std::pair<T0,\
    \ T1>> {\npublic:\n    static constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(),\
    \ std::numeric_limits<T1>::min()}; }\n    static constexpr std::pair<T0, T1> max()\
    \ { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }\n\
    };\n\n}  // namespace std\n"
  code: "#pragma once\n\n#include <limits>\n#include <utility>\n\nnamespace std {\n\
    \ntemplate <typename T0, typename T1>\nclass numeric_limits<std::pair<T0, T1>>\
    \ {\npublic:\n    static constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(),\
    \ std::numeric_limits<T1>::min()}; }\n    static constexpr std::pair<T0, T1> max()\
    \ { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }\n\
    };\n\n}  // namespace std"
  dependsOn: []
  isVerificationFile: false
  path: snow/utils/pair-wrapper.hpp
  requiredBy:
  - snow/monoids/min.hpp
  - snow/graph/tree/euler-tour-path.hpp
  - snow/graph/tree/euler-tour-lca.hpp
  timestamp: '2021-03-23 15:48:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/lowest_common_ancestor_1.test.cpp
  - test/oj/vertex_add_path_sum.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: snow/utils/pair-wrapper.hpp
layout: document
redirect_from:
- /library/snow/utils/pair-wrapper.hpp
- /library/snow/utils/pair-wrapper.hpp.html
title: snow/utils/pair-wrapper.hpp
---
