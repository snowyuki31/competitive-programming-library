---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/oj/lowest_common_ancestor_2.test.cpp
    title: Lowest Common Ancestor (Heavy Light Decomposition ver.)
  - icon: ':x:'
    path: test/oj/vertex_add_path_sum_2.test.cpp
    title: Vertex Add Path Sum (Heavy Light Decomposition ver.)
  - icon: ':x:'
    path: test/oj/vertex_add_subtree_sum_2.test.cpp
    title: Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Heavy Light Decomposition
    links:
    - https://codeforces.com/blog/entry/53170
  bundledCode: "#line 2 \"snow/graph/tree/heavy-light-decomposition.hpp\"\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line\
    \ 4 \"snow/graph/template.hpp\"\n#include <limits>\r\n\r\nnamespace snow {\r\n\
    \r\n/**\r\n * @brief Graph template\r\n */\r\ntemplate < typename T >\r\nstruct\
    \ Graph {\r\n    struct Edge {\r\n        int to;\r\n        T weight;\r\n   \
    \     Edge() : to(0), weight(0) {}\r\n        Edge(int to, T weight) : to(to),\
    \ weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const T INF = std::numeric_limits<T>::max();\r\n    std::vector<Edges> G;\r\
    \n\r\n    Graph() : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n    Edges&\
    \ operator[](int k) {\r\n        return G[k];\r\n    }\r\n    const Edges& operator[](int\
    \ k) const {\r\n        return G[k];\r\n    }\r\n\r\n    size_t size() const{\r\
    \n        return G.size();\r\n    }\r\n\r\n    void add_edge(int a, int b, T w\
    \ = 1){\r\n        G[a].emplace_back(b, w);\r\n        G[b].emplace_back(a, w);\r\
    \n    }\r\n\r\n    void add_directed_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(b,\
    \ w);\r\n    }\r\n\r\n    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a,\
    \ b, w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s)\
    \ const;\r\n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\
    \n\r\n    //Warshall-Floyd\r\n    std::vector<std::vector<T>> warshall_floyd()\
    \ const;\r\n\r\n    //Topological sort\r\n    std::vector<int> topological_sort()\
    \ const;\r\n};\r\n\r\n} // namespace snow\n#line 5 \"snow/graph/tree/heavy-light-decomposition.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Heavy Light Decomposition\n * \n * @tparam\
    \ T \n * @ref https://codeforces.com/blog/entry/53170\n */\ntemplate < typename\
    \ T = int >\nstruct HeavyLightDecomposition {\n    public:\n        HeavyLightDecomposition(snow::Graph<T>&\
    \ G, int root) : N(G.size()), sz(N), in(N), par(N), next(N), depth(N) {\n    \
    \        dfs_sz(G, root);\n            next[root] = root;\n            dfs_hld(G,\
    \ root);\n        }\n\n        /**\n         * @brief Get vertex id.\n       \
    \  * @param v \n         */\n        int get_id(int v){\n            return in[v];\n\
    \        }\n\n        /**\n         * @brief Get Edge id.\n         */\n     \
    \   int get_edge_id(int u, int v){\n            if(depth[u] > depth[v]) swap(u,\
    \ v);\n            return get_id(v);\n        }\n\n        /**\n         * @brief\
    \ Get depth.\n         * \n         */\n        int get_depth(int u){\n      \
    \      return depth[u];\n        }\n\n        /**\n         * @brief Get Lowest\
    \ Common Ancestor of (u, v).\n         * \n         * @param u \n         * @param\
    \ v \n         */\n        int get_lca(int u, int v){\n            while (true){\n\
    \                if(in[u] > in[v]) std::swap(u, v);\n                if(next[u]\
    \ == next[v]) return u;\n                v = par[next[v]];\n            }\n  \
    \      }\n\n        /**\n         * @brief Get a segment of id corresponding to\
    \ the subtree of v.\n         * @param v \n         */\n        std::pair<int,\
    \ int> get_subtree(int v){\n            return {in[v], in[v] + sz[v]};\n     \
    \   }\n\n        /**\n         * @brief Get segments of id corresponding to the\
    \ path from u to v inclusive.\n         * @param u\n         * @param v\n    \
    \     * @return vector<pair<int, int>> : set of segments [l_i, r_i)\n        \
    \ */\n        std::vector<std::pair<int, int>> get_path(int u, int v) {\n    \
    \        std::vector<std::pair<int, int>> path;\n            while (true){\n \
    \               if(in[u] > in[v]) std::swap(u, v);\n                path.emplace_back(std::max(in[next[v]],\
    \ in[u]), in[v] + 1);\n\n                if(next[u] != next[v]) v = par[next[v]];\n\
    \                else break;\n            }\n            return path;\n      \
    \  }\n\n        /**\n         * @brief Get segments of id corresponding to the\
    \ edge-wise path from u to v inclusive.\n         * @param u\n         * @param\
    \ v\n         * @return vector<pair<int, int>> : set of segments [l_i, r_i)\n\
    \         */\n        std::vector<std::pair<int, int>> get_edge_path(int u, int\
    \ v){\n            std::vector<std::pair<int, int>> path;\n            while (true){\n\
    \                if(in[u] > in[v]) std::swap(u, v);\n                if(next[u]\
    \ != next[v]) {\n                    path.emplace_back(in[next[v]], in[v] + 1);\n\
    \                    v = par[next[v]];\n                }\n                else{\n\
    \                    if(u != v) path.emplace_back(in[u] + 1, in[v] + 1);\n   \
    \                 break;\n                }\n            }\n            return\
    \ path;\n        }\n\n    private:\n        int N;\n        std::vector<int> sz;\n\
    \        std::vector<int> in;\n        std::vector<int> out;\n        std::vector<int>\
    \ par;\n        std::vector<int> next; // last vertex of heavy chain of x\n  \
    \      std::vector<int> depth;\n\n        void dfs_sz(snow::Graph<T>& G, int v,\
    \ int p = -1){\n            sz[v] = 1;\n            if(p != -1) depth[v] = depth[p]\
    \ + 1;\n            for(auto &e : G[v]) if(e.to != p) {\n                dfs_sz(G,\
    \ e.to, v);\n                sz[v] += sz[e.to];\n                if(sz[e.to] >\
    \ sz[G[v][0].to]) std::swap(e, G[v][0]);\n            }\n        }\n\n       \
    \ int order = 0;\n        void dfs_hld(snow::Graph<T>& G, int v, int p = -1){\n\
    \            par[v] = p, in[v] = order++;\n            for(auto e : G[v]) if(e.to\
    \ != p) {\n                next[e.to] = ((e.to == G[v].front().to) ? next[v] :\
    \ e.to);\n                dfs_hld(G, e.to, v);\n            }\n        }\n};\n\
    \n} // namespace snow\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include \"snow/graph/template.hpp\"\
    \n\nnamespace snow {\n\n/**\n * @brief Heavy Light Decomposition\n * \n * @tparam\
    \ T \n * @ref https://codeforces.com/blog/entry/53170\n */\ntemplate < typename\
    \ T = int >\nstruct HeavyLightDecomposition {\n    public:\n        HeavyLightDecomposition(snow::Graph<T>&\
    \ G, int root) : N(G.size()), sz(N), in(N), par(N), next(N), depth(N) {\n    \
    \        dfs_sz(G, root);\n            next[root] = root;\n            dfs_hld(G,\
    \ root);\n        }\n\n        /**\n         * @brief Get vertex id.\n       \
    \  * @param v \n         */\n        int get_id(int v){\n            return in[v];\n\
    \        }\n\n        /**\n         * @brief Get Edge id.\n         */\n     \
    \   int get_edge_id(int u, int v){\n            if(depth[u] > depth[v]) swap(u,\
    \ v);\n            return get_id(v);\n        }\n\n        /**\n         * @brief\
    \ Get depth.\n         * \n         */\n        int get_depth(int u){\n      \
    \      return depth[u];\n        }\n\n        /**\n         * @brief Get Lowest\
    \ Common Ancestor of (u, v).\n         * \n         * @param u \n         * @param\
    \ v \n         */\n        int get_lca(int u, int v){\n            while (true){\n\
    \                if(in[u] > in[v]) std::swap(u, v);\n                if(next[u]\
    \ == next[v]) return u;\n                v = par[next[v]];\n            }\n  \
    \      }\n\n        /**\n         * @brief Get a segment of id corresponding to\
    \ the subtree of v.\n         * @param v \n         */\n        std::pair<int,\
    \ int> get_subtree(int v){\n            return {in[v], in[v] + sz[v]};\n     \
    \   }\n\n        /**\n         * @brief Get segments of id corresponding to the\
    \ path from u to v inclusive.\n         * @param u\n         * @param v\n    \
    \     * @return vector<pair<int, int>> : set of segments [l_i, r_i)\n        \
    \ */\n        std::vector<std::pair<int, int>> get_path(int u, int v) {\n    \
    \        std::vector<std::pair<int, int>> path;\n            while (true){\n \
    \               if(in[u] > in[v]) std::swap(u, v);\n                path.emplace_back(std::max(in[next[v]],\
    \ in[u]), in[v] + 1);\n\n                if(next[u] != next[v]) v = par[next[v]];\n\
    \                else break;\n            }\n            return path;\n      \
    \  }\n\n        /**\n         * @brief Get segments of id corresponding to the\
    \ edge-wise path from u to v inclusive.\n         * @param u\n         * @param\
    \ v\n         * @return vector<pair<int, int>> : set of segments [l_i, r_i)\n\
    \         */\n        std::vector<std::pair<int, int>> get_edge_path(int u, int\
    \ v){\n            std::vector<std::pair<int, int>> path;\n            while (true){\n\
    \                if(in[u] > in[v]) std::swap(u, v);\n                if(next[u]\
    \ != next[v]) {\n                    path.emplace_back(in[next[v]], in[v] + 1);\n\
    \                    v = par[next[v]];\n                }\n                else{\n\
    \                    if(u != v) path.emplace_back(in[u] + 1, in[v] + 1);\n   \
    \                 break;\n                }\n            }\n            return\
    \ path;\n        }\n\n    private:\n        int N;\n        std::vector<int> sz;\n\
    \        std::vector<int> in;\n        std::vector<int> out;\n        std::vector<int>\
    \ par;\n        std::vector<int> next; // last vertex of heavy chain of x\n  \
    \      std::vector<int> depth;\n\n        void dfs_sz(snow::Graph<T>& G, int v,\
    \ int p = -1){\n            sz[v] = 1;\n            if(p != -1) depth[v] = depth[p]\
    \ + 1;\n            for(auto &e : G[v]) if(e.to != p) {\n                dfs_sz(G,\
    \ e.to, v);\n                sz[v] += sz[e.to];\n                if(sz[e.to] >\
    \ sz[G[v][0].to]) std::swap(e, G[v][0]);\n            }\n        }\n\n       \
    \ int order = 0;\n        void dfs_hld(snow::Graph<T>& G, int v, int p = -1){\n\
    \            par[v] = p, in[v] = order++;\n            for(auto e : G[v]) if(e.to\
    \ != p) {\n                next[e.to] = ((e.to == G[v].front().to) ? next[v] :\
    \ e.to);\n                dfs_hld(G, e.to, v);\n            }\n        }\n};\n\
    \n} // namespace snow"
  dependsOn:
  - snow/graph/template.hpp
  isVerificationFile: false
  path: snow/graph/tree/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2021-05-13 03:29:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/oj/vertex_add_subtree_sum_2.test.cpp
  - test/oj/vertex_add_path_sum_2.test.cpp
  - test/oj/lowest_common_ancestor_2.test.cpp
documentation_of: snow/graph/tree/heavy-light-decomposition.hpp
layout: document
redirect_from:
- /library/snow/graph/tree/heavy-light-decomposition.hpp
- /library/snow/graph/tree/heavy-light-decomposition.hpp.html
title: Heavy Light Decomposition
---
