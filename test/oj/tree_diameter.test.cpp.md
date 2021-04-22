---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/diameter.hpp
    title: "Diameter (\u6728\u306E\u76F4\u5F84)"
  - icon: ':heavy_check_mark:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    document_title: Tree Diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/oj/tree_diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n#include <iostream>\n#line 3 \"snow/io/helper.hpp\"\n#include <vector>\n#include\
    \ <set>\n\ntemplate< typename T1, typename T2 >\nstd::ostream &operator << (std::ostream\
    \ &os, const std::pair< T1, T2 > &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\n\ntemplate< typename T1, typename T2 >\nstd::istream &operator\
    \ >> (std::istream &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {\n    auto\
    \ &[a, b, c] = t;\n    os << a << \" \" << b << \" \" << c;\n    return os;\n\
    }\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::istream &operator\
    \ >> (std::istream &is, std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b, c] =\
    \ t;\n    is >> a >> b >> c;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::vector< T > &v){\n    for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n        os << v[i] << (i + 1 != v.size() ? \"\
    \ \" : \"\");\n    }\n    return os;\n}\n\ntemplate< typename T >\nstd::istream\
    \ &operator >>  (std::istream &is, std::vector< T > &v){\n    for(T &in : v) is\
    \ >> in;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::set< T > &st){\n    int ct = 0;\n    for(auto&\
    \ s : st) os << s << (++ct != (int)st.size() ? \" \" : \"\");\n    return os;\n\
    }\n\ntemplate<class... T>\nvoid input(T&... a){\n    (std::cin >> ... >> a);\n\
    }\n\nvoid print() {\n    std::cout << '\\n';\n}\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    std::cout << a;\n    (std::cout <<\
    \ ... << (std::cout << ' ', b));\n    std::cout << '\\n';\n}\n\nint drop() {\n\
    \    std::cout << '\\n';\n    exit(0);\n}\ntemplate<class T, class... Ts>\nint\
    \ drop(const T& a, const Ts&... b){\n    std::cout << a;\n    (std::cout << ...\
    \ << (std::cout << ' ', b));\n    std::cout << '\\n';\n    exit(0);\n}\n#line\
    \ 3 \"snow/graph/tree/diameter.hpp\"\n#include <algorithm>\n#line 2 \"snow/graph/template.hpp\"\
    \n\r\n#line 4 \"snow/graph/template.hpp\"\n#include <limits>\r\n\r\nnamespace\
    \ snow {\r\n\r\n/**\r\n * @brief Graph template\r\n */\r\ntemplate < typename\
    \ T >\r\nstruct Graph {\r\n    struct Edge {\r\n        int to;\r\n        T weight;\r\
    \n        Edge() : to(0), weight(0) {}\r\n        Edge(int to, T weight) : to(to),\
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
    \ const;\r\n};\r\n\r\n} // namespace snow\n#line 5 \"snow/graph/tree/diameter.hpp\"\
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
    \            }\n        }\n};\n\n} // namespace snow\n#line 5 \"test/oj/tree_diameter.test.cpp\"\
    \n\n/**\n * @brief Tree Diameter\n * \n */\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    snow::Graph<long long> G(N);\n    for (int i = 0; i < N - 1; ++i){\n\
    \        int a, b;\n        long long c;\n        std::cin >> a >> b >> c;\n \
    \       G.add_edge(a, b, c);\n    }\n    snow::Diameter diameter(G);\n    auto\
    \ path = diameter.get_path();\n    print(diameter.size(), path.size());\n    print(path);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ <iostream>\n#include \"snow/io/helper.hpp\"\n#include \"snow/graph/tree/diameter.hpp\"\
    \n\n/**\n * @brief Tree Diameter\n * \n */\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    snow::Graph<long long> G(N);\n    for (int i = 0; i < N - 1; ++i){\n\
    \        int a, b;\n        long long c;\n        std::cin >> a >> b >> c;\n \
    \       G.add_edge(a, b, c);\n    }\n    snow::Diameter diameter(G);\n    auto\
    \ path = diameter.get_path();\n    print(diameter.size(), path.size());\n    print(path);\n\
    }"
  dependsOn:
  - snow/io/helper.hpp
  - snow/graph/tree/diameter.hpp
  - snow/graph/template.hpp
  isVerificationFile: true
  path: test/oj/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-04-22 17:40:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/oj/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/oj/tree_diameter.test.cpp
- /verify/test/oj/tree_diameter.test.cpp.html
title: Tree Diameter
---
