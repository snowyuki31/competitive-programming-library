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
  - icon: ':heavy_check_mark:'
    path: snow/monoids/plus-size.hpp
    title: snow/monoids/plus-size.hpp
  - icon: ':heavy_check_mark:'
    path: snow/utils/acl-wrapper.hpp
    title: snow/utils/acl-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/aoj/DSL_2_I.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <iostream>\n#line 2 \"snow/utils/acl-wrapper.hpp\"\n\n#line 1 \"\
    atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param\
    \ n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n\
    \ & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned\
    \ long index;\n    _BitScanForward(&index, n);\n    return index;\n#else\n   \
    \ return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree()\
    \ : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n  \
    \      log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <= p &&\
    \ p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr =\
    \ e();\n        l += size;\n        r += size;\n\n        while (l < r) {\n  \
    \          if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n    template <class F> int max_right(int l, F\
    \ f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n  \
    \      if (l == _n) return _n;\n        l += size;\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/lazysegtree.hpp\"\
    \n\n\n\n#line 8 \"atcoder/lazysegtree.hpp\"\n\n#line 10 \"atcoder/lazysegtree.hpp\"\
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
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n}  // namespace atcoder\n\n\n#line 5 \"snow/utils/acl-wrapper.hpp\"\
    \n\nnamespace snow {\n\n    template < class Monoid >\n    using segtree = atcoder::segtree<typename\
    \ Monoid::value_type, Monoid::op, Monoid::e>;\n\n    template < class Monoid,\
    \ class Mapping >\n    using lazy_segtree = atcoder::lazy_segtree<typename Monoid::value_type,\
    \ Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition,\
    \ Mapping::id>;\n\n} // namespace snow\n#line 2 \"snow/monoids/plus-size.hpp\"\
    \n\nnamespace snow {\n\n    template < typename T >\n    struct plus_size_monoid\
    \ {\n        struct value_type {\n            T val;\n            int size;\n\
    \        };\n        static value_type e() { return value_type{0, 0}; };\n   \
    \     static value_type op(value_type l, value_type r) { return {l.val + r.val,\
    \ l.size + r.size}; };\n\n        struct add {\n            using f_type = T;\n\
    \            static value_type mapping(f_type f, value_type x) { return {f * x.size\
    \ + x.val, x.size}; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f + g; }\n            static f_type id(){ return T(); }\n      \
    \  };\n\n        struct update {\n            struct f_type{\n               \
    \ T val;\n                bool flag;\n            };\n            static value_type\
    \ mapping(f_type f, value_type x) { return {(f.flag ? f.val * x.size : x.val),\
    \ x.size}; }\n            static f_type composition(f_type f, f_type g) { return\
    \ f.flag ? f : g; }\n            static f_type id(){ return {T(), false}; }\n\
    \        };\n    };\n\n} // namespace snow\n#line 6 \"test/aoj/DSL_2_I.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    snow::lazy_segtree<snow::plus_size_monoid<int>,\
    \ snow::plus_size_monoid<int>::update> segtree(n);\n    for(int i = 0; i < n;\
    \ ++i) segtree.set(i, {0, 1});\n\n    while(q--) {\n        int t;\n        std::cin\
    \ >> t;\n\n        if(t == 0) {\n            int l, r, x;\n            std::cin\
    \ >> l >> r >> x;\n            segtree.apply(l, r + 1, {x, 1});\n        }\n \
    \       else {\n            int s, t;\n            std::cin >> s >> t;\n     \
    \       std::cout << segtree.prod(s, t + 1).val << '\\n';\n        }\n    }\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <iostream>\n#include \"snow/utils/acl-wrapper.hpp\"\n#include \"\
    snow/monoids/plus-size.hpp\"\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n\n    snow::lazy_segtree<snow::plus_size_monoid<int>, snow::plus_size_monoid<int>::update>\
    \ segtree(n);\n    for(int i = 0; i < n; ++i) segtree.set(i, {0, 1});\n\n    while(q--)\
    \ {\n        int t;\n        std::cin >> t;\n\n        if(t == 0) {\n        \
    \    int l, r, x;\n            std::cin >> l >> r >> x;\n            segtree.apply(l,\
    \ r + 1, {x, 1});\n        }\n        else {\n            int s, t;\n        \
    \    std::cin >> s >> t;\n            std::cout << segtree.prod(s, t + 1).val\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - snow/utils/acl-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - atcoder/lazysegtree.hpp
  - snow/monoids/plus-size.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:14:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.test.cpp
- /verify/test/aoj/DSL_2_I.test.cpp.html
title: test/aoj/DSL_2_I.test.cpp
---
