---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: Twelvefold way V
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1035.test.cpp
    title: Twelvefold way III
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Binomial Coefficient - $\\binom{n}{k}$ \u524D\u51E6\u7406$O(n)$,\
      \ $O(1)$"
    links: []
  bundledCode: "#line 2 \"snow/math/binomial.hpp\"\n\n#include <vector>\n\nnamespace\
    \ snow {\n\n/**\n * @brief Binomial Coefficient - $\\binom{n}{k}$ \u524D\u51E6\
    \u7406$O(n)$, $O(1)$\n * @param N max N\n * @tparam mint \n */\ntemplate < typename\
    \ mint >\nstruct Binomial {\n    public:\n        Binomial(int N) : _N(N + 1),\
    \ _M(mint::mod()), fac(_N), finv(_N), inv(_N) {\n            fac[0] = fac[1] =\
    \ 1;\n            finv[0] = finv[1] = 1;\n            inv[1] = 1;\n          \
    \  for (int i = 2; i < _N; ++i) {\n                fac[i] = fac[i - 1] * i;\n\
    \                inv[i] = _M - inv[_M % i] * (_M / i);\n                finv[i]\
    \ = finv[i - 1] * inv[i];\n            }\n        }\n\n        /**\n         *\
    \ @brief Calculate nCk\n         * \n         * @param n \n         * @param k\
    \ \n         */\n        mint get(int n, int k){\n            if (n < k) return\
    \ 0;\n            if (n < 0 || k < 0) return 0;\n            return fac[n] * finv[k]\
    \ * finv[n - k];\n        }\n\n    protected:\n        const int _N;\n       \
    \ const int _M;\n        std::vector<mint> fac, finv, inv;\n};\n\n} // namespace\
    \ snow\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace snow {\n\n/**\n * @brief Binomial\
    \ Coefficient - $\\binom{n}{k}$ \u524D\u51E6\u7406$O(n)$, $O(1)$\n * @param N\
    \ max N\n * @tparam mint \n */\ntemplate < typename mint >\nstruct Binomial {\n\
    \    public:\n        Binomial(int N) : _N(N + 1), _M(mint::mod()), fac(_N), finv(_N),\
    \ inv(_N) {\n            fac[0] = fac[1] = 1;\n            finv[0] = finv[1] =\
    \ 1;\n            inv[1] = 1;\n            for (int i = 2; i < _N; ++i) {\n  \
    \              fac[i] = fac[i - 1] * i;\n                inv[i] = _M - inv[_M\
    \ % i] * (_M / i);\n                finv[i] = finv[i - 1] * inv[i];\n        \
    \    }\n        }\n\n        /**\n         * @brief Calculate nCk\n         *\
    \ \n         * @param n \n         * @param k \n         */\n        mint get(int\
    \ n, int k){\n            if (n < k) return 0;\n            if (n < 0 || k < 0)\
    \ return 0;\n            return fac[n] * finv[k] * finv[n - k];\n        }\n\n\
    \    protected:\n        const int _N;\n        const int _M;\n        std::vector<mint>\
    \ fac, finv, inv;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/binomial.hpp
  requiredBy: []
  timestamp: '2021-03-23 06:07:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1035.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: snow/math/binomial.hpp
layout: document
redirect_from:
- /library/snow/math/binomial.hpp
- /library/snow/math/binomial.hpp.html
title: "Binomial Coefficient - $\\binom{n}{k}$ \u524D\u51E6\u7406$O(n)$, $O(1)$"
---
