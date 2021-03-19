---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/graph.hpp
    title: snow/graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/graph/shortest-path/warshall-floyd.hpp\"\n\n#include\
    \ <vector>\n\n#line 2 \"snow/graph/graph.hpp\"\n\r\n#line 4 \"snow/graph/graph.hpp\"\
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
    \n    //warshall-floyd\r\n    std::vector<std::vector<T>> warshall_floyd() const;\r\
    \n\r\n};\r\n\r\n} // namespace snow\n#line 6 \"snow/graph/shortest-path/warshall-floyd.hpp\"\
    \n\nnamespace snow{\n\ntemplate < typename T >\nstd::vector<std::vector<T>> Graph<T>::warshall_floyd()\
    \ const{\n    int N = G.size();\n    std::vector<std::vector<T>> d(N, std::vector<T>(N,\
    \ INF));\n    \n    for(int i = 0; i < N; ++i) d[i][i] = 0;\n\n    for(int i =\
    \ 0; i < N; ++i) for(auto &e : G[i]) d[i][e.to] = e.weight;\n\n    for(int k =\
    \ 0; k < N; ++k){\n        for(int i = 0; i < N; ++i){\n            for(int j\
    \ = 0; j < N; ++j){\n                if(d[i][k] == INF or d[k][j] == INF) continue;\n\
    \n                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);\n          \
    \  }\n        }\n    }\n    return d;\n \n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"snow/graph/graph.hpp\"\n\n\
    namespace snow{\n\ntemplate < typename T >\nstd::vector<std::vector<T>> Graph<T>::warshall_floyd()\
    \ const{\n    int N = G.size();\n    std::vector<std::vector<T>> d(N, std::vector<T>(N,\
    \ INF));\n    \n    for(int i = 0; i < N; ++i) d[i][i] = 0;\n\n    for(int i =\
    \ 0; i < N; ++i) for(auto &e : G[i]) d[i][e.to] = e.weight;\n\n    for(int k =\
    \ 0; k < N; ++k){\n        for(int i = 0; i < N; ++i){\n            for(int j\
    \ = 0; j < N; ++j){\n                if(d[i][k] == INF or d[k][j] == INF) continue;\n\
    \n                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);\n          \
    \  }\n        }\n    }\n    return d;\n \n}\n\n}"
  dependsOn:
  - snow/graph/graph.hpp
  isVerificationFile: false
  path: snow/graph/shortest-path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2021-03-19 20:50:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: snow/graph/shortest-path/warshall-floyd.hpp
layout: document
redirect_from:
- /library/snow/graph/shortest-path/warshall-floyd.hpp
- /library/snow/graph/shortest-path/warshall-floyd.hpp.html
title: snow/graph/shortest-path/warshall-floyd.hpp
---
