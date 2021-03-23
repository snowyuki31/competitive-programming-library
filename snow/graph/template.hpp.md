---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/bellman-ford.hpp
    title: Bellman-Ford
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/warshall-floyd.hpp
    title: Warshall-Floyd
  - icon: ':heavy_check_mark:'
    path: snow/graph/topological-sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour.hpp
    title: Euler Tour (Point Set and Subtree Query)
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/lowest-common-ancestor-segtree.hpp
    title: "Lowest Common Ancestor (Segment Tree ver.) - \u524D\u51E6\u7406$O(N\\\
      log N)$, $O(\\logN)$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: Dikstra
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: Bellman-Ford
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: Warshall-Floyd (with Negative Cycle Detection)
  - icon: ':heavy_check_mark:'
    path: test/oj/lowest_common_ancestor_1.test.cpp
    title: Lowest Common Ancestor (Segment Tree ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_subtree_sum.test.cpp
    title: Vertex Add Subtree Sum (With Euler-Tour)
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0517.test.cpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1065.test.cpp
    title: Dijkstra (decimal floating point ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Graph template
    links: []
  bundledCode: "#line 2 \"snow/graph/template.hpp\"\n\r\n#include <vector>\r\n\r\n\
    namespace snow {\r\n\r\n/**\r\n * @brief Graph template\r\n */\r\ntemplate < typename\
    \ T >\r\nstruct Graph {\r\n    struct Edge {\r\n        int from, to;\r\n    \
    \    T weight;\r\n        Edge() : from(0), to(0), weight(0) {}\r\n        Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\r\n    };\r\n\
    \    using Edges = std::vector<Edge>;\r\n\r\n    const T INF = std::numeric_limits<T>::max();\r\
    \n    std::vector<Edges> G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int\
    \ n) : G(n) {}\r\n\r\n    Edges operator[](int k) const{\r\n        return G[k];\r\
    \n    }\r\n\r\n    size_t size() const{\r\n        return G.size();\r\n    }\r\
    \n\r\n    void add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a,\
    \ b, w);\r\n        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\
    \n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\
    \n    //Warshall-Floyd\r\n    std::vector<std::vector<T>> warshall_floyd() const;\r\
    \n\r\n    //Topological sort\r\n    std::vector<int> topological_sort() const;\r\
    \n};\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace snow {\r\n\r\n/**\r\
    \n * @brief Graph template\r\n */\r\ntemplate < typename T >\r\nstruct Graph {\r\
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
    \n};\r\n\r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/graph/template.hpp
  requiredBy:
  - snow/graph/topological-sort.hpp
  - snow/graph/tree/lowest-common-ancestor-segtree.hpp
  - snow/graph/tree/euler-tour.hpp
  - snow/graph/shortest-path/bellman-ford.hpp
  - snow/graph/shortest-path/warshall-floyd.hpp
  - snow/graph/shortest-path/dijkstra.hpp
  timestamp: '2021-03-22 12:08:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0517.test.cpp
  - test/yukicoder/1065.test.cpp
  - test/oj/vertex_add_subtree_sum.test.cpp
  - test/oj/lowest_common_ancestor_1.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: snow/graph/template.hpp
layout: document
redirect_from:
- /library/snow/graph/template.hpp
- /library/snow/graph/template.hpp.html
title: Graph template
---
