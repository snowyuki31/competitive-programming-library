---
title: Lucas's theorem (Binomial Coefficient mod p) 
documentation_of: snow/math/lucas.hpp
---

## About

Lucasの定理に基づいて，$\binom{m}{n} \bmod{p}$を求めます．

ただし，$p$は素数です．

この実装では二項係数は愚直に求めているので，計算量は$O(p\log_p m)$です．

$p$が素数でなくても求める方法もあるようです．