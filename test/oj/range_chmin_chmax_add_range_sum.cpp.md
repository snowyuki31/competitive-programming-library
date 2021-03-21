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
  - icon: ':warning:'
    path: snow/monoids/beats.hpp
    title: snow/monoids/beats.hpp
  - icon: ':heavy_check_mark:'
    path: snow/utils/acl-wrapper.hpp
    title: snow/utils/acl-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://old.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/oj/range_chmin_chmax_add_range_sum.cpp\"\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\n\n#include\
    \ <iostream>\n#line 2 \"snow/utils/acl-wrapper.hpp\"\n\n#line 1 \"atcoder/segtree.hpp\"\
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
    \ atcoder\n\n\n#line 1 \"atcoder/lazysegtree.hpp\"\n\n\n\n#line 8 \"atcoder/lazysegtree.hpp\"\
    \n\n#line 10 \"atcoder/lazysegtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ S,\n          S (*op)(S, S),\n          S (*e)(),\n          class F,\n    \
    \      S (*mapping)(F, S),\n          F (*composition)(F, F),\n          F (*id)()>\n\
    struct lazy_segtree {\n  public:\n    lazy_segtree() : lazy_segtree(0) {}\n  \
    \  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n  \
    \  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    \
    \    log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(),\
    \ smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n}  // namespace atcoder\n\n\n#line 5 \"snow/utils/acl-wrapper.hpp\"\
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
    \ Mapping::composition, Mapping::id>;\n\n\n} // namespace snow\n#line 2 \"snow/monoids/beats.hpp\"\
    \n\nnamespace snow {\n\n    template <typename T> inline T second_lowest(T a,\
    \ T a2, T c, T c2) noexcept {\n        return a == c ? std::min(a2, c2) : a2 <=\
    \ c ? a2 : c2 <= a ? c2 : std::max(a, c);\n    }\n    template <typename T> inline\
    \ T second_highest(T a, T a2, T b, T b2) noexcept {\n        return a == b ? std::max(a2,\
    \ b2) : a2 >= b ? a2 : b2 >= a ? b2 : std::min(a, b);\n    }\n\n    template <\
    \ typename T >\n    struct beats {\n        T inf = std::numelic_limits<T>::max();\n\
    \        T minf = std::numelic_limits<T>::lowest();\n        \n        struct\
    \ value_type {\n            T lo, hi, lo2, hi2, sum;\n            unsigned sz,\
    \ nlo, nhi;\n            bool fail;\n            value_type() : lo(inf), hi(minf),\
    \ lo2(inf), hi2(minf), sum(0), sz(0), nlo(0), nhi(0), fail(0) {}\n           \
    \ value_type(T x, unsigned sz_ = 1)\n                : lo(x), hi(x), lo2(inf),\
    \ hi2(minf), sum(x * sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(0) {}\n        };\n\
    \n        static value_type e() { return value_type(); };\n        static value_type\
    \ op(value_type l, value_type r) {\n            static value_type ret;\n     \
    \       ret.lo = std::min(l.lo, r.lo), ret.hi = std::max(l.hi, r.hi);\n      \
    \      ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);\n            ret.hi2\
    \ = second_highest(l.hi, l.hi2, r.hi, r.hi2);\n            ret.sum = l.sum + r.sum,\
    \ ret.sz = l.sz + r.sz;\n            ret.nlo = l.nlo * (l.lo <= r.lo) + r.nlo\
    \ * (r.lo <= l.lo);\n            ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi\
    \ >= l.hi);\n            return ret;\n        }\n\n        struct mapping {\n\
    \            struct f_type {\n                T lb, ub, bias;\n              \
    \  f_type(T chmax_ = minf, T chmin_ = inf, T add = 0) : lb(chmax_), ub(chmin_),\
    \ bias(add) {}\n                static f_type chmin(T x) noexcept { return f_type(minf,\
    \ x, T(0)); }\n                static f_type chmax(T x) noexcept { return f_type(x,\
    \ inf, T(0)); }\n                static f_type add(T x) noexcept { return f_type(minf,\
    \ inf, x); };\n            };\n\n            static f_type composition(f_type\
    \ fnew, f_type fold) {\n                static f_type ret;\n                ret.lb\
    \ = std::max(std::min(fold.lb + fold.bias, fnew.ub), fnew.lb) - fold.bias;\n \
    \               ret.ub = std::min(std::max(fold.ub + fold.bias, fnew.lb), fnew.ub)\
    \ - fold.bias;\n                ret.bias = fold.bias + fnew.bias;\n          \
    \      return ret;\n            }\n\n            static f_type id() { return f_type();\
    \ }\n\n            value_type mapping(f_type f, value_type x) {\n            \
    \    if (x.sz == 0) return e();\n                else if (x.lo == x.hi or f.lb\
    \ == f.ub or f.lb >= x.hi or f.ub < x.lo) {\n                    return value_type(std::min(std::max(x.lo,\
    \ f.lb), f.ub) + f.bias, x.sz);\n                } else if (x.lo2 == x.hi) {\n\
    \                    x.lo = x.hi2 = std::max(x.lo, f.lb) + f.bias;\n         \
    \           x.hi = x.lo2 = std::min(x.hi, f.ub) + f.bias;\n                  \
    \  x.sum = x.lo * x.nlo + x.hi * x.nhi;\n                    return x;\n     \
    \           } else if (f.lb < x.lo2 and f.ub > x.hi2) {\n                    T\
    \ nxt_lo = std::max(x.lo, f.lb), nxt_hi = std::min(x.hi, f.ub);\n            \
    \        x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias *\
    \ x.sz;\n                    x.lo = nxt_lo + f.bias, x.hi = nxt_hi + f.bias, x.lo2\
    \ += f.bias, x.hi2 += f.bias;\n                    return x;\n               \
    \ }\n                x.fail = true;\n                return x;\n            }\n\
    \        };\n    };\n\n} // namespace snow\n#line 6 \"test/oj/range_chmin_chmax_add_range_sum.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\n    // snow::segtree_beats<snow::beats<long>,\
    \ snow::beats<long>::mapping> segtree(N);\n    \n\n}\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <iostream>\n#include \"snow/utils/acl-wrapper.hpp\"\n#include \"\
    snow/monoids/beats.hpp\"\n\nint main() {\n    int N, Q;\n    std::cin >> N >>\
    \ Q;\n\n    // snow::segtree_beats<snow::beats<long>, snow::beats<long>::mapping>\
    \ segtree(N);\n    \n\n}"
  dependsOn:
  - snow/utils/acl-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - atcoder/lazysegtree.hpp
  - snow/monoids/beats.hpp
  isVerificationFile: false
  path: test/oj/range_chmin_chmax_add_range_sum.cpp
  requiredBy: []
  timestamp: '2021-03-21 19:53:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/oj/range_chmin_chmax_add_range_sum.cpp
layout: document
redirect_from:
- /library/test/oj/range_chmin_chmax_add_range_sum.cpp
- /library/test/oj/range_chmin_chmax_add_range_sum.cpp.html
title: test/oj/range_chmin_chmax_add_range_sum.cpp
---
