---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_4_B.test.cpp
    title: Binary Search
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Search
    links: []
  bundledCode: "#line 2 \"snow/algorithm/binary-search.hpp\"\n\n#include <utility>\n\
    \nnamespace snow {\n\n/**\n * @brief Binary Search\n * @param EPS Sepcify if using\
    \ decimal floating point\n * @return right\n */\ntemplate< typename T, typename\
    \ F >\nT binary_search(T left, T right, F f, T EPS = 1) {\n    while(abs(right\
    \ - left) > EPS){\n        T mid = (right + left) / 2;\n        if(f(mid)) right\
    \ = mid;\n        else left = mid;\n    }\n    return right;\n}\n\n} // namespace\
    \ snow\n"
  code: "#pragma once\n\n#include <utility>\n\nnamespace snow {\n\n/**\n * @brief\
    \ Binary Search\n * @param EPS Sepcify if using decimal floating point\n * @return\
    \ right\n */\ntemplate< typename T, typename F >\nT binary_search(T left, T right,\
    \ F f, T EPS = 1) {\n    while(abs(right - left) > EPS){\n        T mid = (right\
    \ + left) / 2;\n        if(f(mid)) right = mid;\n        else left = mid;\n  \
    \  }\n    return right;\n}\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/algorithm/binary-search.hpp
  requiredBy: []
  timestamp: '2021-03-23 01:20:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_4_B.test.cpp
documentation_of: snow/algorithm/binary-search.hpp
layout: document
redirect_from:
- /library/snow/algorithm/binary-search.hpp
- /library/snow/algorithm/binary-search.hpp.html
title: Binary Search
---
