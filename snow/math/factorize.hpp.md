---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2932.test.cpp
    title: Divisor / Factorize
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: Factorize
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Prime Factorization - $O(\sqrt{n})$
    links: []
  bundledCode: "#line 2 \"snow/math/factorize.hpp\"\n\r\n#include <map>\r\n\r\nnamespace\
    \ snow {\r\n\r\n/**\r\n * @brief Prime Factorization - $O(\\sqrt{n})$\r\n * \r\
    \n * @tparam T \r\n * @param v \r\n */\r\ntemplate < typename T >\r\nstd::map<T,\
    \ int> factorize(T v){\r\n    std::map<T, int> ret;\r\n    for(T i = 2; i * i\
    \ <= v; ++i){\r\n        while(!(v % i)) ret[i]++, v /= i;\r\n    }\r\n    if(v\
    \ != 1) ret[v]++;\r\n    return ret;\r\n}\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n\r\n#include <map>\r\n\r\nnamespace snow {\r\n\r\n/**\r\n\
    \ * @brief Prime Factorization - $O(\\sqrt{n})$\r\n * \r\n * @tparam T \r\n *\
    \ @param v \r\n */\r\ntemplate < typename T >\r\nstd::map<T, int> factorize(T\
    \ v){\r\n    std::map<T, int> ret;\r\n    for(T i = 2; i * i <= v; ++i){\r\n \
    \       while(!(v % i)) ret[i]++, v /= i;\r\n    }\r\n    if(v != 1) ret[v]++;\r\
    \n    return ret;\r\n}\r\n\r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/factorize.hpp
  requiredBy: []
  timestamp: '2021-03-23 06:07:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_A.test.cpp
  - test/aoj/2932.test.cpp
documentation_of: snow/math/factorize.hpp
layout: document
redirect_from:
- /library/snow/math/factorize.hpp
- /library/snow/math/factorize.hpp.html
title: Prime Factorization - $O(\sqrt{n})$
---
