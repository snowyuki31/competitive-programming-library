---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1013.test.cpp
    title: test/yukicoder/1013.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/utils/xorshift.hpp\"\n\nnamespace snow {\n\nstruct\
    \ xorShift128 {\n    unsigned long long x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n    xorShift128(unsigned long long seed = 0) {\n        w ^=\
    \ seed;\n    }\n    unsigned long long operator()() {\n        unsigned long long\
    \ t = x ^ (x << 11);\n        x = y; y = z; z = w;\n        return w = (w ^ (w\
    \ >> 19)) ^ (t ^ (t >> 8));\n    }\n};\n\n} // namespace snow\n"
  code: "#pragma once\n\nnamespace snow {\n\nstruct xorShift128 {\n    unsigned long\
    \ long x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n    xorShift128(unsigned\
    \ long long seed = 0) {\n        w ^= seed;\n    }\n    unsigned long long operator()()\
    \ {\n        unsigned long long t = x ^ (x << 11);\n        x = y; y = z; z =\
    \ w;\n        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n};\n\n} //\
    \ namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/utils/xorshift.hpp
  requiredBy: []
  timestamp: '2021-03-21 19:40:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1013.test.cpp
documentation_of: snow/utils/xorshift.hpp
layout: document
redirect_from:
- /library/snow/utils/xorshift.hpp
- /library/snow/utils/xorshift.hpp.html
title: snow/utils/xorshift.hpp
---
