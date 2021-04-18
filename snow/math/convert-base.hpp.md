---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0499.test.cpp
    title: Conversion Base (base 7)
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0782.test.cpp
    title: Conversion Base (negative base)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Base Conversion
    links: []
  bundledCode: "#line 2 \"snow/math/convert-base.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace snow {\n    /**\n     * @brief Base Conversion\n  \
    \   * \n     */\n    template <typename T>\n    std::vector<T> convert_base(T\
    \ val, T base){\n        std::vector<T> ret;\n        T tmp = 1, base_ = abs(base);\n\
    \        while(val){\n            T dig = val * tmp % base_;\n            if(dig\
    \ < 0) dig += base_;\n            ret.emplace_back(dig);\n\n            val -=\
    \ dig * tmp;\n            val /= base_;\n            tmp *= base / base_;\n  \
    \      }\n        if(ret.empty()) ret.emplace_back(0);\n        std::reverse(ret.begin(),\
    \ ret.end());\n\n        return ret;\n    };\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace snow {\n\
    \    /**\n     * @brief Base Conversion\n     * \n     */\n    template <typename\
    \ T>\n    std::vector<T> convert_base(T val, T base){\n        std::vector<T>\
    \ ret;\n        T tmp = 1, base_ = abs(base);\n        while(val){\n         \
    \   T dig = val * tmp % base_;\n            if(dig < 0) dig += base_;\n      \
    \      ret.emplace_back(dig);\n\n            val -= dig * tmp;\n            val\
    \ /= base_;\n            tmp *= base / base_;\n        }\n        if(ret.empty())\
    \ ret.emplace_back(0);\n        std::reverse(ret.begin(), ret.end());\n\n    \
    \    return ret;\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/convert-base.hpp
  requiredBy: []
  timestamp: '2021-04-19 02:03:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
