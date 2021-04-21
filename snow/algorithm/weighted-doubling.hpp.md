---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1013.test.cpp
    title: Weighted Doubling
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Wegihted Doubling
    links: []
  bundledCode: "#line 2 \"snow/algorithm/weighted-doubling.hpp\"\n#include <vector>\n\
    #include <utility>\n\nnamespace snow {\n\n/**\n * @brief Wegihted Doubling\n */\n\
    template < typename Monoid >\nstruct WeightedDoubling {\n    using Data = std::pair<int,\
    \ Monoid>;\n\n    public:\n        WeightedDoubling(std::vector<Data>& f, long\
    \ long lim, const Monoid I = Monoid()) : N(f.size()), LIM(64 - __builtin_clzll(lim)),\
    \ table(LIM, std::vector<Data>(N, Data(-1, I))), I(I){\n            // Build Doubling\
    \ Table.\n            for (int i = 0; i < N; ++i) table[0][i] = f[i];\n      \
    \      for (int k = 1; k < LIM; ++k) {\n                for (int i = 0; i < N;\
    \ ++i) {\n                    int pre = table[k - 1][i].first;\n             \
    \       if(pre == -1) table[k][i].first = -1;\n                    else {\n  \
    \                      table[k][i].first = table[k - 1][pre].first;\n        \
    \                table[k][i].second = table[k - 1][i].second + table[k - 1][pre].second;\n\
    \                    }\n                }\n            }\n        }\n\n      \
    \  /**\n         * @fn\n         * @brief Get position after t times of operations,\
    \ starting from p.\n         */\n        Data get(int p, long long t){\n     \
    \       Monoid val = I;\n            for(int k = LIM - 1; k >= 0; --k) if((t >>\
    \ k) & 1) {\n                val = val + table[k][p].second;\n               \
    \ p = table[k][p].first;\n                if(p == -1) break;\n            }\n\
    \            return {p, val};\n        }\n\n        size_t size(){\n         \
    \   return LIM;\n        }\n\n    private:\n        const int N;\n        const\
    \ int LIM;\n        const Monoid I;\n        std::vector<std::vector<Data>> table;\n\
    };\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace snow {\n\
    \n/**\n * @brief Wegihted Doubling\n */\ntemplate < typename Monoid >\nstruct\
    \ WeightedDoubling {\n    using Data = std::pair<int, Monoid>;\n\n    public:\n\
    \        WeightedDoubling(std::vector<Data>& f, long long lim, const Monoid I\
    \ = Monoid()) : N(f.size()), LIM(64 - __builtin_clzll(lim)), table(LIM, std::vector<Data>(N,\
    \ Data(-1, I))), I(I){\n            // Build Doubling Table.\n            for\
    \ (int i = 0; i < N; ++i) table[0][i] = f[i];\n            for (int k = 1; k <\
    \ LIM; ++k) {\n                for (int i = 0; i < N; ++i) {\n               \
    \     int pre = table[k - 1][i].first;\n                    if(pre == -1) table[k][i].first\
    \ = -1;\n                    else {\n                        table[k][i].first\
    \ = table[k - 1][pre].first;\n                        table[k][i].second = table[k\
    \ - 1][i].second + table[k - 1][pre].second;\n                    }\n        \
    \        }\n            }\n        }\n\n        /**\n         * @fn\n        \
    \ * @brief Get position after t times of operations, starting from p.\n      \
    \   */\n        Data get(int p, long long t){\n            Monoid val = I;\n \
    \           for(int k = LIM - 1; k >= 0; --k) if((t >> k) & 1) {\n           \
    \     val = val + table[k][p].second;\n                p = table[k][p].first;\n\
    \                if(p == -1) break;\n            }\n            return {p, val};\n\
    \        }\n\n        size_t size(){\n            return LIM;\n        }\n\n \
    \   private:\n        const int N;\n        const int LIM;\n        const Monoid\
    \ I;\n        std::vector<std::vector<Data>> table;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/algorithm/weighted-doubling.hpp
  requiredBy: []
  timestamp: '2021-04-22 07:13:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1013.test.cpp
documentation_of: snow/algorithm/weighted-doubling.hpp
layout: document
redirect_from:
- /library/snow/algorithm/weighted-doubling.hpp
- /library/snow/algorithm/weighted-doubling.hpp.html
title: Wegihted Doubling
---
