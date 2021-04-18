---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: snow/math/convert-base.hpp
    title: Base Conversion
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lucas's theorem (Binomial Coefficient mod p)
    links: []
  bundledCode: "#line 2 \"snow/math/lucas.hpp\"\n#include <algorithm>\n#line 2 \"\
    snow/math/convert-base.hpp\"\n#include <vector>\n#line 4 \"snow/math/convert-base.hpp\"\
    \n\nnamespace snow {\n/**\n * @brief Base Conversion\n * \n */\ntemplate <typename\
    \ T>\nstd::vector<T> convert_base(T val, T base, int length = 0){\n    std::vector<T>\
    \ ret;\n    T tmp = 1, base_ = abs(base);\n    while(val){\n        T dig = val\
    \ * tmp % base_;\n        if(dig < 0) dig += base_;\n        ret.emplace_back(dig);\n\
    \n        val -= dig * tmp;\n        val /= base_;\n        tmp *= base / base_;\n\
    \    }\n    if(ret.empty()) ret.emplace_back(0);\n\n    if(length){\n        assert(ret.size()\
    \ <= length);\n        while (ret.size() < length) ret.emplace_back(0);\n    }\n\
    \n    std::reverse(ret.begin(), ret.end());\n\n    return ret;\n}\n\n} //namespace\
    \ snow\n#line 4 \"snow/math/lucas.hpp\"\n\nnamespace snow {\n\n/**\n * @brief\
    \ Lucas's theorem (Binomial Coefficient mod p) \n * \n */\nint lucas(int m, int\
    \ n, int p){\n    auto m_ = convert_base(m, p);\n    int l = m_.size();\n    auto\
    \ n_ = convert_base(n, p, l);\n\n    /**\n     * @fn\n     * Calculate binomial\
    \ coefficient in a naive way.\n     * \n     * @brief Calculate binomial coef.\n\
    \     * \n     */\n    auto binom = [](int m, int n)->int {\n        if(m < n)\
    \ return 0;\n        int ret = 1;\n        for (int i = 1; i <= m; ++i) ret *=\
    \ i;\n        for (int i = 1; i <= n; ++i) ret /= i;\n        for (int i = 1;\
    \ i <= m - n; ++i) ret /= i;\n        return ret;\n    };\n\n    int ret = 1;\n\
    \    for(int i = 0; i < l; ++i) ret *= binom(m_[i], n_[i]), ret %= p;\n    return\
    \ ret;\n}\n\n\n} // namespace snow\n"
  code: "#pragma once\n#include <algorithm>\n#include \"snow/math/convert-base.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Lucas's theorem (Binomial Coefficient mod\
    \ p) \n * \n */\nint lucas(int m, int n, int p){\n    auto m_ = convert_base(m,\
    \ p);\n    int l = m_.size();\n    auto n_ = convert_base(n, p, l);\n\n    /**\n\
    \     * @fn\n     * Calculate binomial coefficient in a naive way.\n     * \n\
    \     * @brief Calculate binomial coef.\n     * \n     */\n    auto binom = [](int\
    \ m, int n)->int {\n        if(m < n) return 0;\n        int ret = 1;\n      \
    \  for (int i = 1; i <= m; ++i) ret *= i;\n        for (int i = 1; i <= n; ++i)\
    \ ret /= i;\n        for (int i = 1; i <= m - n; ++i) ret /= i;\n        return\
    \ ret;\n    };\n\n    int ret = 1;\n    for(int i = 0; i < l; ++i) ret *= binom(m_[i],\
    \ n_[i]), ret %= p;\n    return ret;\n}\n\n\n} // namespace snow"
  dependsOn:
  - snow/math/convert-base.hpp
  isVerificationFile: false
  path: snow/math/lucas.hpp
  requiredBy: []
  timestamp: '2021-04-19 02:46:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/math/lucas.hpp
layout: document
title: Lucas's theorem (Binomial Coefficient mod p)
---

## About

Lucasの定理に基づいて，$\binom{m}{n} \bmod{p}$を求めます．

ただし，$p$は素数です．

この実装では二項係数は愚直に求めているので，計算量は$O(p\log_p m)$です．

$p$が素数でなくても求める方法もあるようです．