---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_4_B.test.cpp
    title: test/aoj/ALDS1_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/algorithm/binary-search.hpp\"\n\n#include <utility>\n\
    \nnamespace snow {\n\n// [left, right)\ntemplate< typename T, typename F >\nT\
    \ binary_search(T left, T right, F f, T EPS = 1) {\n    while(abs(right - left)\
    \ > EPS){\n        T mid = (right + left) / 2;\n        if(f(mid)) right = mid;\n\
    \        else left = mid;\n    }\n    return right;\n}\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <utility>\n\nnamespace snow {\n\n// [left, right)\n\
    template< typename T, typename F >\nT binary_search(T left, T right, F f, T EPS\
    \ = 1) {\n    while(abs(right - left) > EPS){\n        T mid = (right + left)\
    \ / 2;\n        if(f(mid)) right = mid;\n        else left = mid;\n    }\n   \
    \ return right;\n}\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/algorithm/binary-search.hpp
  requiredBy: []
  timestamp: '2021-03-20 06:51:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_4_B.test.cpp
documentation_of: snow/algorithm/binary-search.hpp
layout: document
redirect_from:
- /library/snow/algorithm/binary-search.hpp
- /library/snow/algorithm/binary-search.hpp.html
title: snow/algorithm/binary-search.hpp
---