---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/euler_phi_a.test.cpp
    title: test/aoj/euler_phi_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/euler_phi.hpp\"\n\r\nnamespace snow {\r\n\r\ntemplate\
    \ <typename T>\r\nT euler_phi(T n) {\r\n   T ret = n;\r\n   for(T i = 2; i * i\
    \ <= n; ++i){\r\n       if(n % i == 0) {\r\n           ret -= ret / i;\r\n   \
    \        while(n % i == 0) n /= i;\r\n       }\r\n   }\r\n   if(n > 1) ret -=\
    \ ret / n;\r\n   return ret;\r\n}\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n\r\nnamespace snow {\r\n\r\ntemplate <typename T>\r\nT euler_phi(T\
    \ n) {\r\n   T ret = n;\r\n   for(T i = 2; i * i <= n; ++i){\r\n       if(n %\
    \ i == 0) {\r\n           ret -= ret / i;\r\n           while(n % i == 0) n /=\
    \ i;\r\n       }\r\n   }\r\n   if(n > 1) ret -= ret / n;\r\n   return ret;\r\n\
    }\r\n\r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: src/math/euler_phi.hpp
  requiredBy: []
  timestamp: '2021-03-19 09:17:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/euler_phi_a.test.cpp
documentation_of: src/math/euler_phi.hpp
layout: document
redirect_from:
- /library/src/math/euler_phi.hpp
- /library/src/math/euler_phi.hpp.html
title: src/math/euler_phi.hpp
---
