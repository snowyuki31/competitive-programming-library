---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/graph.hpp
    title: snow/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/bellman-ford.hpp
    title: snow/graph/shortest-path/bellman-ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/bellman-ford.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n\r\n#line 2 \"snow/graph/shortest-path/bellman-ford.hpp\"\
    \n\r\n#include <vector>\r\n#line 5 \"snow/graph/shortest-path/bellman-ford.hpp\"\
    \n\r\n#line 2 \"snow/graph/graph.hpp\"\n\r\n#line 4 \"snow/graph/graph.hpp\"\n\
    \r\nnamespace snow {\r\n\r\ntemplate < typename T >\r\nstruct Graph {\r\n    struct\
    \ Edge {\r\n        int from, to;\r\n        T weight;\r\n        Edge() : from(0),\
    \ to(0), weight(0) {}\r\n        Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\r\n    };\r\n    using Edges = std::vector<Edge>;\r\
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
    \n};\r\n\r\n} // namespace snow\n#line 7 \"snow/graph/shortest-path/bellman-ford.hpp\"\
    \n\r\nnamespace snow{\r\n\r\ntemplate < typename T >\r\nstd::vector<T> Graph<T>::bellman_ford(int\
    \ s) const{\r\n    std::vector<T> dist(G.size(), INF);\r\n    dist[s] = 0;\r\n\
    \    for(int i = 0; i < G.size(); ++i){\r\n        for(int j = 0; j < G.size();\
    \ ++j){\r\n            for(auto& e : G[j]){\r\n                if(dist[e.from]\
    \ == INF) continue;\r\n                if(dist[e.to] > dist[e.from] + e.weight){\r\
    \n                    dist[e.to] = dist[e.from] + e.weight;\r\n              \
    \      if(i == (G.size() - 1)) return {};\r\n                }\r\n           \
    \ }\r\n        }\r\n    }\r\n    return dist;\r\n}\r\n\r\n}\n#line 7 \"test/aoj/bellman-ford.test.cpp\"\
    \n\r\nint main(){\r\n    int V, E, r;\r\n    std::cin >> V >> E >> r;\r\n\r\n\
    \    snow::Graph<int> G(V);\r\n    while(E--){\r\n        int s, t, d;\r\n   \
    \     std::cin >> s >> t >> d;\r\n        G.add_directed_edge(s, t, d);\r\n  \
    \  }\r\n\r\n    const auto INF = std::numeric_limits<int>::max();\r\n    auto\
    \ ret = G.bellman_ford(r);\r\n    if(ret.empty()) std::cout << \"NEGATIVE CYCLE\"\
    \ << '\\n';\r\n    else{\r\n        for(auto r : ret){\r\n            if(r ==\
    \ INF) std::cout << \"INF\" << '\\n';\r\n            else std::cout << r << '\\\
    n';\r\n        }\r\n    }\r\n\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n\r\n#include \"snow/graph/shortest-path/bellman-ford.hpp\"\
    \r\n\r\nint main(){\r\n    int V, E, r;\r\n    std::cin >> V >> E >> r;\r\n\r\n\
    \    snow::Graph<int> G(V);\r\n    while(E--){\r\n        int s, t, d;\r\n   \
    \     std::cin >> s >> t >> d;\r\n        G.add_directed_edge(s, t, d);\r\n  \
    \  }\r\n\r\n    const auto INF = std::numeric_limits<int>::max();\r\n    auto\
    \ ret = G.bellman_ford(r);\r\n    if(ret.empty()) std::cout << \"NEGATIVE CYCLE\"\
    \ << '\\n';\r\n    else{\r\n        for(auto r : ret){\r\n            if(r ==\
    \ INF) std::cout << \"INF\" << '\\n';\r\n            else std::cout << r << '\\\
    n';\r\n        }\r\n    }\r\n\r\n    return 0;\r\n}"
  dependsOn:
  - snow/graph/shortest-path/bellman-ford.hpp
  - snow/graph/graph.hpp
  isVerificationFile: true
  path: test/aoj/bellman-ford.test.cpp
  requiredBy: []
  timestamp: '2021-03-19 19:13:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/bellman-ford.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/bellman-ford.test.cpp
- /verify/test/aoj/bellman-ford.test.cpp.html
title: test/aoj/bellman-ford.test.cpp
---
