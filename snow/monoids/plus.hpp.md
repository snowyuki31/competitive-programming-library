---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  requiredBy: []
  timestamp: '2021-03-21 08:45:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
documentation_of: snow/monoids/plus.hpp
layout: document
redirect_from:
- /library/snow/monoids/plus.hpp
- /library/snow/monoids/plus.hpp.html
title: snow/monoids/plus.hpp
---
