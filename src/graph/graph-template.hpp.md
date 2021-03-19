---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/graph/shortest/bellman-ford.hpp
    title: src/graph/shortest/bellman-ford.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/bellman-ford.test.cpp
    title: test/aoj/bellman-ford.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/graph-template.hpp\"\n\r\n#include <vector>\r\n\
    \r\nnamespace snow {\r\n\r\ntemplate < typename T >\r\nstruct Graph {\r\n    struct\
    \ Edge {\r\n        int from, to;\r\n        T weight;\r\n        Edge() : from(0),\
    \ to(0), weight(0) {}\r\n        Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    Edges G;\r\n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n)\
    \ {}\r\n\r\n    Edges operator[](int k) const{\r\n        return G[k];\r\n   \
    \ }\r\n\r\n    size_t size() const{\r\n        return G.size();\r\n    }\r\n\r\
    \n    void add_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(a, b,\
    \ w);\r\n        G[b].emplace_back(b, a, w);\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ a, int b, T w = 1){\r\n        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n\
    \    void add_arrow(int a, int b, T W = 1){\r\n        add_directed_edge(a, b,\
    \ w);\r\n    }\r\n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int\
    \ s) const;\r\n\r\n};\r\n\r\n} // namespace snow\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace snow {\r\n\r\ntemplate\
    \ < typename T >\r\nstruct Graph {\r\n    struct Edge {\r\n        int from, to;\r\
    \n        T weight;\r\n        Edge() : from(0), to(0), weight(0) {}\r\n     \
    \   Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}\r\
    \n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n    Edges G;\r\n\r\n \
    \   Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n    Edges operator[](int\
    \ k) const{\r\n        return G[k];\r\n    }\r\n\r\n    size_t size() const{\r\
    \n        return G.size();\r\n    }\r\n\r\n    void add_edge(int a, int b, T w\
    \ = 1){\r\n        G[a].emplace_back(a, b, w);\r\n        G[b].emplace_back(b,\
    \ a, w);\r\n    }\r\n\r\n    void add_directed_edge(int a, int b, T w = 1){\r\n\
    \        G[a].emplace_back(a, b, w);\r\n    }\r\n\r\n    void add_arrow(int a,\
    \ int b, T W = 1){\r\n        add_directed_edge(a, b, w);\r\n    }\r\n\r\n   \
    \ //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\n\r\n};\r\n\
    \r\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/graph-template.hpp
  requiredBy:
  - src/graph/shortest/bellman-ford.hpp
  timestamp: '2021-03-19 10:23:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/bellman-ford.test.cpp
documentation_of: src/graph/graph-template.hpp
layout: document
redirect_from:
- /library/src/graph/graph-template.hpp
- /library/src/graph/graph-template.hpp.html
title: src/graph/graph-template.hpp
---
