---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0517.test.cpp
    title: Topological Sort
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Topological Sort
    links: []
  bundledCode: "#line 2 \"snow/graph/topological-sort.hpp\"\n\n#include <vector>\n\
    #include <queue>\n\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\
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
    \n};\r\n\r\n} // namespace snow\n#line 7 \"snow/graph/topological-sort.hpp\"\n\
    \nnamespace snow {\n\n/**\n * @brief Topological Sort\n * \n */\ntemplate < typename\
    \ T >\nstd::vector<int> Graph<T>::topological_sort() const {\n    int N = G.size();\n\
    \    std::vector<int> ind(N, 0);\n    \n    for(int i = 0; i < N; ++i) for (auto\
    \ &e : G[i]) ind[e.to]++;\n    \n    std::queue<int> que;\n    for(int i = 0;\
    \ i < N; ++i) if (ind[i] == 0) que.push(i);\n\n    std::vector<int> ans;\n   \
    \ while(!que.empty()){\n        int now = que.front();\n        que.pop();\n \
    \       ans.emplace_back(now);\n\n        for(auto& e : G[now]) {\n          \
    \  ind[e.to]--;\n            if(ind[e.to] == 0) que.push(e.to);\n        }\n \
    \   }\n\n    if ((int)ans.size() != N) return {};\n    return ans;\n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n\n#include \"snow/graph/template.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Topological Sort\n * \n */\ntemplate <\
    \ typename T >\nstd::vector<int> Graph<T>::topological_sort() const {\n    int\
    \ N = G.size();\n    std::vector<int> ind(N, 0);\n    \n    for(int i = 0; i <\
    \ N; ++i) for (auto &e : G[i]) ind[e.to]++;\n    \n    std::queue<int> que;\n\
    \    for(int i = 0; i < N; ++i) if (ind[i] == 0) que.push(i);\n\n    std::vector<int>\
    \ ans;\n    while(!que.empty()){\n        int now = que.front();\n        que.pop();\n\
    \        ans.emplace_back(now);\n\n        for(auto& e : G[now]) {\n         \
    \   ind[e.to]--;\n            if(ind[e.to] == 0) que.push(e.to);\n        }\n\
    \    }\n\n    if ((int)ans.size() != N) return {};\n    return ans;\n}\n\n}"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0517.test.cpp
documentation_of: snow/graph/topological-sort.hpp
layout: document
redirect_from:
- /library/snow/graph/topological-sort.hpp
- /library/snow/graph/topological-sort.hpp.html
title: Topological Sort
---
