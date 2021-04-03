---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/graph/shortest-path/warshall-floyd.hpp
    title: Warshall-Floyd
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    document_title: Warshall-Floyd (with Negative Cycle Detection)
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n\n#line 2 \"snow/graph/shortest-path/warshall-floyd.hpp\"\
    \n\n#include <vector>\n\n#line 2 \"snow/graph/template.hpp\"\n\r\n#line 4 \"snow/graph/template.hpp\"\
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
    \n};\r\n\r\n} // namespace snow\n#line 6 \"snow/graph/shortest-path/warshall-floyd.hpp\"\
    \n\nnamespace snow{\n\n/**\n * @brief Warshall-Floyd\n * \n * @tparam T \n */\n\
    template < typename T >\nstd::vector<std::vector<T>> Graph<T>::warshall_floyd()\
    \ const{\n    int N = G.size();\n    std::vector<std::vector<T>> d(N, std::vector<T>(N,\
    \ INF));\n    \n    for(int i = 0; i < N; ++i) d[i][i] = 0;\n\n    for(int i =\
    \ 0; i < N; ++i) for(auto &e : G[i]) d[i][e.to] = e.weight;\n\n    for(int k =\
    \ 0; k < N; ++k){\n        for(int i = 0; i < N; ++i){\n            for(int j\
    \ = 0; j < N; ++j){\n                if(d[i][k] == INF or d[k][j] == INF) continue;\n\
    \n                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);\n          \
    \  }\n        }\n    }\n    return d;\n \n}\n\n}\n#line 6 \"test/aoj/GRL_1_C.test.cpp\"\
    \n\n/**\n * @brief Warshall-Floyd (with Negative Cycle Detection)\n * \n */\n\
    int main(){\n    int V, E;\n    std::cin >> V >> E;\n\n    snow::Graph<int> G(V);\n\
    \    \n    while(E--){\n        int s, t, d;\n        std::cin >> s >> t >> d;\n\
    \        G.add_directed_edge(s, t, d);\n    }\n\n    auto ret = G.warshall_floyd();\n\
    \n    for(int i = 0; i < V; ++i){\n        if(ret[i][i] < 0){\n            std::cout\
    \ << \"NEGATIVE CYCLE\" << '\\n';\n            return 0;\n        }\n    }\n\n\
    \    for(int i = 0; i < V; ++i){\n        for(int j = 0; j < V; ++j){\n      \
    \      if(j > 0) std::cout << ' ';\n            if(ret[i][j] == G.INF) std::cout\
    \ << \"INF\";\n            else std::cout << ret[i][j];\n        }\n        std::cout\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n\n#include \"snow/graph/shortest-path/warshall-floyd.hpp\"\
    \n\n/**\n * @brief Warshall-Floyd (with Negative Cycle Detection)\n * \n */\n\
    int main(){\n    int V, E;\n    std::cin >> V >> E;\n\n    snow::Graph<int> G(V);\n\
    \    \n    while(E--){\n        int s, t, d;\n        std::cin >> s >> t >> d;\n\
    \        G.add_directed_edge(s, t, d);\n    }\n\n    auto ret = G.warshall_floyd();\n\
    \n    for(int i = 0; i < V; ++i){\n        if(ret[i][i] < 0){\n            std::cout\
    \ << \"NEGATIVE CYCLE\" << '\\n';\n            return 0;\n        }\n    }\n\n\
    \    for(int i = 0; i < V; ++i){\n        for(int j = 0; j < V; ++j){\n      \
    \      if(j > 0) std::cout << ' ';\n            if(ret[i][j] == G.INF) std::cout\
    \ << \"INF\";\n            else std::cout << ret[i][j];\n        }\n        std::cout\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - snow/graph/shortest-path/warshall-floyd.hpp
  - snow/graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 03:29:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: Warshall-Floyd (with Negative Cycle Detection)
---
