---
title: Binomial Coefficient - $\binom{n}{k} \bmod{p}$ 前処理$O(n)$, $O(1)$
documentation_of: snow/math/binomial.hpp
---

## About

二項係数を求めるクラスです．

ACLのmodintをテンプレートとして利用しています（atcoder::modint::mod()を利用しています）．

素数$p$よりも$n$が大きい場合は，Lucasの定理に従って分解してあげることで求めています．

## Note

Lucasの定理パートのverify : https://atcoder.jp/contests/arc117/tasks/arc117_c