---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/monoids/min.hpp\"\n\nnamespace snow {\n\n    template\
    \ < typename T >\n    struct min_monoid {\n        using value_type = T;\n   \
    \     static value_type e() { return std::numeric_limits<T>::max(); };\n     \
    \   static value_type op(value_type l, value_type r){ return std::min(l, r); };\n\
    \n        struct add {\n            using f_type = T;\n            static value_type\
    \ mapping(f_type f, value_type x) { return f + x; }\n            static f_type\
    \ composition(f_type f, f_type g) { return f + g; }\n            static f_type\
    \ id(){ return T(); }\n        };\n\n        struct update {\n            struct\
    \ f_type{\n                T val;\n                bool flag;\n            };\n\
    \            static value_type mapping(f_type f, value_type x) { return f.flag\
    \ ? f.val : x; }\n            static f_type composition(f_type f, f_type g) {\
    \ return f.flag ? f : g; }\n            static f_type id(){ return {T(), false};\
    \ }\n        };\n    };\n\n} // namespace snow\n"
  code: "#pragma once\n\nnamespace snow {\n\n    template < typename T >\n    struct\
    \ min_monoid {\n        using value_type = T;\n        static value_type e() {\
    \ return std::numeric_limits<T>::max(); };\n        static value_type op(value_type\
    \ l, value_type r){ return std::min(l, r); };\n\n        struct add {\n      \
    \      using f_type = T;\n            static value_type mapping(f_type f, value_type\
    \ x) { return f + x; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f + g; }\n            static f_type id(){ return T(); }\n      \
    \  };\n\n        struct update {\n            struct f_type{\n               \
    \ T val;\n                bool flag;\n            };\n            static value_type\
    \ mapping(f_type f, value_type x) { return f.flag ? f.val : x; }\n           \
    \ static f_type composition(f_type f, f_type g) { return f.flag ? f : g; }\n \
    \           static f_type id(){ return {T(), false}; }\n        };\n    };\n\n\
    } // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/monoids/min.hpp
  requiredBy: []
  timestamp: '2021-03-21 09:14:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: snow/monoids/min.hpp
layout: document
redirect_from:
- /library/snow/monoids/min.hpp
- /library/snow/monoids/min.hpp.html
title: snow/monoids/min.hpp
---
