---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: snow/graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/graph/shortest-path/bellman-ford.hpp\"\n\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\
    \n\r\nnamespace snow {\r\n\r\ntemplate < typename T >\r\nstruct Graph {\r\n  \
    \  struct Edge {\r\n        int from, to;\r\n        T weight;\r\n        Edge()\
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
    \n};\r\n\r\n} // namespace snow\n#line 6 \"snow/graph/shortest-path/bellman-ford.hpp\"\
    \n\r\nnamespace snow{\r\n\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::bellman_ford(int\
    \ s) const{\r\n    std::vector<T> dist(G.size(), INF);\r\n    dist[s] = 0;\r\n\
    \    for(int i = 0; i < G.size(); ++i){\r\n        for(int j = 0; j < G.size();\
    \ ++j){\r\n            for(auto& e : G[j]){\r\n                if(dist[e.from]\
    \ == INF) continue;\r\n                if(dist[e.to] > dist[e.from] + e.weight){\r\
    \n                    dist[e.to] = dist[e.from] + e.weight;\r\n              \
    \      if(i == (G.size() - 1)) return {};\r\n                }\r\n           \
    \ }\r\n        }\r\n    }\r\n    return dist;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n#include \"snow/graph/template.hpp\"\
    \r\n\r\nnamespace snow{\r\n\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::bellman_ford(int\
    \ s) const{\r\n    std::vector<T> dist(G.size(), INF);\r\n    dist[s] = 0;\r\n\
    \    for(int i = 0; i < G.size(); ++i){\r\n        for(int j = 0; j < G.size();\
    \ ++j){\r\n            for(auto& e : G[j]){\r\n                if(dist[e.from]\
    \ == INF) continue;\r\n                if(dist[e.to] > dist[e.from] + e.weight){\r\
    \n                    dist[e.to] = dist[e.from] + e.weight;\r\n              \
    \      if(i == (G.size() - 1)) return {};\r\n                }\r\n           \
    \ }\r\n        }\r\n    }\r\n    return dist;\r\n}\r\n\r\n}"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/shortest-path/bellman-ford.hpp
  requiredBy: []
  timestamp: '2021-03-22 03:30:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: snow/graph/shortest-path/bellman-ford.hpp
layout: document
redirect_from:
- /library/snow/graph/shortest-path/bellman-ford.hpp
- /library/snow/graph/shortest-path/bellman-ford.hpp.html
title: snow/graph/shortest-path/bellman-ford.hpp
---