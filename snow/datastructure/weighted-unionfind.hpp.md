---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/datastructure/weighted-unionfind.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace snow {\n\n//\
    \ Based on ac-library implementation\ntemplate < typename Abel = int >\nstruct\
    \ WeightedUnionFind {\n  public:\n    WeightedUnionFind() : _n(0) {}\n    explicit\
    \ WeightedUnionFind(int n, Abel e = 0) : _n(n), parent_or_size(n, -1), diff_weight(n,\
    \ e) {}\n\n    bool merge(int a, int b, Abel w) {\n        assert(0 <= a && a\
    \ < _n);\n        assert(0 <= b && b < _n);\n        w += weight(a), w -= weight(b);\n\
    \        int x = leader(a), y = leader(b);\n        if (x == y) return false;\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w *= -1;\n\
    \        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] =\
    \ x;\n        diff_weight[y] = w;\n        return true;\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        int r = leader(parent_or_size[a]);\n        diff_weight[a] += diff_weight[parent_or_size[a]];\n\
    \        return parent_or_size[a] = r;\n    }\n\n    int size(int a) {\n     \
    \   assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n  \
    \  }\n\n    Abel weight(int a){\n        leader(a);\n        return diff_weight[a];\n\
    \    }\n\n    Abel diff(int a, int b){\n        return weight(b) - weight(a);\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n    std::vector<Abel> diff_weight;\n\
    };\n\n}  // namespace snow\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace snow {\n\n// Based on ac-library implementation\ntemplate < typename\
    \ Abel = int >\nstruct WeightedUnionFind {\n  public:\n    WeightedUnionFind()\
    \ : _n(0) {}\n    explicit WeightedUnionFind(int n, Abel e = 0) : _n(n), parent_or_size(n,\
    \ -1), diff_weight(n, e) {}\n\n    bool merge(int a, int b, Abel w) {\n      \
    \  assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        w +=\
    \ weight(a), w -= weight(b);\n        int x = leader(a), y = leader(b);\n    \
    \    if (x == y) return false;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y), w *= -1;\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        diff_weight[y] = w;\n        return true;\n\
    \    }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n \
    \       assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n  \
    \  }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        int r = leader(parent_or_size[a]);\n\
    \        diff_weight[a] += diff_weight[parent_or_size[a]];\n        return parent_or_size[a]\
    \ = r;\n    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n  \
    \      return -parent_or_size[leader(a)];\n    }\n\n    Abel weight(int a){\n\
    \        leader(a);\n        return diff_weight[a];\n    }\n\n    Abel diff(int\
    \ a, int b){\n        return weight(b) - weight(a);\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n    std::vector<Abel> diff_weight;\n\
    };\n\n}  // namespace snow\n"
  dependsOn: []
  isVerificationFile: false
  path: snow/datastructure/weighted-unionfind.hpp
  requiredBy: []
  timestamp: '2021-03-20 06:10:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: snow/datastructure/weighted-unionfind.hpp
layout: document
title: Weighted UnionFind
---

# About

[atcoder/dsu](https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)のポテンシャル付きversionです．

# How to use

```bool d.merge(int a, int b)``` : 代表元ではなく，マージしたかどうかを返します．

```Abel d.weight(int a)```

```Abel d.diff(int a, int b)```

その他は`atcoder/dsu`に準拠します．