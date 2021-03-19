---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: snow/graph/shortest-path/bellman-ford.hpp
    title: snow/graph/shortest-path/bellman-ford.hpp
  - icon: ':x:'
    path: snow/graph/shortest-path/dijkstra.hpp
    title: snow/graph/shortest-path/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/bellman-ford.test.cpp
    title: test/aoj/bellman-ford.test.cpp
  - icon: ':x:'
    path: test/aoj/dijkstra.test.cpp
    title: test/aoj/dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/graph/graph.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ snow {\r\n\r\ntemplate < typename T >\r\nstruct Graph {\r\n    struct Edge {\r\
    \n        int from, to;\r\n        T weight;\r\n        Edge() : from(0), to(0),\
    \ weight(0) {}\r\n        Edge(int from, int to, T weight) : from(from), to(to),\
    \ weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const auto INF = std::numeric_limits<T>::max();\r\n    std::vector<Edges>\
    \ G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n\
    \    Edges operator[](int k) const{\r\n        return G[k];\r\n    }\r\n\r\n \
    \   size_t size() const{\r\n        return G.size();\r\n    }\r\n\r\n    void\
    \ add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n\
    \        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\
    \n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\
    \n};\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace snow {\r\n\r\ntemplate\
    \ < typename T >\r\nstruct Graph {\r\n    struct Edge {\r\n        int from, to;\r\
    \n        T weight;\r\n        Edge() : from(0), to(0), weight(0) {}\r\n     \
    \   Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}\r\
    \n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const auto INF = std::numeric_limits<T>::max();\r\
    \n    std::vector<Edges> G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int\
    \ n) : G(n) {}\r\n\r\n    Edges operator[](int k) const{\r\n        return G[k];\r\
    \n    }\r\n\r\n    size_t size() const{\r\n        return G.size();\r\n    }\r\
    \n\r\n    void add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a,\
    \ b, w);\r\n        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\
    \n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\
    \n};\r\n\r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/graph/graph.hpp
  requiredBy:
  - snow/graph/shortest-path/bellman-ford.hpp
  - snow/graph/shortest-path/dijkstra.hpp
  timestamp: '2021-03-19 17:41:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/dijkstra.test.cpp
  - test/aoj/bellman-ford.test.cpp
documentation_of: snow/graph/graph.hpp
layout: document
redirect_from:
- /library/snow/graph/graph.hpp
- /library/snow/graph/graph.hpp.html
title: snow/graph/graph.hpp
---
