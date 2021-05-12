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
    path: snow/graph/template.hpp
    title: Graph template
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-lca.hpp
    title: "Euler Tour (Lowest Common Ancestor Query)- \u524D\u51E6\u7406$O(N\\log\
      \ N)$, $O(\\log N)$"
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour.hpp
    title: Euler Tour
  - icon: ':question:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  - icon: ':heavy_check_mark:'
    path: snow/monoids/min.hpp
    title: snow/monoids/min.hpp
  - icon: ':question:'
    path: snow/monoids/plus.hpp
    title: snow/monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: snow/utils/pair-wrapper.hpp
    title: snow/utils/pair-wrapper.hpp
  - icon: ':question:'
    path: snow/utils/seg-wrapper.hpp
    title: snow/utils/seg-wrapper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/vertex_add_path_sum
    document_title: Vertex Add Path Sum (Euler Tour ver.)
    links:
    - https://old.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/oj/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/vertex_add_path_sum\"\n#include <iostream>\n\
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
    \ T > &st){\n    int ct = 0;\n    for(auto& s : st) os << s << (++ct != (int)st.size()\
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
    \      int to;\r\n        T weight;\r\n        Edge() : to(0), weight(0) {}\r\n\
    \        Edge(int to, T weight) : to(to), weight(weight) {}\r\n    };\r\n    using\
    \ Edges = std::vector<Edge>;\r\n\r\n    const T INF = std::numeric_limits<T>::max();\r\
    \n    std::vector<Edges> G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int\
    \ n) : G(n) {}\r\n\r\n    Edges& operator[](int k) {\r\n        return G[k];\r\
    \n    }\r\n    const Edges& operator[](int k) const {\r\n        return G[k];\r\
    \n    }\r\n\r\n    size_t size() const{\r\n        return G.size();\r\n    }\r\
    \n\r\n    void add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(b,\
    \ w);\r\n        G[b].emplace_back(a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(b, w);\r\n    }\r\n\r\n   \
    \ void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b, w);\r\
    \n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\n\
    \r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\n\
    \    //Warshall-Floyd\r\n    std::vector<std::vector<T>> warshall_floyd() const;\r\
    \n\r\n    //Topological sort\r\n    std::vector<int> topological_sort() const;\r\
    \n};\r\n\r\n} // namespace snow\n#line 2 \"snow/monoids/plus.hpp\"\n\nnamespace\
    \ snow {\n\n    template < typename T >\n    struct plus_monoid {\n        using\
    \ value_type = T;\n        static value_type e() { return T(); };\n        static\
    \ value_type op(value_type l, value_type r){ return l + r; };\n    };\n\n} //\
    \ namespace snow\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n\
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
    \ 2 \"snow/utils/pair-wrapper.hpp\"\n\n#line 4 \"snow/utils/pair-wrapper.hpp\"\
    \n#include <utility>\n\nnamespace std {\n\ntemplate <typename T0, typename T1>\n\
    class numeric_limits<std::pair<T0, T1>> {\npublic:\n    static constexpr std::pair<T0,\
    \ T1> min() { return {std::numeric_limits<T0>::min(), std::numeric_limits<T1>::min()};\
    \ }\n    static constexpr std::pair<T0, T1> max() { return {std::numeric_limits<T0>::max(),\
    \ std::numeric_limits<T1>::max()}; }\n};\n\n}  // namespace std\n#line 4 \"snow/monoids/min.hpp\"\
    \n\nnamespace snow {\n\n    template < typename T >\n    struct min_monoid {\n\
    \        using value_type = T;\n        static value_type e() { return std::numeric_limits<T>::max();\
    \ };\n        static value_type op(value_type l, value_type r){ return std::min(l,\
    \ r); };\n\n        struct add {\n            using f_type = T;\n            static\
    \ value_type mapping(f_type f, value_type x) { return f + x; }\n            static\
    \ f_type composition(f_type f, f_type g) { return f + g; }\n            static\
    \ f_type id(){ return T(); }\n        };\n\n        struct update {\n        \
    \    struct f_type{\n                T val;\n                bool flag;\n    \
    \        };\n            static value_type mapping(f_type f, value_type x) { return\
    \ f.flag ? f.val : x; }\n            static f_type composition(f_type f, f_type\
    \ g) { return f.flag ? f : g; }\n            static f_type id(){ return {T(),\
    \ false}; }\n        };\n    };\n\n} // namespace snow\n#line 4 \"snow/graph/tree/euler-tour.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Euler Tour\n * @tparam T edge weight type\n\
    \ */\ntemplate < typename T = int >\nstruct EulerTour {\n    public:\n       \
    \ EulerTour(snow::Graph<T> const& G, int root) : N(G.size()), vs(2 * N, 0), in(N,\
    \ 0), out(N, 0), depth(2 * N, 0) {\n            dfs(G, root, -1, 0);\n       \
    \ }\n\n        int get_in(int x){\n            return in[x];\n        }\n\n  \
    \      int get_out(int x){\n            return out[x];\n        }\n\n        int\
    \ get_vertex(int x){\n            return vs[x];\n        }\n\n        int get_depth(int\
    \ x){\n            return depth[x];\n        }\n\n    private:\n        int N;\n\
    \        std::vector<int> vs;    // order->vertex number\n        std::vector<int>\
    \ in;    // vertex number->order(in)\n        std::vector<int> out;   // vertex\
    \ number->order(out)\n        std::vector<int> depth; // depth\n\n        int\
    \ order = 0;\n        void dfs(snow::Graph<int> const& G, int v, int p, int d)\
    \ {\n            vs[order] = v;\n            depth[order] = d;\n            in[v]\
    \ = order++;\n            for(auto &e : G[v]) if(e.to != p) {\n              \
    \  dfs(G, e.to, v, d + 1);\n                vs[order] = v;\n                depth[order++]\
    \ = d;\n            }\n            out[v] = order;\n        }\n};\n\n} // namespace\
    \ snow\n#line 7 \"snow/graph/tree/euler-tour-lca.hpp\"\n\nnamespace snow {\n\n\
    /**\n * @brief Euler Tour (Lowest Common Ancestor Query)- \u524D\u51E6\u7406$O(N\\\
    log N)$, $O(\\log N)$\n * \n */\ntemplate < typename T = int >\nstruct EulerTourLCA\
    \ : public EulerTour<T> {\n    public:\n        EulerTourLCA(snow::Graph<T> const&\
    \ G, int root) : EulerTour<T>(G, root), N(G.size()), segtree(2 * N) {\n      \
    \      for(int i = 0; i < 2 * N; ++i) segtree.set(i, {this->get_depth(i), this->get_vertex(i)});\n\
    \        }\n\n        int lca(int u, int v) {\n            int u_ = this->get_in(u),\
    \ v_ = this->get_in(v);\n            auto ret = segtree.prod(std::min(u_, v_),\
    \ std::max(u_, v_) + 1);\n            return ret.second;\n        }\n\n    private:\n\
    \        int N;\n        snow::segtree<snow::min_monoid<std::pair<int, int>>>\
    \ segtree;\n};\n\n} // namespace snow\n#line 7 \"snow/graph/tree/euler-tour-path.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Euler Tour (Point Set and Path Sum Query)\n\
    \ * @note Available if inverse element exists (i.e., Abel)\n * @tparam T edge\
    \ weight type\n */\ntemplate < typename S, typename T = int >\nstruct EulerTourPath\
    \ : public EulerTourLCA<T> {\n    public:\n        EulerTourPath(snow::Graph<T>\
    \ const &G, int root) : EulerTourLCA<T>(G, root), N(G.size()), _root(root), segtree(2\
    \ * N) {}\n\n        void set(int u, S x) {\n            segtree.set(this->get_in(u),\
    \ x);\n            segtree.set(this->get_out(u), -x); // You need apply inverse\
    \ value here\n        }\n\n        S get(int u) {\n            return segtree.get(this->get_in(u));\n\
    \        }\n\n        // Path Query (from u to v, inclusive)\n        S prod(int\
    \ u, int v) {\n            int lca = this->lca(u, v);\n            return _prod(u)\
    \ + _prod(v) - 2 * _prod(lca) + segtree.get(this->get_in(lca));\n        }\n\n\
    \    private:\n        int N;\n        int _root;\n        snow::segtree<snow::plus_monoid<S>>\
    \ segtree;\n\n        S _prod(int u){\n            int l = this->get_in(_root),\
    \ r = this->get_out(u);\n            return segtree.prod(l, r);\n        }\n};\n\
    \n} // namespace snow\n#line 8 \"test/oj/vertex_add_path_sum.test.cpp\"\n\n/**\n\
    \ * @brief Vertex Add Path Sum (Euler Tour ver.)\n * \n */\nint main() {\n   \
    \ int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    std::cin\
    \ >> A;\n\n    snow::Graph<int> G(N);\n    for (int i = 0; i < N - 1; ++i){\n\
    \        int u, v;\n        std::cin >> u >> v;\n        G.add_edge(u, v);\n \
    \   }\n\n    snow::EulerTourPath<long long> euler(G, 0);\n    for(int i = 0; i\
    \ < N; ++i) euler.set(i, A[i]);\n\n    while(Q--){\n        int t, u;\n      \
    \  std::cin >> t >> u;\n\n        if(t == 0){\n            int x;\n          \
    \  std::cin >> x;\n            euler.set(u, euler.get(u) + x);\n        }\n  \
    \      else {\n            int v;\n            std::cin >> v;\n            std::cout\
    \ << euler.prod(u, v) << '\\n';\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/vertex_add_path_sum\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"snow/io/helper.hpp\"\n#include \"\
    snow/graph/template.hpp\"\n#include \"snow/monoids/plus.hpp\"\n#include \"snow/graph/tree/euler-tour-path.hpp\"\
    \n\n/**\n * @brief Vertex Add Path Sum (Euler Tour ver.)\n * \n */\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    std::cin\
    \ >> A;\n\n    snow::Graph<int> G(N);\n    for (int i = 0; i < N - 1; ++i){\n\
    \        int u, v;\n        std::cin >> u >> v;\n        G.add_edge(u, v);\n \
    \   }\n\n    snow::EulerTourPath<long long> euler(G, 0);\n    for(int i = 0; i\
    \ < N; ++i) euler.set(i, A[i]);\n\n    while(Q--){\n        int t, u;\n      \
    \  std::cin >> t >> u;\n\n        if(t == 0){\n            int x;\n          \
    \  std::cin >> x;\n            euler.set(u, euler.get(u) + x);\n        }\n  \
    \      else {\n            int v;\n            std::cin >> v;\n            std::cout\
    \ << euler.prod(u, v) << '\\n';\n        }\n    }\n\n}"
  dependsOn:
  - snow/io/helper.hpp
  - snow/graph/template.hpp
  - snow/monoids/plus.hpp
  - snow/graph/tree/euler-tour-path.hpp
  - snow/graph/tree/euler-tour-lca.hpp
  - snow/utils/seg-wrapper.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  - snow/monoids/min.hpp
  - snow/utils/pair-wrapper.hpp
  - snow/graph/tree/euler-tour.hpp
  isVerificationFile: true
  path: test/oj/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-04-21 03:38:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/oj/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/oj/vertex_add_path_sum.test.cpp
- /verify/test/oj/vertex_add_path_sum.test.cpp.html
title: Vertex Add Path Sum (Euler Tour ver.)
---
