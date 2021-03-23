---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: Euler's totient function
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Euler's totient function - $O(\sqrt{n})$
    links: []
  bundledCode: "#line 2 \"snow/math/euler-phi.hpp\"\n\r\nnamespace snow {\r\n\r\n\
    /**\r\n * @brief Euler's totient function - $O(\\sqrt{n})$\r\n * \r\n * @tparam\
    \ T \r\n * @param n \r\n */\r\ntemplate < typename T >\r\nT euler_phi(T n) {\r\
    \n   T ret = n;\r\n   for(T i = 2; i * i <= n; ++i){\r\n       if(n % i == 0)\
    \ {\r\n           ret -= ret / i;\r\n           while(n % i == 0) n /= i;\r\n\
    \       }\r\n   }\r\n   if(n > 1) ret -= ret / n;\r\n   return ret;\r\n}\r\n\r\
    \n} // namespace snow\n"
  code: "#pragma once\r\n\r\nnamespace snow {\r\n\r\n/**\r\n * @brief Euler's totient\
    \ function - $O(\\sqrt{n})$\r\n * \r\n * @tparam T \r\n * @param n \r\n */\r\n\
    template < typename T >\r\nT euler_phi(T n) {\r\n   T ret = n;\r\n   for(T i =\
    \ 2; i * i <= n; ++i){\r\n       if(n % i == 0) {\r\n           ret -= ret / i;\r\
    \n           while(n % i == 0) n /= i;\r\n       }\r\n   }\r\n   if(n > 1) ret\
    \ -= ret / n;\r\n   return ret;\r\n}\r\n\r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/euler-phi.hpp
  requiredBy: []
  timestamp: '2021-03-23 06:07:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: snow/math/euler-phi.hpp
layout: document
redirect_from:
- /library/snow/math/euler-phi.hpp
- /library/snow/math/euler-phi.hpp.html
title: Euler's totient function - $O(\sqrt{n})$
---