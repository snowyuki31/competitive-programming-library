---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: snow/math/lucas.hpp
    title: Lucas's theorem (Binomial Coefficient mod p)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/0499.test.cpp
    title: Conversion Base (base 7)
  - icon: ':x:'
    path: test/yukicoder/0782.test.cpp
    title: Conversion Base (negative base)
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Base Conversion
    links: []
  bundledCode: "#line 2 \"snow/math/convert-base.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace snow {\n/**\n * @brief Base Conversion\n * \n */\n\
    template <typename T>\nstd::vector<T> convert_base(T val, T base, int length =\
    \ 0){\n    std::vector<T> ret;\n    T tmp = 1, base_ = abs(base);\n    while(val){\n\
    \        T dig = val * tmp % base_;\n        if(dig < 0) dig += base_;\n     \
    \   ret.emplace_back(dig);\n\n        val -= dig * tmp;\n        val /= base_;\n\
    \        tmp *= base / base_;\n    }\n    if(ret.empty()) ret.emplace_back(0);\n\
    \n    if(length){\n        assert(ret.size() <= length);\n        while (ret.size()\
    \ < length) ret.emplace_back(0);\n    }\n\n    std::reverse(ret.begin(), ret.end());\n\
    \n    return ret;\n}\n\n} //namespace snow\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace snow {\n\
    /**\n * @brief Base Conversion\n * \n */\ntemplate <typename T>\nstd::vector<T>\
    \ convert_base(T val, T base, int length = 0){\n    std::vector<T> ret;\n    T\
    \ tmp = 1, base_ = abs(base);\n    while(val){\n        T dig = val * tmp % base_;\n\
    \        if(dig < 0) dig += base_;\n        ret.emplace_back(dig);\n\n       \
    \ val -= dig * tmp;\n        val /= base_;\n        tmp *= base / base_;\n   \
    \ }\n    if(ret.empty()) ret.emplace_back(0);\n\n    if(length){\n        assert(ret.size()\
    \ <= length);\n        while (ret.size() < length) ret.emplace_back(0);\n    }\n\
    \n    std::reverse(ret.begin(), ret.end());\n\n    return ret;\n}\n\n} //namespace\
    \ snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/convert-base.hpp
  requiredBy:
  - snow/math/lucas.hpp
  timestamp: '2021-04-19 02:46:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/0782.test.cpp
  - test/yukicoder/0499.test.cpp
documentation_of: snow/math/convert-base.hpp
layout: document
redirect_from:
- /library/snow/math/convert-base.hpp
- /library/snow/math/convert-base.hpp.html
title: Base Conversion
---
