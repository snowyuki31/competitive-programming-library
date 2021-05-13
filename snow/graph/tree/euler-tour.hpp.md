---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-lca.hpp
    title: "Euler Tour (Lowest Common Ancestor Query)- \u524D\u51E6\u7406$O(N\\log\
      \ N)$, $O(\\log N)$"
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-subtree.hpp
    title: Euler Tour (Point Set and Subtree Query)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/oj/lowest_common_ancestor_1.test.cpp
    title: Lowest Common Ancestor (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_path_sum.test.cpp
    title: Vertex Add Path Sum (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_subtree_sum.test.cpp
    title: Vertex Add Subtree Sum (Euler Tour ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Euler Tour
    links: []
  bundledCode: "#line 2 \"snow/graph/tree/euler-tour.hpp\"\n#include <vector>\n#line\
    \ 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\n#include\
    \ <limits>\r\n\r\nnamespace snow {\r\n\r\n/**\r\n * @brief Graph template\r\n\
    \ */\r\ntemplate < typename T >\r\nstruct Graph {\r\n    struct Edge {\r\n   \
    \     int to;\r\n        T weight;\r\n        Edge() : to(0), weight(0) {}\r\n\
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
    \n};\r\n\r\n} // namespace snow\n#line 4 \"snow/graph/tree/euler-tour.hpp\"\n\n\
    namespace snow {\n\n/**\n * @brief Euler Tour\n * @tparam T edge weight type\n\
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
    \ snow\n"
  code: "#pragma once\n#include <vector>\n#include \"snow/graph/template.hpp\"\n\n\
    namespace snow {\n\n/**\n * @brief Euler Tour\n * @tparam T edge weight type\n\
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
    \ snow"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/tree/euler-tour.hpp
  requiredBy:
  - snow/graph/tree/euler-tour-lca.hpp
  - snow/graph/tree/euler-tour-path.hpp
  - snow/graph/tree/euler-tour-subtree.hpp
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/vertex_add_subtree_sum.test.cpp
  - test/oj/lowest_common_ancestor_1.test.cpp
  - test/oj/vertex_add_path_sum.test.cpp
documentation_of: snow/graph/tree/euler-tour.hpp
layout: document
redirect_from:
- /library/snow/graph/tree/euler-tour.hpp
- /library/snow/graph/tree/euler-tour.hpp.html
title: Euler Tour
---
