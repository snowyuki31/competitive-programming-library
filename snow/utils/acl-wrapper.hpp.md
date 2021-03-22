---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/oj/range_chmin_chmax_add_range_sum.cpp
    title: test/oj/range_chmin_chmax_add_range_sum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: Segment Tree (Point Set and Range Sum)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: Segment Tree (Range Min and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: Segment Tree (Range Add and Range Sum)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: Segment Tree (Range Add and Range Min)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: Segment Tree (Range Add and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/oj/range_affine_range_sum.test.cpp
    title: Segment Tree (Range Affine and Range Sum with Modint)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/utils/acl-wrapper.hpp\"\n\n#line 1 \"atcoder/segtree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 1\
    \ \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x\
    \ = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0) {}\n \
    \   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"atcoder/lazysegtree.hpp\"\n\n\n\n#line 6 \"atcoder/lazysegtree.hpp\"\
    \n#include <iostream>\n#line 8 \"atcoder/lazysegtree.hpp\"\n\n#line 10 \"atcoder/lazysegtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S,\n          S (*op)(S, S),\n    \
    \      S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n        \
    \  F (*composition)(F, F),\n          F (*id)()>\nstruct lazy_segtree {\n  public:\n\
    \    lazy_segtree() : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool\
    \ (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ g(x); });\n    }\n    template <class G> int max_right(int l, G g) {\n     \
    \   assert(0 <= l && l <= _n);\n        assert(g(e()));\n        if (l == _n)\
    \ return _n;\n        l += size;\n        for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n        S sm = e();\n        do {\n            while (l % 2 == 0) l\
    \ >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l = (2 * l);\n        \
    \            if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n}  // namespace atcoder\n\n\n#line 5 \"snow/utils/acl-wrapper.hpp\"\
    \n\nnamespace snow {\n\n    template < class Monoid >\n    using segtree = atcoder::segtree<typename\
    \ Monoid::value_type, Monoid::op, Monoid::e>;\n\n    template < class Monoid,\
    \ class Mapping >\n    using lazy_segtree = atcoder::lazy_segtree<typename Monoid::value_type,\
    \ Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition,\
    \ Mapping::id>;\n\n    // template <class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\n    // struct _segtree_beats\
    \ : atcoder::lazy_segtree<> {\n    //     void all_apply(int k, F f) {\n    //\
    \         d[k] = mapping(f, d[k]);\n    //         if (k < size){\n    //    \
    \         lz[k] = composition(f, lz[k]);\n    //             if (d[k].fail) push(k),\
    \ update(k);\n    //         }\n    //     }\n    // };\n\n    // template < class\
    \ Monoid, class Mapping >\n    // using segtree_beats = _segtree_beats<typename\
    \ Monoid::value_type, Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping,\
    \ Mapping::composition, Mapping::id>;\n\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include \"atcoder/segtree.hpp\"\n#include \"atcoder/lazysegtree.hpp\"\
    \n\nnamespace snow {\n\n    template < class Monoid >\n    using segtree = atcoder::segtree<typename\
    \ Monoid::value_type, Monoid::op, Monoid::e>;\n\n    template < class Monoid,\
    \ class Mapping >\n    using lazy_segtree = atcoder::lazy_segtree<typename Monoid::value_type,\
    \ Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition,\
    \ Mapping::id>;\n\n    // template <class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\n    // struct _segtree_beats\
    \ : atcoder::lazy_segtree<> {\n    //     void all_apply(int k, F f) {\n    //\
    \         d[k] = mapping(f, d[k]);\n    //         if (k < size){\n    //    \
    \         lz[k] = composition(f, lz[k]);\n    //             if (d[k].fail) push(k),\
    \ update(k);\n    //         }\n    //     }\n    // };\n\n    // template < class\
    \ Monoid, class Mapping >\n    // using segtree_beats = _segtree_beats<typename\
    \ Monoid::value_type, Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping,\
    \ Mapping::composition, Mapping::id>;\n\n\n} // namespace snow"
  dependsOn:
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - atcoder/lazysegtree.hpp
  isVerificationFile: false
  path: snow/utils/acl-wrapper.hpp
  requiredBy:
  - test/oj/range_chmin_chmax_add_range_sum.cpp
  timestamp: '2021-03-21 19:53:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: snow/utils/acl-wrapper.hpp
layout: document
redirect_from:
- /library/snow/utils/acl-wrapper.hpp
- /library/snow/utils/acl-wrapper.hpp.html
title: snow/utils/acl-wrapper.hpp
---
