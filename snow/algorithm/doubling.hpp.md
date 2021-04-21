---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2320.test.cpp
    title: Doubling
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Doubling
    links: []
  bundledCode: "#line 2 \"snow/algorithm/doubling.hpp\"\n#include <vector>\n\nnamespace\
    \ snow {\n\n/**\n * @brief Doubling\n */\ntemplate < typename T >\nstruct Doubling\
    \ {\n    public:\n        Doubling(std::vector<T>& f, long long lim) : N(f.size()),\
    \ LIM(64 - __builtin_clzll(lim)), table(LIM, std::vector<T>(N, -1)){\n       \
    \     // Built Doubling Table.\n            for (int i = 0; i < N; ++i) table[0][i]\
    \ = f[i];\n            for (int k = 1; k < LIM; ++k) {\n                for (int\
    \ i = 0; i < N; ++i) {\n                    if(table[k - 1][i] == -1) table[k][i]\
    \ = -1;\n                    else table[k][i] = table[k - 1][table[k - 1][i]];\n\
    \                }\n            }\n        }\n\n        /**\n         * @fn\n\
    \         * @brief Get position after t times of operations, starting from p.\n\
    \         */\n        T get(T p, long long t){\n            for(int k = LIM -\
    \ 1; k >= 0; --k) if((t >> k) & 1) p = table[k][p];\n            return p;\n \
    \       }\n\n        size_t size(){\n            return LIM;\n        }\n\n  \
    \  private:\n        const int N;\n        const int LIM;\n        std::vector<std::vector<T>>\
    \ table;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n\nnamespace snow {\n\n/**\n * @brief Doubling\n\
    \ */\ntemplate < typename T >\nstruct Doubling {\n    public:\n        Doubling(std::vector<T>&\
    \ f, long long lim) : N(f.size()), LIM(64 - __builtin_clzll(lim)), table(LIM,\
    \ std::vector<T>(N, -1)){\n            // Built Doubling Table.\n            for\
    \ (int i = 0; i < N; ++i) table[0][i] = f[i];\n            for (int k = 1; k <\
    \ LIM; ++k) {\n                for (int i = 0; i < N; ++i) {\n               \
    \     if(table[k - 1][i] == -1) table[k][i] = -1;\n                    else table[k][i]\
    \ = table[k - 1][table[k - 1][i]];\n                }\n            }\n       \
    \ }\n\n        /**\n         * @fn\n         * @brief Get position after t times\
    \ of operations, starting from p.\n         */\n        T get(T p, long long t){\n\
    \            for(int k = LIM - 1; k >= 0; --k) if((t >> k) & 1) p = table[k][p];\n\
    \            return p;\n        }\n\n        size_t size(){\n            return\
    \ LIM;\n        }\n\n    private:\n        const int N;\n        const int LIM;\n\
    \        std::vector<std::vector<T>> table;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/algorithm/doubling.hpp
  requiredBy: []
  timestamp: '2021-04-22 04:45:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2320.test.cpp
documentation_of: snow/algorithm/doubling.hpp
layout: document
redirect_from:
- /library/snow/algorithm/doubling.hpp
- /library/snow/algorithm/doubling.hpp.html
title: Doubling
---
