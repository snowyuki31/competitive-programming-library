---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: snow/graph/template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    document_title: Dikstra
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n\r\n#line 2 \"snow/graph/shortest-path/dijkstra.hpp\"\
    \n\r\n#include <vector>\r\n#include <queue>\r\n\r\n#line 2 \"snow/graph/template.hpp\"\
    \n\r\n#line 5 \"snow/graph/template.hpp\"\n\r\nnamespace snow {\r\n\r\n/**\r\n\
    \ * @brief Graph template\r\n */\r\ntemplate < typename T >\r\nstruct Graph {\r\
    \n    struct Edge {\r\n        int to;\r\n        T weight;\r\n        Edge()\
    \ : to(0), weight(0) {}\r\n        Edge(int to, T weight) : to(to), weight(weight)\
    \ {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const T INF\
    \ = std::numeric_limits<T>::max();\r\n    std::vector<Edges> G;\r\n\r\n    Graph()\
    \ : G() {}\r\n    \r\n    Graph(int n) : G(n) {}\r\n\r\n    Edges& operator[](int\
    \ k) {\r\n        return G[k];\r\n    }\r\n    const Edges& operator[](int k)\
    \ const {\r\n        return G[k];\r\n    }\r\n\r\n    size_t size() const{\r\n\
    \        return G.size();\r\n    }\r\n\r\n    void add_edge(int a, int b, T w\
    \ = 1){\r\n        G[a].emplace_back(b, w);\r\n        G[b].emplace_back(a, w);\r\
    \n    }\r\n\r\n    void add_directed_edge(int a, int b, T w = 1){\r\n        G[a].emplace_back(b,\
    \ w);\r\n    }\r\n\r\n    void add_arrow(int a, int b, T w = 1){\r\n        add_directed_edge(a,\
    \ b, w);\r\n    }\r\n\r\n    //Dijkstra\r\n    std::vector<T> dijkstra(int s)\
    \ const;\r\n\r\n    //Bellman-Ford\r\n    std::vector<T> bellman_ford(int s) const;\r\
    \n\r\n    //Warshall-Floyd\r\n    std::vector<std::vector<T>> warshall_floyd()\
    \ const;\r\n\r\n    //Topological sort\r\n    std::vector<int> topological_sort()\
    \ const;\r\n};\r\n\r\n} // namespace snow\n#line 7 \"snow/graph/shortest-path/dijkstra.hpp\"\
    \n\r\nnamespace snow{\r\n\r\n/**\r\n * @brief Dijkstra\r\n * \r\n * @param s \r\
    \n */\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::dijkstra(int s) const{\r\
    \n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>>\
    \ que;\r\n    std::vector<T> dist(G.size(), INF);\r\n    dist[s] = 0;\r\n    que.emplace(dist[s],\
    \ s);\r\n\r\n    while(!que.empty()){\r\n        auto [cost, idx] = que.top();\r\
    \n        que.pop();\r\n        if(dist[idx] < cost) continue;\r\n        for(auto\
    \ &e : G[idx]){\r\n            auto next_cost = cost + e.weight;\r\n         \
    \   if(dist[e.to] <= next_cost) continue;\r\n            dist[e.to] = next_cost;\r\
    \n            que.emplace(dist[e.to], e.to);\r\n        }\r\n    }\r\n    return\
    \ dist;\r\n}\r\n\r\n}\n#line 7 \"test/aoj/GRL_1_A.test.cpp\"\n\r\n/**\r\n * @brief\
    \ Dikstra\r\n * \r\n */\r\nint main(){\r\n    int V, E, r;\r\n    std::cin >>\
    \ V >> E >> r;\r\n\r\n    snow::Graph<long long> G(V);\r\n    while(E--){\r\n\
    \        int s, t, d;\r\n        std::cin >> s >> t >> d;\r\n        G.add_directed_edge(s,\
    \ t, d);\r\n    }\r\n\r\n    auto ret = G.dijkstra(r);\r\n    for(auto r : ret){\r\
    \n        if(r == G.INF) std::cout << \"INF\" << '\\n';\r\n        else std::cout\
    \ << r << '\\n';\r\n    }\r\n\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n\r\n#include \"snow/graph/shortest-path/dijkstra.hpp\"\
    \r\n\r\n/**\r\n * @brief Dikstra\r\n * \r\n */\r\nint main(){\r\n    int V, E,\
    \ r;\r\n    std::cin >> V >> E >> r;\r\n\r\n    snow::Graph<long long> G(V);\r\
    \n    while(E--){\r\n        int s, t, d;\r\n        std::cin >> s >> t >> d;\r\
    \n        G.add_directed_edge(s, t, d);\r\n    }\r\n\r\n    auto ret = G.dijkstra(r);\r\
    \n    for(auto r : ret){\r\n        if(r == G.INF) std::cout << \"INF\" << '\\\
    n';\r\n        else std::cout << r << '\\n';\r\n    }\r\n\r\n    return 0;\r\n\
    }"
  dependsOn:
  - snow/graph/shortest-path/dijkstra.hpp
  - snow/graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: Dikstra
---
