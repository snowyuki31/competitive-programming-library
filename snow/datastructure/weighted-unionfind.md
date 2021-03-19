---
title: Weighted UnionFind
documentation_of: snow/datastructure/weighted-unionfind.hpp
---

# About

[atcoder/dsu](https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)のポテンシャル付きversionです．

# How to use

```bool d.merge(int a, int b)``` : 代表元ではなく，マージしたかどうかを返します．

```Abel d.weight(int a)```

```Abel d.diff(int a, int b)```

その他は`atcoder/dsu`に準拠します．