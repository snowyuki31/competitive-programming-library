---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: Cumurative Sum (2D)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cumulative Sum (2D)
    links: []
  bundledCode: "#line 2 \"snow/algorithm/cumsum2D.hpp\"\n\n#include <vector>\n\nnamespace\
    \ snow {\n\n/**\n * @brief Cumulative Sum (2D)\n */\ntemplate < typename T >\n\
    struct cumsum2D {\n    public:\n        cumsum2D(std::vector<std::vector<T>> const&\
    \ data) : H(data.size()), W(data.front().size()), _data(H + 1, std::vector<T>(W\
    \ + 1)) {\n            for (int i = 1; i <= H; ++i) {\n                for(int\
    \ j = 1; j <= W; ++j) {\n                    _data[i][j] = data[i - 1][j - 1]\
    \ + _data[i - 1][j];\n                }\n            }\n            for (int i\
    \ = 0; i <= H; ++i) {\n                for(int j = 0; j <= W; ++j) {\n       \
    \             if(j >= 1) _data[i][j] += _data[i][j - 1];\n                }\n\
    \            }\n        }\n\n        /**\n         * @brief get cumsum [sx, gx),\
    \ [sy, gy)\n         */\n        T get(int sx, int sy, int gx, int gy) const {\n\
    \            return _data[gx][gy] - _data[sx][gy] - _data[gx][sy] + _data[sx][sy];\n\
    \        }\n\n    private:\n        int H, W;\n        std::vector<std::vector<T>>\
    \ _data;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace snow {\n\n/**\n * @brief Cumulative\
    \ Sum (2D)\n */\ntemplate < typename T >\nstruct cumsum2D {\n    public:\n   \
    \     cumsum2D(std::vector<std::vector<T>> const& data) : H(data.size()), W(data.front().size()),\
    \ _data(H + 1, std::vector<T>(W + 1)) {\n            for (int i = 1; i <= H; ++i)\
    \ {\n                for(int j = 1; j <= W; ++j) {\n                    _data[i][j]\
    \ = data[i - 1][j - 1] + _data[i - 1][j];\n                }\n            }\n\
    \            for (int i = 0; i <= H; ++i) {\n                for(int j = 0; j\
    \ <= W; ++j) {\n                    if(j >= 1) _data[i][j] += _data[i][j - 1];\n\
    \                }\n            }\n        }\n\n        /**\n         * @brief\
    \ get cumsum [sx, gx), [sy, gy)\n         */\n        T get(int sx, int sy, int\
    \ gx, int gy) const {\n            return _data[gx][gy] - _data[sx][gy] - _data[gx][sy]\
    \ + _data[sx][sy];\n        }\n\n    private:\n        int H, W;\n        std::vector<std::vector<T>>\
    \ _data;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/algorithm/cumsum2D.hpp
  requiredBy: []
  timestamp: '2021-03-23 05:30:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0560.test.cpp
documentation_of: snow/algorithm/cumsum2D.hpp
layout: document
redirect_from:
- /library/snow/algorithm/cumsum2D.hpp
- /library/snow/algorithm/cumsum2D.hpp.html
title: Cumulative Sum (2D)
---
