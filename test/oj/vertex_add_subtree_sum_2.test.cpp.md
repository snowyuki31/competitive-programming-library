---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/heavy-light-decomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  - icon: ':heavy_check_mark:'
    path: snow/monoids/plus.hpp
    title: snow/monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: snow/utils/seg-wrapper.hpp
    title: snow/utils/seg-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/vertex_add_subtree_sum
    document_title: Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
    links:
    - https://old.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/oj/vertex_add_subtree_sum_2.test.cpp\"\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/vertex_add_subtree_sum\"\n#include <iostream>\n\
    #include <vector>\n#line 4 \"snow/io/helper.hpp\"\n#include <set>\n\ntemplate<\
    \ typename T1, typename T2 >\nstd::ostream &operator << (std::ostream &os, const\
    \ std::pair< T1, T2 > &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\n\ntemplate< typename T1, typename T2 >\nstd::istream &operator >> (std::istream\
    \ &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b,\
    \ c] = t;\n    os << a << \" \" << b << \" \" << c;\n    return os;\n}\n\ntemplate<\
    \ typename T1, typename T2, typename T3 >\nstd::istream &operator >> (std::istream\
    \ &is, std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b, c] = t;\n    is >> a >>\
    \ b >> c;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::vector< T > &v){\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n \
    \   return os;\n}\n\ntemplate< typename T >\nstd::istream &operator >>  (std::istream\
    \ &is, std::vector< T > &v){\n    for(T &in : v) is >> in;\n    return is;\n}\n\
    \ntemplate< typename T >\nstd::ostream &operator << (std::ostream &os, const std::set<\
    \ T > &st){\n    int ct = 0;\n    for(auto& s : st) os << s << (++ct != st.size()\
    \ ? \" \" : \"\");\n    return os;\n}\n\ntemplate<class... T>\nvoid input(T&...\
    \ a){\n    (std::cin >> ... >> a);\n}\n\nvoid print() {\n    std::cout << '\\\
    n';\n}\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n\
    \    std::cout << a;\n    (std::cout << ... << (std::cout << ' ', b));\n    std::cout\
    \ << '\\n';\n}\n\nint drop() {\n    std::cout << '\\n';\n    exit(0);\n}\ntemplate<class\
    \ T, class... Ts>\nint drop(const T& a, const Ts&... b){\n    std::cout << a;\n\
    \    (std::cout << ... << (std::cout << ' ', b));\n    std::cout << '\\n';\n \
    \   exit(0);\n}\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\
    \n#include <limits>\r\n\r\nnamespace snow {\r\n\r\n/**\r\n * @brief Graph template\r\
    \n */\r\ntemplate < typename T >\r\nstruct Graph {\r\n    struct Edge {\r\n  \
    \      int from, to;\r\n        T weight;\r\n        Edge() : from(0), to(0),\
    \ weight(0) {}\r\n        Edge(int from, int to, T weight) : from(from), to(to),\
    \ weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const T INF = std::numeric_limits<T>::max();\r\n    std::vector<Edges> G;\r\
    \n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n    Edges&\
    \ operator[](int k) {\r\n        return G[k];\r\n    }\r\n    const Edges& operator[](int\
    \ k) const {\r\n        return G[k];\r\n    }\r\n\r\n    size_t size() const{\r\
    \n        return G.size();\r\n    }\r\n\r\n    void add_edge(int a, int b, T w\
    \ = 1){\r\n        G[a].emplace_back(a, b, w);\r\n        G[b].emplace_back(b,\
    \ a, w);\r\n    }\r\n\r\n    void add_directed_edge(int a, int b, T w = 1){\r\n\
    \        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n    void add_arrow(int a,\
    \ int b, T w = 1){\r\n        add_directed_edge(a, b, w);\r\n    }\r\n\r\n   \
    \ //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\n\r\n    //Bellman-Ford\r\
    \n    std::vector<T> bellman_ford(int s) const;\r\n\r\n    //Warshall-Floyd\r\n\
    \    std::vector<std::vector<T>> warshall_floyd() const;\r\n\r\n    //Topological\
    \ sort\r\n    std::vector<int> topological_sort() const;\r\n};\r\n\r\n} // namespace\
    \ snow\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#line 7 \"atcoder/segtree.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\
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
    \ Monoid::e>;\n\n} // namespace snow\n#line 2 \"snow/monoids/plus.hpp\"\n\nnamespace\
    \ snow {\n\n    template < typename T >\n    struct plus_monoid {\n        using\
    \ value_type = T;\n        static value_type e() { return T(); };\n        static\
    \ value_type op(value_type l, value_type r){ return l + r; };\n    };\n\n} //\
    \ namespace snow\n#line 2 \"snow/graph/tree/heavy-light-decomposition.hpp\"\n\n\
    #include <utility>\n#line 6 \"snow/graph/tree/heavy-light-decomposition.hpp\"\n\
    \nnamespace snow {\n\n/**\n * @brief Heavy Light Decomposition\n * \n * @tparam\
    \ T \n * @ref https://codeforces.com/blog/entry/53170\n */\ntemplate < typename\
    \ T = int >\nstruct HeavyLightDecomposition {\n    public:\n        HeavyLightDecomposition(snow::Graph<T>&\
    \ G, int root) : N(G.size()), sz(N), in(N), par(N), next(N) {\n            dfs_sz(G,\
    \ root);\n            next[root] = root;\n            dfs_hld(G, root);\n    \
    \    }\n\n        /**\n         * @brief Get vertex id\n         * @param v \n\
    \         */\n        int get_id(int v){\n            return in[v];\n        }\n\
    \n        /**\n         * @brief Get a segment of id corresponding to the subtree\
    \ of v\n         * @param v \n         */\n        std::pair<int, int> get_subtree(int\
    \ v){\n            return {in[v], in[v] + sz[v]};\n        }\n\n        /**\n\
    \         * @brief Get Lowest Common Ancestor of (u, v)\n         * \n       \
    \  * @param u \n         * @param v \n         */\n        int get_lca(int u,\
    \ int v){\n            while (true){\n                if(in[u] > in[v]) std::swap(u,\
    \ v);\n                if(next[u] == next[v]) return u;\n                v = par[next[v]];\n\
    \            }\n        }\n\n        /**\n         * @brief Get segments of id\
    \ corresponding to the path from u to v inclusive\n         * @param u\n     \
    \    * @param v\n         */\n        std::vector<std::pair<int, int>> get_path(int\
    \ u, int v) {\n            std::vector<std::pair<int, int>> path;\n          \
    \  while (true){\n                if(in[u] > in[v]) std::swap(u, v);\n       \
    \         path.emplace_back(std::max(in[next[v]], in[u]), in[v]);\n\n        \
    \        if(next[u] != next[v]) v = par[next[v]];\n                else break;\n\
    \            }\n            return path;\n        }\n\n    private:\n        int\
    \ N;\n        int _root;\n        std::vector<int> sz;\n        std::vector<int>\
    \ in;\n        std::vector<int> out;\n        std::vector<int> par;\n        std::vector<int>\
    \ next; // last vertex of heavy chain of x\n\n        void dfs_sz(snow::Graph<T>&\
    \ G, int v, int p = -1){\n            sz[v] = 1;\n            for(auto &e : G[v])\
    \ if(e.to != p) {\n                dfs_sz(G, e.to, v);\n                sz[v]\
    \ += sz[e.to];\n                if(sz[e.to] > sz[G[v][0].to]) std::swap(e, G[v][0]);\n\
    \            }\n        }\n\n        int order = 0;\n        void dfs_hld(snow::Graph<T>&\
    \ G, int v, int p = -1){\n            par[v] = p, in[v] = order++;\n         \
    \   for(auto e : G[v]) if(e.to != p) {\n                next[e.to] = ((e.to ==\
    \ G[v].front().to) ? next[v] : e.to);\n                dfs_hld(G, e.to, v);\n\
    \            }\n        }\n};\n\n} // namespace snow\n#line 9 \"test/oj/vertex_add_subtree_sum_2.test.cpp\"\
    \n\n/**\n * @brief Vertex Add Subtree Sum (Heavy Light Decomposition ver.)\n *\
    \ \n */\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    std::cin >> A;\n\n    snow::Graph<int> G(N);\n    for (int i = 1;\
    \ i <= N - 1; ++i){\n        int p;\n        std::cin >> p;\n        G.add_edge(p,\
    \ i);\n    }\n\n    snow::HeavyLightDecomposition<int> HLD(G, 0);\n    snow::segtree<snow::plus_monoid<long\
    \ long>> segtree(N);\n\n    for(int i = 0; i < N; ++i) segtree.set(HLD.get_id(i),\
    \ A[i]);\n\n    while(Q--){\n        int t, u;\n        std::cin >> t >> u;\n\n\
    \        if(t == 0){\n            int x;\n            std::cin >> x;\n       \
    \     segtree.set(HLD.get_id(u), segtree.get(HLD.get_id(u)) + x);\n        }\n\
    \        else{\n            auto [l, r] = HLD.get_subtree(u);\n            std::cout\
    \ << segtree.prod(l, r) << '\\n';\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #include <iostream>\n#include <vector>\n#include \"snow/io/helper.hpp\"\n#include\
    \ \"snow/graph/template.hpp\"\n#include \"snow/utils/seg-wrapper.hpp\"\n#include\
    \ \"snow/monoids/plus.hpp\"\n#include \"snow/graph/tree/heavy-light-decomposition.hpp\"\
    \n\n/**\n * @brief Vertex Add Subtree Sum (Heavy Light Decomposition ver.)\n *\
    \ \n */\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    std::cin >> A;\n\n    snow::Graph<int> G(N);\n    for (int i = 1;\
    \ i <= N - 1; ++i){\n        int p;\n        std::cin >> p;\n        G.add_edge(p,\
    \ i);\n    }\n\n    snow::HeavyLightDecomposition<int> HLD(G, 0);\n    snow::segtree<snow::plus_monoid<long\
    \ long>> segtree(N);\n\n    for(int i = 0; i < N; ++i) segtree.set(HLD.get_id(i),\
    \ A[i]);\n\n    while(Q--){\n        int t, u;\n        std::cin >> t >> u;\n\n\
    \        if(t == 0){\n            int x;\n            std::cin >> x;\n       \
    \     segtree.set(HLD.get_id(u), segtree.get(HLD.get_id(u)) + x);\n        }\n\
    \        else{\n            auto [l, r] = HLD.get_subtree(u);\n            std::cout\
    \ << segtree.prod(l, r) << '\\n';\n        }\n    }\n\n}"
  dependsOn:
  - snow/io/helper.hpp
  - snow/graph/template.hpp
  - snow/utils/seg-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - snow/monoids/plus.hpp
  - snow/graph/tree/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: test/oj/vertex_add_subtree_sum_2.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 14:58:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/oj/vertex_add_subtree_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/oj/vertex_add_subtree_sum_2.test.cpp
- /verify/test/oj/vertex_add_subtree_sum_2.test.cpp.html
title: Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
---
