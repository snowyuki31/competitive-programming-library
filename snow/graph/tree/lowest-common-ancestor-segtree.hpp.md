---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':question:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  - icon: ':heavy_check_mark:'
    path: snow/monoids/min.hpp
    title: snow/monoids/min.hpp
  - icon: ':heavy_check_mark:'
    path: snow/utils/pair-wrapper.hpp
    title: snow/utils/pair-wrapper.hpp
  - icon: ':question:'
    path: snow/utils/seg-wrapper.hpp
    title: snow/utils/seg-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/oj/lowest_common_ancestor_1.test.cpp
    title: Lowest Common Ancestor (Segment Tree ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lowest Common Ancestor (Segment Tree ver.) - \u524D\u51E6\u7406\
      $O(N\\log N)$, $O(\\logN)$"
    links: []
  bundledCode: "#line 2 \"snow/graph/tree/lowest-common-ancestor-segtree.hpp\"\n\n\
    #include <vector>\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#line 7 \"atcoder/segtree.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
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
    \ Monoid::e>;\n\n} // namespace snow\n#line 2 \"snow/monoids/min.hpp\"\n\n#line\
    \ 2 \"snow/utils/pair-wrapper.hpp\"\n\n#include <limits>\n#include <utility>\n\
    \nnamespace std {\n\ntemplate <typename T0, typename T1>\nclass numeric_limits<std::pair<T0,\
    \ T1>> {\npublic:\n    static constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(),\
    \ std::numeric_limits<T1>::min()}; }\n    static constexpr std::pair<T0, T1> max()\
    \ { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }\n\
    };\n\n}  // namespace std\n#line 4 \"snow/monoids/min.hpp\"\n\nnamespace snow\
    \ {\n\n    template < typename T >\n    struct min_monoid {\n        using value_type\
    \ = T;\n        static value_type e() { return std::numeric_limits<T>::max();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::min(l,\
    \ r); };\n\n        struct add {\n            using f_type = T;\n            static\
    \ value_type mapping(f_type f, value_type x) { return f + x; }\n            static\
    \ f_type composition(f_type f, f_type g) { return f + g; }\n            static\
    \ f_type id(){ return T(); }\n        };\n\n        struct update {\n        \
    \    struct f_type{\n                T val;\n                bool flag;\n    \
    \        };\n            static value_type mapping(f_type f, value_type x) { return\
    \ f.flag ? f.val : x; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f.flag ? f : g; }\n            static f_type id(){ return {T(),\
    \ false}; }\n        };\n    };\n\n} // namespace snow\n#line 2 \"snow/graph/template.hpp\"\
    \n\r\n#line 4 \"snow/graph/template.hpp\"\n\r\nnamespace snow {\r\n\r\n/**\r\n\
    \ * @brief Graph template\r\n */\r\ntemplate < typename T >\r\nstruct Graph {\r\
    \n    struct Edge {\r\n        int from, to;\r\n        T weight;\r\n        Edge()\
    \ : from(0), to(0), weight(0) {}\r\n        Edge(int from, int to, T weight) :\
    \ from(from), to(to), weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const T INF = std::numeric_limits<T>::max();\r\n    std::vector<Edges>\
    \ G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n\
    \    Edges operator[](int k) const{\r\n        return G[k];\r\n    }\r\n\r\n \
    \   size_t size() const{\r\n        return G.size();\r\n    }\r\n\r\n    void\
    \ add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n\
    \        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\
    \n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\
    \n    //Warshall-Floyd\r\n    std::vector<std::vector<T>> warshall_floyd() const;\r\
    \n\r\n    //Topological sort\r\n    std::vector<int> topological_sort() const;\r\
    \n};\r\n\r\n} // namespace snow\n#line 7 \"snow/graph/tree/lowest-common-ancestor-segtree.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Lowest Common Ancestor (Segment Tree ver.)\
    \ - \u524D\u51E6\u7406$O(N\\log N)$, $O(\\logN)$\n * \n */\ntemplate < typename\
    \ T = int >\nstruct LowestCommonAncestorBySeg {\n    public:\n        LowestCommonAncestorBySeg(snow::Graph<T>\
    \ const& G, int root) : N(G.size()), depth(2 * N, 0), vs(2 * N, 0), id(N, 0),\
    \ segtree(2 * N) {\n            euler_tour(G, root, -1, 0);\n            for(int\
    \ i = 0; i < 2 * N; ++i) segtree.set(i, {depth[i], vs[i]});\n        }\n\n   \
    \     int get(int u, int v) {\n            int u_ = id[u], v_ = id[v];\n     \
    \       auto ret = segtree.prod(std::min(u_, v_), std::max(u_, v_) + 1);\n   \
    \         return ret.second;\n        }\n\n    private:\n        int N;\n    \
    \    std::vector<int> depth; // order->depth\n        std::vector<int> vs;   \
    \ // order->vertex number\n        std::vector<int> id;    // vertex number->order\n\
    \        snow::segtree<snow::min_monoid<std::pair<int, int>>> segtree;\n\n   \
    \     int order = 0;\n        void euler_tour(snow::Graph<T> const& G, int v,\
    \ int p, int d){\n            id[v] = order;\n            vs[order] = v;\n   \
    \         depth[order++] = d;\n            for(auto &e : G[v]) if(e.to != p){\n\
    \                euler_tour(G, e.to, v, d + 1);\n                vs[order] = v;\n\
    \                depth[order++] = d;\n            }\n        }\n};\n\n} // namespace\
    \ snow\n"
  code: "#pragma once\n\n#include <vector>\n#include \"snow/utils/seg-wrapper.hpp\"\
    \n#include \"snow/monoids/min.hpp\"\n#include \"snow/graph/template.hpp\"\n\n\
    namespace snow {\n\n/**\n * @brief Lowest Common Ancestor (Segment Tree ver.)\
    \ - \u524D\u51E6\u7406$O(N\\log N)$, $O(\\logN)$\n * \n */\ntemplate < typename\
    \ T = int >\nstruct LowestCommonAncestorBySeg {\n    public:\n        LowestCommonAncestorBySeg(snow::Graph<T>\
    \ const& G, int root) : N(G.size()), depth(2 * N, 0), vs(2 * N, 0), id(N, 0),\
    \ segtree(2 * N) {\n            euler_tour(G, root, -1, 0);\n            for(int\
    \ i = 0; i < 2 * N; ++i) segtree.set(i, {depth[i], vs[i]});\n        }\n\n   \
    \     int get(int u, int v) {\n            int u_ = id[u], v_ = id[v];\n     \
    \       auto ret = segtree.prod(std::min(u_, v_), std::max(u_, v_) + 1);\n   \
    \         return ret.second;\n        }\n\n    private:\n        int N;\n    \
    \    std::vector<int> depth; // order->depth\n        std::vector<int> vs;   \
    \ // order->vertex number\n        std::vector<int> id;    // vertex number->order\n\
    \        snow::segtree<snow::min_monoid<std::pair<int, int>>> segtree;\n\n   \
    \     int order = 0;\n        void euler_tour(snow::Graph<T> const& G, int v,\
    \ int p, int d){\n            id[v] = order;\n            vs[order] = v;\n   \
    \         depth[order++] = d;\n            for(auto &e : G[v]) if(e.to != p){\n\
    \                euler_tour(G, e.to, v, d + 1);\n                vs[order] = v;\n\
    \                depth[order++] = d;\n            }\n        }\n};\n\n} // namespace\
    \ snow"
  dependsOn:
  - snow/utils/seg-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - snow/monoids/min.hpp
  - snow/utils/pair-wrapper.hpp
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/tree/lowest-common-ancestor-segtree.hpp
  requiredBy: []
  timestamp: '2021-03-23 17:14:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/lowest_common_ancestor_1.test.cpp
documentation_of: snow/graph/tree/lowest-common-ancestor-segtree.hpp
layout: document
redirect_from:
- /library/snow/graph/tree/lowest-common-ancestor-segtree.hpp
- /library/snow/graph/tree/lowest-common-ancestor-segtree.hpp.html
title: "Lowest Common Ancestor (Segment Tree ver.) - \u524D\u51E6\u7406$O(N\\log N)$,\
  \ $O(\\logN)$"
---
