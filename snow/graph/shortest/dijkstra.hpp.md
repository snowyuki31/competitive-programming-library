---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: snow/graph/graph.hpp
    title: snow/graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/dijkstra.test.cpp
    title: test/aoj/dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/graph/shortest/dijkstra.hpp\"\n\r\n#include <vector>\r\
    \n#include <queue>\r\n#include <limits>\r\n\r\n#line 2 \"snow/graph/graph.hpp\"\
    \n\r\n#line 4 \"snow/graph/graph.hpp\"\n\r\nnamespace snow {\r\n\r\ntemplate <\
    \ typename T >\r\nstruct Graph {\r\n    struct Edge {\r\n        int from, to;\r\
    \n        T weight;\r\n        Edge() : from(0), to(0), weight(0) {}\r\n     \
    \   Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}\r\
    \n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n    std::vector<Edges>\
    \ G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n\
    \    Edges operator[](int k) const{\r\n        return G[k];\r\n    }\r\n\r\n \
    \   size_t size() const{\r\n        return G.size();\r\n    }\r\n\r\n    void\
    \ add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n\
    \        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\
    \n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\
    \n};\r\n\r\n} // namespace snow\n#line 8 \"snow/graph/shortest/dijkstra.hpp\"\n\
    \r\nnamespace snow{\r\n\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::bellman_ford(int\
    \ s) const{\r\n    const auto INF = std::numeric_limits<T>::max();\r\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> que;\r\n    std::vector<T>\
    \ dist(G.size(), INF);\r\n    dist[s] = 0;\r\n    que.emplace(dist[s], s);\r\n\
    \r\n    while(!que.empty()){\r\n        auto [cost, idx] = que.top();\r\n    \
    \    que.pop();\r\n        if(dist[idx] < cost) continue;\r\n        for(auto\
    \ &e : G[idx]){\r\n            auto next_cost = cost + e.weight;\r\n         \
    \   if(dist[e.to] <= next_cost) continue;\r\n            dist[e.to] = next_cost;\r\
    \n            que.emplace(dist[e.to], e.to);\r\n        }\r\n    }\r\n    return\
    \ dist;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <queue>\r\n#include <limits>\r\
    \n\r\n#include \"snow/graph/graph.hpp\"\r\n\r\nnamespace snow{\r\n\r\ntemplate\
    \ < typename T >\r\nstd::vector<T> Graph<T>::bellman_ford(int s) const{\r\n  \
    \  const auto INF = std::numeric_limits<T>::max();\r\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> que;\r\n    std::vector<T>\
    \ dist(G.size(), INF);\r\n    dist[s] = 0;\r\n    que.emplace(dist[s], s);\r\n\
    \r\n    while(!que.empty()){\r\n        auto [cost, idx] = que.top();\r\n    \
    \    que.pop();\r\n        if(dist[idx] < cost) continue;\r\n        for(auto\
    \ &e : G[idx]){\r\n            auto next_cost = cost + e.weight;\r\n         \
    \   if(dist[e.to] <= next_cost) continue;\r\n            dist[e.to] = next_cost;\r\
    \n            que.emplace(dist[e.to], e.to);\r\n        }\r\n    }\r\n    return\
    \ dist;\r\n}\r\n\r\n}"
  dependsOn:
  - snow/graph/graph.hpp
  isVerificationFile: false
  path: snow/graph/shortest/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-03-19 10:56:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/dijkstra.test.cpp
documentation_of: snow/graph/shortest/dijkstra.hpp
layout: document
redirect_from:
- /library/snow/graph/shortest/dijkstra.hpp
- /library/snow/graph/shortest/dijkstra.hpp.html
title: snow/graph/shortest/dijkstra.hpp
---
