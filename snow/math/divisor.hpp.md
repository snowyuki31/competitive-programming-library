---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2932.test.cpp
    title: test/aoj/2932.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/divisor.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace snow {\n\ntemplate < typename T >\nstd::vector<T> divisor(T n) {\n\
    \    std::vector<T> ret;\n    for(T i = 1; i * i <= n; ++i) {\n        if(n %\
    \ i == 0) {\n            ret.emplace_back(i);\n            if(i * i != n) ret.emplace_back(n\
    \ / i);\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n    return\
    \ ret;\n}\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace snow\
    \ {\n\ntemplate < typename T >\nstd::vector<T> divisor(T n) {\n    std::vector<T>\
    \ ret;\n    for(T i = 1; i * i <= n; ++i) {\n        if(n % i == 0) {\n      \
    \      ret.emplace_back(i);\n            if(i * i != n) ret.emplace_back(n / i);\n\
    \        }\n    }\n    std::sort(ret.begin(), ret.end());\n    return ret;\n}\n\
    \n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/divisor.hpp
  requiredBy: []
  timestamp: '2021-03-21 03:28:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2932.test.cpp
documentation_of: snow/math/divisor.hpp
layout: document
redirect_from:
- /library/snow/math/divisor.hpp
- /library/snow/math/divisor.hpp.html
title: snow/math/divisor.hpp
---
