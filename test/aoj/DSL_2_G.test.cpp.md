---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':question:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':question:'
    path: snow/monoids/plus-size.hpp
    title: snow/monoids/plus-size.hpp
  - icon: ':question:'
    path: snow/utils/seg-wrapper.hpp
    title: snow/utils/seg-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: Segment Tree (Range Add and Range Sum)
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\
    \n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n\
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\n  public:\n    segtree() : segtree(0) {}\n    explicit segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    explicit segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n        r +=\
    \ size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int l) const\
    \ {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) const {\n        return min_left(r, [](S x) { return f(x); });\n\
    \    }\n    template <class F> int min_left(int r, F f) const {\n        assert(0\
    \ <= r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n\
    \        r += size;\n        S sm = e();\n        do {\n            r--;\n   \
    \         while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 3\
    \ \"snow/utils/seg-wrapper.hpp\"\n\nnamespace snow {\n\n    template < class Monoid\
    \ >\n    using segtree = atcoder::segtree<typename Monoid::value_type, Monoid::op,\
    \ Monoid::e>;\n\n} // namespace snow\n#line 2 \"snow/monoids/plus-size.hpp\"\n\
    \nnamespace snow {\n\n    template < typename T >\n    struct plus_size_monoid\
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
    \        };\n\n        struct affine {\n            using f_type = std::pair<T,\
    \ T>;\n            static value_type mapping(f_type f, value_type x) { return\
    \ {x.val * f.first + x.size * f.second, x.size}; }\n            static f_type\
    \ composition(f_type f, f_type g) { return {g.first * f.first, g.second * f.first\
    \ + f.second}; }\n            static f_type id(){ return {1, 0}; }\n        };\n\
    \    };\n\n} // namespace snow\n#line 6 \"test/aoj/DSL_2_G.test.cpp\"\n\n/**\n\
    \ * @brief Segment Tree (Range Add and Range Sum)\n * \n */\nint main() {\n  \
    \  int n, q;\n    std::cin >> n >> q;\n\n    snow::lazy_segtree<snow::plus_size_monoid<long>,\
    \ snow::plus_size_monoid<long>::add> segtree(n);\n    for(int i = 0; i < n; ++i)\
    \ segtree.set(i, {0, 1});\n\n    while(q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if(t == 0) {\n            int l, r, x;\n            std::cin\
    \ >> l >> r >> x;\n            --l, --r;\n            segtree.apply(l, r + 1,\
    \ x);\n        }\n        else {\n            int s, t;\n            std::cin\
    \ >> s >> t;\n            --s, --t;\n            std::cout << segtree.prod(s,\
    \ t + 1).val << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n#include \"snow/utils/seg-wrapper.hpp\"\n#include \"\
    snow/monoids/plus-size.hpp\"\n\n/**\n * @brief Segment Tree (Range Add and Range\
    \ Sum)\n * \n */\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n   \
    \ snow::lazy_segtree<snow::plus_size_monoid<long>, snow::plus_size_monoid<long>::add>\
    \ segtree(n);\n    for(int i = 0; i < n; ++i) segtree.set(i, {0, 1});\n\n    while(q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if(t == 0) {\n          \
    \  int l, r, x;\n            std::cin >> l >> r >> x;\n            --l, --r;\n\
    \            segtree.apply(l, r + 1, x);\n        }\n        else {\n        \
    \    int s, t;\n            std::cin >> s >> t;\n            --s, --t;\n     \
    \       std::cout << segtree.prod(s, t + 1).val << '\\n';\n        }\n    }\n\n\
    \    return 0;\n}\n"
  dependsOn:
  - snow/utils/seg-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - snow/monoids/plus-size.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2021-03-23 17:14:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.test.cpp
- /verify/test/aoj/DSL_2_G.test.cpp.html
title: Segment Tree (Range Add and Range Sum)
---
