---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/utils/pair-wrapper.hpp
    title: snow/utils/pair-wrapper.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-lca.hpp
    title: snow/graph/tree/euler-tour-lca.hpp
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
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
  bundledCode: "#line 2 \"snow/monoids/min.hpp\"\n\n#line 2 \"snow/utils/pair-wrapper.hpp\"\
    \n\n#include <limits>\n#include <utility>\n\nnamespace std {\n\ntemplate <typename\
    \ T0, typename T1>\nclass numeric_limits<std::pair<T0, T1>> {\npublic:\n    static\
    \ constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(),\
    \ std::numeric_limits<T1>::min()}; }\n    static constexpr std::pair<T0, T1> max()\
    \ { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }\n\
    };\n\n}  // namespace std\n#line 4 \"snow/monoids/min.hpp\"\n\nnamespace snow\
    \ {\n\n    template < typename T >\n    struct min_monoid {\n        using value_type\
    \ = T;\n        static value_type e() { return std::numeric_limits<T>::max();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::min(l,\
    \ r); };\n\n        struct add {\n            using f_type = T;\n            static\
    \ value_type mapping(f_type f, value_type x) { return f + x; }\n            static\
    \ f_type composition(f_type f, f_type g) { return f + g; }\n            static\
    \ f_type id(){ return T(); }\n        };\n\n        struct update {\n        \
    \    struct f_type{\n                T val;\n                bool flag;\n    \
    \        };\n            static value_type mapping(f_type f, value_type x) { return\
    \ f.flag ? f.val : x; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f.flag ? f : g; }\n            static f_type id(){ return {T(),\
    \ false}; }\n        };\n    };\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include \"snow/utils/pair-wrapper.hpp\"\n\nnamespace snow\
    \ {\n\n    template < typename T >\n    struct min_monoid {\n        using value_type\
    \ = T;\n        static value_type e() { return std::numeric_limits<T>::max();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::min(l,\
    \ r); };\n\n        struct add {\n            using f_type = T;\n            static\
    \ value_type mapping(f_type f, value_type x) { return f + x; }\n            static\
    \ f_type composition(f_type f, f_type g) { return f + g; }\n            static\
    \ f_type id(){ return T(); }\n        };\n\n        struct update {\n        \
    \    struct f_type{\n                T val;\n                bool flag;\n    \
    \        };\n            static value_type mapping(f_type f, value_type x) { return\
    \ f.flag ? f.val : x; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f.flag ? f : g; }\n            static f_type id(){ return {T(),\
    \ false}; }\n        };\n    };\n\n} // namespace snow"
  dependsOn:
  - snow/utils/pair-wrapper.hpp
  isVerificationFile: false
  path: snow/monoids/min.hpp
  requiredBy:
  - snow/graph/tree/euler-tour-path.hpp
  - snow/graph/tree/euler-tour-lca.hpp
  timestamp: '2021-03-23 15:48:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/vertex_add_path_sum.test.cpp
  - test/oj/lowest_common_ancestor_1.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: snow/monoids/min.hpp
layout: document
redirect_from:
- /library/snow/monoids/min.hpp
- /library/snow/monoids/min.hpp.html
title: snow/monoids/min.hpp
---
