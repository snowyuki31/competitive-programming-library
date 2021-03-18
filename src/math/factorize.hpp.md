---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/oj/factorize.test.cpp
    title: test/oj/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/factorize.hpp\"\n#include<map>\r\n\r\nnamespace\
    \ snow {\r\n\r\ntemplate<typename T>\r\nstd::map<T, int> factorize(T v){\r\n \
    \   std::map<T, int> ret;\r\n    for(int i = 2; i * i <= v; ++i){\r\n        while(!(v\
    \ % i)) ret[i]++, v /= i;\r\n    }\r\n    if(v != 1) ret[v]++;\r\n    return ret;\r\
    \n}\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n#include<map>\r\n\r\nnamespace snow {\r\n\r\ntemplate<typename\
    \ T>\r\nstd::map<T, int> factorize(T v){\r\n    std::map<T, int> ret;\r\n    for(int\
    \ i = 2; i * i <= v; ++i){\r\n        while(!(v % i)) ret[i]++, v /= i;\r\n  \
    \  }\r\n    if(v != 1) ret[v]++;\r\n    return ret;\r\n}\r\n\r\n} // namespace\
    \ snow"
  dependsOn: []
  isVerificationFile: false
  path: src/math/factorize.hpp
  requiredBy: []
  timestamp: '2021-03-19 07:19:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/oj/factorize.test.cpp
documentation_of: src/math/factorize.hpp
layout: document
redirect_from:
- /library/src/math/factorize.hpp
- /library/src/math/factorize.hpp.html
title: src/math/factorize.hpp
---
