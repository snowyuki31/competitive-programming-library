---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/graph/template.hpp\"\n\r\n#include <vector>\r\n#include\
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
    \n};\r\n\r\n} // namespace snow\n#line 3 \"snow/graph/tree/rerooting.hpp\"\n\n\
    namespace snow {\n\ntemplate < typename T >\nstruct Rerooting {\n    \n};\n\n\
    }\n"
  code: "#pragma once\n#include \"snow/graph/template.hpp\"\n\nnamespace snow {\n\n\
    template < typename T >\nstruct Rerooting {\n    \n};\n\n}"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/snow/graph/tree/rerooting.hpp
- /library/snow/graph/tree/rerooting.hpp.html
title: snow/graph/tree/rerooting.hpp
---
