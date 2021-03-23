---
title: Euler Tour (Point Set and Path Sum Query)
documentation_of: snow/graph/tree/euler-tour-path.hpp
---

## About

Euler Tour + Segment Treeでパスクエリを処理します．

現時点では，Sum Queryのみ対応しています．

Abel群であれば処理できるはずで，以下の部分を適宜書き換えます．

```cpp
void set(int u, S x) {
    segtree.set(this->get_in(u), x);
    segtree.set(this->get_out(u), -x); // You need apply inverse value here
}
```