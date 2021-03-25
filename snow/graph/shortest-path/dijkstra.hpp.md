---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: Dikstra
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1065.test.cpp
    title: Dijkstra (decimal floating point ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"snow/graph/shortest-path/dijkstra.hpp\"\n\r\n#include <vector>\r\
    \n#include <queue>\r\n\r\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"\
    snow/graph/template.hpp\"\n#include <limits>\r\n\r\nnamespace snow {\r\n\r\n/**\r\
    \n * @brief Graph template\r\n */\r\ntemplate < typename T >\r\nstruct Graph {\r\
    \n    struct Edge {\r\n        int from, to;\r\n        T weight;\r\n        Edge()\
    \ : from(0), to(0), weight(0) {}\r\n        Edge(int from, int to, T weight) :\
    \ from(from), to(to), weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const T INF = std::numeric_limits<T>::max();\r\n    std::vector<Edges>\
    \ G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n\
    \    Edges& operator[](int k) {\r\n        return G[k];\r\n    }\r\n    const\
    \ Edges& operator[](int k) const {\r\n        return G[k];\r\n    }\r\n\r\n  \
    \  size_t size() const{\r\n        return G.size();\r\n    }\r\n\r\n    void add_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n        G[b].emplace_back(b,\
    \ a, w);\r\n    }\r\n\r\n    void add_directed_edge(int a, int b, T w = 1){\r\n\
    \        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n    void add_arrow(int a,\
    \ int b, T w = 1){\r\n        add_directed_edge(a, b, w);\r\n    }\r\n\r\n   \
    \ //Dijkstra\r\n    std::vector<T> dijkstra(int s) const;\r\n\r\n    //Bellman-Ford\r\
    \n    std::vector<T> bellman_ford(int s) const;\r\n\r\n    //Warshall-Floyd\r\n\
    \    std::vector<std::vector<T>> warshall_floyd() const;\r\n\r\n    //Topological\
    \ sort\r\n    std::vector<int> topological_sort() const;\r\n};\r\n\r\n} // namespace\
    \ snow\n#line 7 \"snow/graph/shortest-path/dijkstra.hpp\"\n\r\nnamespace snow{\r\
    \n\r\n/**\r\n * @brief Dijkstra\r\n * \r\n * @param s \r\n */\r\ntemplate < typename\
    \ T >\r\nstd::vector<T> Graph<T>::dijkstra(int s) const{\r\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> que;\r\n    std::vector<T>\
    \ dist(G.size(), INF);\r\n    dist[s] = 0;\r\n    que.emplace(dist[s], s);\r\n\
    \r\n    while(!que.empty()){\r\n        auto [cost, idx] = que.top();\r\n    \
    \    que.pop();\r\n        if(dist[idx] < cost) continue;\r\n        for(auto\
    \ &e : G[idx]){\r\n            auto next_cost = cost + e.weight;\r\n         \
    \   if(dist[e.to] <= next_cost) continue;\r\n            dist[e.to] = next_cost;\r\
    \n            que.emplace(dist[e.to], e.to);\r\n        }\r\n    }\r\n    return\
    \ dist;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <queue>\r\n\r\n#include\
    \ \"snow/graph/template.hpp\"\r\n\r\nnamespace snow{\r\n\r\n/**\r\n * @brief Dijkstra\r\
    \n * \r\n * @param s \r\n */\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::dijkstra(int\
    \ s) const{\r\n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<>> que;\r\n    std::vector<T> dist(G.size(), INF);\r\n \
    \   dist[s] = 0;\r\n    que.emplace(dist[s], s);\r\n\r\n    while(!que.empty()){\r\
    \n        auto [cost, idx] = que.top();\r\n        que.pop();\r\n        if(dist[idx]\
    \ < cost) continue;\r\n        for(auto &e : G[idx]){\r\n            auto next_cost\
    \ = cost + e.weight;\r\n            if(dist[e.to] <= next_cost) continue;\r\n\
    \            dist[e.to] = next_cost;\r\n            que.emplace(dist[e.to], e.to);\r\
    \n        }\r\n    }\r\n    return dist;\r\n}\r\n\r\n}"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/shortest-path/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-03-25 14:58:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1065.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: snow/graph/shortest-path/dijkstra.hpp
layout: document
redirect_from:
- /library/snow/graph/shortest-path/dijkstra.hpp
- /library/snow/graph/shortest-path/dijkstra.hpp.html
title: Dijkstra
---
