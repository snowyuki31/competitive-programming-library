---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/utils/pair-wrapper.hpp
    title: snow/utils/pair-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/monoids/max.hpp\"\n\n#line 2 \"snow/utils/pair-wrapper.hpp\"\
    \n\n#include <limits>\n#include <utility>\n\nnamespace std {\n\ntemplate <typename\
    \ T0, typename T1>\nclass numeric_limits<std::pair<T0, T1>> {\npublic:\n    static\
    \ constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(),\
    \ std::numeric_limits<T1>::min()}; }\n    static constexpr std::pair<T0, T1> max()\
    \ { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }\n\
    };\n\n}  // namespace std\n#line 4 \"snow/monoids/max.hpp\"\n\nnamespace snow\
    \ {\n\n    template < typename T >\n    struct max_monoid {\n        using value_type\
    \ = T;\n        static value_type e() { return std::numeric_limits<T>::min();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::max(l,\
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
    \ {\n\n    template < typename T >\n    struct max_monoid {\n        using value_type\
    \ = T;\n        static value_type e() { return std::numeric_limits<T>::min();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::max(l,\
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
  path: snow/monoids/max.hpp
  requiredBy: []
  timestamp: '2021-05-03 16:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/monoids/max.hpp
layout: document
redirect_from:
- /library/snow/monoids/max.hpp
- /library/snow/monoids/max.hpp.html
title: snow/monoids/max.hpp
---
