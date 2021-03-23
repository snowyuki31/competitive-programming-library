---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_G.test.cpp
    title: Segment Tree (Range Add and Range Sum)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: Segment Tree (Range Add and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/oj/range_affine_range_sum.test.cpp
    title: Segment Tree (Range Affine and Range Sum with Modint)
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/monoids/plus-size.hpp\"\n\nnamespace snow {\n\n   \
    \ template < typename T >\n    struct plus_size_monoid {\n        struct value_type\
    \ {\n            T val;\n            int size;\n        };\n        static value_type\
    \ e() { return value_type{0, 0}; };\n        static value_type op(value_type l,\
    \ value_type r) { return {l.val + r.val, l.size + r.size}; };\n\n        struct\
    \ add {\n            using f_type = T;\n            static value_type mapping(f_type\
    \ f, value_type x) { return {f * x.size + x.val, x.size}; }\n            static\
    \ f_type composition(f_type f, f_type g) { return f + g; }\n            static\
    \ f_type id(){ return T(); }\n        };\n\n        struct update {\n        \
    \    struct f_type{\n                T val;\n                bool flag;\n    \
    \        };\n            static value_type mapping(f_type f, value_type x) { return\
    \ {(f.flag ? f.val * x.size : x.val), x.size}; }\n            static f_type composition(f_type\
    \ f, f_type g) { return f.flag ? f : g; }\n            static f_type id(){ return\
    \ {T(), false}; }\n        };\n\n        struct affine {\n            using f_type\
    \ = std::pair<T, T>;\n            static value_type mapping(f_type f, value_type\
    \ x) { return {x.val * f.first + x.size * f.second, x.size}; }\n            static\
    \ f_type composition(f_type f, f_type g) { return {g.first * f.first, g.second\
    \ * f.first + f.second}; }\n            static f_type id(){ return {1, 0}; }\n\
    \        };\n    };\n\n} // namespace snow\n"
  code: "#pragma once\n\nnamespace snow {\n\n    template < typename T >\n    struct\
    \ plus_size_monoid {\n        struct value_type {\n            T val;\n      \
    \      int size;\n        };\n        static value_type e() { return value_type{0,\
    \ 0}; };\n        static value_type op(value_type l, value_type r) { return {l.val\
    \ + r.val, l.size + r.size}; };\n\n        struct add {\n            using f_type\
    \ = T;\n            static value_type mapping(f_type f, value_type x) { return\
    \ {f * x.size + x.val, x.size}; }\n            static f_type composition(f_type\
    \ f, f_type g) { return f + g; }\n            static f_type id(){ return T();\
    \ }\n        };\n\n        struct update {\n            struct f_type{\n     \
    \           T val;\n                bool flag;\n            };\n            static\
    \ value_type mapping(f_type f, value_type x) { return {(f.flag ? f.val * x.size\
    \ : x.val), x.size}; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f.flag ? f : g; }\n            static f_type id(){ return {T(),\
    \ false}; }\n        };\n\n        struct affine {\n            using f_type =\
    \ std::pair<T, T>;\n            static value_type mapping(f_type f, value_type\
    \ x) { return {x.val * f.first + x.size * f.second, x.size}; }\n            static\
    \ f_type composition(f_type f, f_type g) { return {g.first * f.first, g.second\
    \ * f.first + f.second}; }\n            static f_type id(){ return {1, 0}; }\n\
    \        };\n    };\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/monoids/plus-size.hpp
  requiredBy: []
  timestamp: '2021-03-21 09:43:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/oj/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: snow/monoids/plus-size.hpp
layout: document
redirect_from:
- /library/snow/monoids/plus-size.hpp
- /library/snow/monoids/plus-size.hpp.html
title: snow/monoids/plus-size.hpp
---
