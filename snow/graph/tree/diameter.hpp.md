---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/oj/tree_diameter.test.cpp
    title: Tree Diameter
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Diameter (\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"snow/graph/tree/diameter.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\
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
    \n};\r\n\r\n} // namespace snow\n#line 5 \"snow/graph/tree/diameter.hpp\"\n\n\
    namespace snow {\n\n/**\n * @brief Diameter (\u6728\u306E\u76F4\u5F84)\n * @tparam\
    \ T edge weight type\n */\ntemplate < typename T = int >\nstruct Diameter {\n\
    \    public:\n        Diameter(snow::Graph<T> const& G) : N(G.size()), G(G), dist(N,\
    \ 0), dist_(N, 0) {\n            dfs(G, 0, -1, dist);\n            left = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n            dist[left] = 0;\n            dfs(G,\
    \ left, -1, dist);\n            right = std::max_element(dist.begin(), dist.end())\
    \ - dist.begin();\n            dfs(G, right, -1, dist_);\n        }\n\n      \
    \  std::pair<int, int> get_ends(){\n            return {left, right};\n      \
    \  }\n\n        T size(){\n            return dist[right];\n        }\n\n    \
    \    bool is_on(int x){\n            return dist[x] + dist_[x] == dist[right];\n\
    \        }\n\n        std::vector<int> get_path(){\n            std::vector<int>\
    \ path{left};\n            _dfs(G, left, -1, path);\n            return path;\n\
    \        }\n\n    private:\n        int N;\n        snow::Graph<T> G;\n      \
    \  std::vector<T> dist;\n        std::vector<T> dist_;\n        int left, right;\n\
    \n        void dfs(snow::Graph<T> const& G, int s, int p, std::vector<T>& dist)\
    \ {\n            for(auto e : G[s]) if(e.to != p){\n                dist[e.to]\
    \ = dist[s] + e.weight;\n                dfs(G, e.to, s, dist);\n            }\n\
    \        }\n\n        void _dfs(snow::Graph<T> const &G, int s, int p, std::vector<int>\
    \ &path){\n            for(auto e : G[s]) if(e.to != p and is_on(e.to)){\n   \
    \             path.emplace_back(e.to);\n                _dfs(G, e.to, s, path);\n\
    \            }\n        }\n};\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"snow/graph/template.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Diameter (\u6728\u306E\u76F4\u5F84)\n *\
    \ @tparam T edge weight type\n */\ntemplate < typename T = int >\nstruct Diameter\
    \ {\n    public:\n        Diameter(snow::Graph<T> const& G) : N(G.size()), G(G),\
    \ dist(N, 0), dist_(N, 0) {\n            dfs(G, 0, -1, dist);\n            left\
    \ = std::max_element(dist.begin(), dist.end()) - dist.begin();\n            dist[left]\
    \ = 0;\n            dfs(G, left, -1, dist);\n            right = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n            dfs(G, right, -1, dist_);\n       \
    \ }\n\n        std::pair<int, int> get_ends(){\n            return {left, right};\n\
    \        }\n\n        T size(){\n            return dist[right];\n        }\n\n\
    \        bool is_on(int x){\n            return dist[x] + dist_[x] == dist[right];\n\
    \        }\n\n        std::vector<int> get_path(){\n            std::vector<int>\
    \ path{left};\n            _dfs(G, left, -1, path);\n            return path;\n\
    \        }\n\n    private:\n        int N;\n        snow::Graph<T> G;\n      \
    \  std::vector<T> dist;\n        std::vector<T> dist_;\n        int left, right;\n\
    \n        void dfs(snow::Graph<T> const& G, int s, int p, std::vector<T>& dist)\
    \ {\n            for(auto e : G[s]) if(e.to != p){\n                dist[e.to]\
    \ = dist[s] + e.weight;\n                dfs(G, e.to, s, dist);\n            }\n\
    \        }\n\n        void _dfs(snow::Graph<T> const &G, int s, int p, std::vector<int>\
    \ &path){\n            for(auto e : G[s]) if(e.to != p and is_on(e.to)){\n   \
    \             path.emplace_back(e.to);\n                _dfs(G, e.to, s, path);\n\
    \            }\n        }\n};\n\n} // namespace snow"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/tree/diameter.hpp
  requiredBy: []
  timestamp: '2021-04-22 17:27:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/oj/tree_diameter.test.cpp
documentation_of: snow/graph/tree/diameter.hpp
layout: document
redirect_from:
- /library/snow/graph/tree/diameter.hpp
- /library/snow/graph/tree/diameter.hpp.html
title: "Diameter (\u6728\u306E\u76F4\u5F84)"
---
