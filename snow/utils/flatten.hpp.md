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
    document_title: Flatten
    links: []
  bundledCode: "#line 2 \"snow/utils/flatten.hpp\"\n#include <vector>\n\nnamespace\
    \ snow {\n\n/**\n * @brief Flatten\n */\ntemplate < typename T >\nstruct Flatten\
    \ {\n    public:\n        Flatten(T a, T b, T c = 1, T d = 1, T e = 1){\n    \
    \        D = e;\n            C = D * d;\n            B = C * c;\n            A\
    \ = B * b;\n        }\n\n        T get(T a, T b, T c = 0, T d = 0, T e = 0){\n\
    \            T state = a * A;\n            state += b * B;\n            state\
    \ += c * C;\n            state += d * D;\n            return state + e;\n    \
    \    }\n\n        std::vector<T> restore(T val){\n            std::vector<T> ret;\n\
    \            std::vector<T> X{A, B, C, D, E};\n            for(auto x : X){\n\
    \                ret.emplace_back(val / x);\n                val %= x;\n     \
    \       }\n            return ret;\n        }\n\n    private:\n        T A, B,\
    \ C, D, E = 1;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n\nnamespace snow {\n\n/**\n * @brief Flatten\n\
    \ */\ntemplate < typename T >\nstruct Flatten {\n    public:\n        Flatten(T\
    \ a, T b, T c = 1, T d = 1, T e = 1){\n            D = e;\n            C = D *\
    \ d;\n            B = C * c;\n            A = B * b;\n        }\n\n        T get(T\
    \ a, T b, T c = 0, T d = 0, T e = 0){\n            T state = a * A;\n        \
    \    state += b * B;\n            state += c * C;\n            state += d * D;\n\
    \            return state + e;\n        }\n\n        std::vector<T> restore(T\
    \ val){\n            std::vector<T> ret;\n            std::vector<T> X{A, B, C,\
    \ D, E};\n            for(auto x : X){\n                ret.emplace_back(val /\
    \ x);\n                val %= x;\n            }\n            return ret;\n   \
    \     }\n\n    private:\n        T A, B, C, D, E = 1;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/utils/flatten.hpp
  requiredBy: []
  timestamp: '2021-04-22 04:45:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2320.test.cpp
documentation_of: snow/utils/flatten.hpp
layout: document
redirect_from:
- /library/snow/utils/flatten.hpp
- /library/snow/utils/flatten.hpp.html
title: Flatten
---
