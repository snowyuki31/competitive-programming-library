---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_E.test.cpp
    title: Twelvefold way V
  - icon: ':x:'
    path: test/yukicoder/1035.test.cpp
    title: Twelvefold way III
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Binomial Coefficient - $\\binom{n}{k}$ \u524D\u51E6\u7406$O(n)$,\
      \ $O(1)$"
    links: []
  bundledCode: "#line 2 \"snow/math/binomial.hpp\"\n\n#include <vector>\n\nnamespace\
    \ snow {\n\n/**\n * @brief Binomial Coefficient - $\\binom{n}{k}$ \u524D\u51E6\
    \u7406$O(n)$, $O(1)$\n * @param N max N\n * @tparam mint \n */\ntemplate < typename\
    \ mint >\nstruct Binomial {\n    public:\n        Binomial(int N) : _N(N + 1),\
    \ _M(mint::mod()), D(min(_N, _M)), fac(D), finv(D), inv(D) {\n            fac[0]\
    \ = fac[1] = 1;\n            finv[0] = finv[1] = 1;\n            inv[1] = 1;\n\
    \            for (int i = 2; i < D; ++i) {\n                fac[i] = fac[i - 1]\
    \ * i;\n                inv[i] = _M - inv[_M % i] * (_M / i);\n              \
    \  finv[i] = finv[i - 1] * inv[i];\n            }\n        }\n\n        /**\n\
    \         * @brief Calculate nCk\n         * \n         * @param n \n        \
    \ * @param k \n         */\n        mint get(int n, int k){\n            if (n\
    \ < k) return 0;\n            if (n < 0 || k < 0) return 0;\n            if (n\
    \ >= _M) return get(n % _M, k % _M) * get(n / _M, k / _M); // Lucas's theorem.\n\
    \            return fac[n] * finv[k] * finv[n - k];\n        }\n\n    protected:\n\
    \        const int _N;\n        const int _M;\n        const int D;\n        std::vector<mint>\
    \ fac, finv, inv;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace snow {\n\n/**\n * @brief Binomial\
    \ Coefficient - $\\binom{n}{k}$ \u524D\u51E6\u7406$O(n)$, $O(1)$\n * @param N\
    \ max N\n * @tparam mint \n */\ntemplate < typename mint >\nstruct Binomial {\n\
    \    public:\n        Binomial(int N) : _N(N + 1), _M(mint::mod()), D(min(_N,\
    \ _M)), fac(D), finv(D), inv(D) {\n            fac[0] = fac[1] = 1;\n        \
    \    finv[0] = finv[1] = 1;\n            inv[1] = 1;\n            for (int i =\
    \ 2; i < D; ++i) {\n                fac[i] = fac[i - 1] * i;\n               \
    \ inv[i] = _M - inv[_M % i] * (_M / i);\n                finv[i] = finv[i - 1]\
    \ * inv[i];\n            }\n        }\n\n        /**\n         * @brief Calculate\
    \ nCk\n         * \n         * @param n \n         * @param k \n         */\n\
    \        mint get(int n, int k){\n            if (n < k) return 0;\n         \
    \   if (n < 0 || k < 0) return 0;\n            if (n >= _M) return get(n % _M,\
    \ k % _M) * get(n / _M, k / _M); // Lucas's theorem.\n            return fac[n]\
    \ * finv[k] * finv[n - k];\n        }\n\n    protected:\n        const int _N;\n\
    \        const int _M;\n        const int D;\n        std::vector<mint> fac, finv,\
    \ inv;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/binomial.hpp
  requiredBy: []
  timestamp: '2021-04-19 04:04:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1035.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: snow/math/binomial.hpp
layout: document
title: "Binomial Coefficient - $\\binom{n}{k} \\bmod{p}$ \u524D\u51E6\u7406$O(n)$,\
  \ $O(1)$"
---

## About

二項係数を求めるクラスです．

ACLのmodintをテンプレートとして利用しています（atcoder::modint::mod()を利用しています）．

素数$p$よりも$n$が大きい場合は，Lucasの定理に従って分解してあげることで求めています．

## Note

Lucasの定理パートのverify : https://atcoder.jp/contests/arc117/tasks/arc117_c