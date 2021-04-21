---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0430.test.cpp
    title: Rolling Hash
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: XorShift (Random Number Generator)
    links: []
  bundledCode: "#line 2 \"snow/utils/xorshift.hpp\"\n#include <time.h>\n\nnamespace\
    \ snow {\n\n/**\n * @brief XorShift (Random Number Generator)\n */\nstruct xorShift128\
    \ {\n    unsigned long long x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \    xorShift128(unsigned long long seed = time(NULL)) {\n        w ^= seed;\n\
    \    }\n    unsigned long long operator()() {\n        unsigned long long t =\
    \ x ^ (x << 11);\n        x = y; y = z; z = w;\n        return w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8));\n    }\n\n    /**\n     * @brief Get random number in\
    \ [l, r).\n     */\n    unsigned long long operator()(unsigned long long l, unsigned\
    \ long long r) {\n        w = this->operator()();\n        return w % (r - l)\
    \ + l;\n    }\n};\n\n} // namespace snow\n"
  code: "#pragma once\n#include <time.h>\n\nnamespace snow {\n\n/**\n * @brief XorShift\
    \ (Random Number Generator)\n */\nstruct xorShift128 {\n    unsigned long long\
    \ x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n    xorShift128(unsigned\
    \ long long seed = time(NULL)) {\n        w ^= seed;\n    }\n    unsigned long\
    \ long operator()() {\n        unsigned long long t = x ^ (x << 11);\n       \
    \ x = y; y = z; z = w;\n        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\
    \    }\n\n    /**\n     * @brief Get random number in [l, r).\n     */\n    unsigned\
    \ long long operator()(unsigned long long l, unsigned long long r) {\n       \
    \ w = this->operator()();\n        return w % (r - l) + l;\n    }\n};\n\n} //\
    \ namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/utils/xorshift.hpp
  requiredBy: []
  timestamp: '2021-04-21 03:38:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0430.test.cpp
documentation_of: snow/utils/xorshift.hpp
layout: document
redirect_from:
- /library/snow/utils/xorshift.hpp
- /library/snow/utils/xorshift.hpp.html
title: XorShift (Random Number Generator)
---
