---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/datastructure/weighted-unionfind.hpp
    title: snow/datastructure/weighted-unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <iostream>\n#line 2 \"snow/datastructure/weighted-unionfind.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace snow\
    \ {\n\n// Based on ac-library implementation\ntemplate < typename Abel = int >\n\
    struct WeightedUnionFind {\n  public:\n    WeightedUnionFind() : _n(0) {}\n  \
    \  explicit WeightedUnionFind(int n, Abel e = 0) : _n(n), parent_or_size(n, -1),\
    \ diff_weight(n, e) {}\n\n    bool merge(int a, int b, Abel w) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        w += weight(a),\
    \ w -= weight(b);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return false;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y), w *= -1;\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        diff_weight[y] = w;\n        return true;\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        int r = leader(parent_or_size[a]);\n        diff_weight[a] += diff_weight[parent_or_size[a]];\n\
    \        return parent_or_size[a] = r;\n    }\n\n    int size(int a) {\n     \
    \   assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n  \
    \  }\n\n    Abel weight(int a){\n        leader(a);\n        return diff_weight[a];\n\
    \    }\n\n    Abel diff(int a, int b){\n        return weight(b) - weight(a);\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n    std::vector<Abel> diff_weight;\n\
    };\n\n}  // namespace snow\n#line 5 \"test/aoj/DSL_1_B.test.cpp\"\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n\n    snow::WeightedUnionFind<int>\
    \ wuf(n, 0);\n\n    while(q--){\n        int t;\n        std::cin >> t;\n\n  \
    \      if(t == 0){\n            int x, y, z;\n            std::cin >> x >> y >>\
    \ z;\n            wuf.merge(x, y, z);\n        }\n        else{\n            int\
    \ x, y;\n            std::cin >> x >> y;\n            if(!wuf.same(x, y)) std::cout\
    \ << '?' << '\\n';\n            else std::cout << wuf.diff(x, y) << '\\n';\n \
    \       }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <iostream>\n#include \"snow/datastructure/weighted-unionfind.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    snow::WeightedUnionFind<int>\
    \ wuf(n, 0);\n\n    while(q--){\n        int t;\n        std::cin >> t;\n\n  \
    \      if(t == 0){\n            int x, y, z;\n            std::cin >> x >> y >>\
    \ z;\n            wuf.merge(x, y, z);\n        }\n        else{\n            int\
    \ x, y;\n            std::cin >> x >> y;\n            if(!wuf.same(x, y)) std::cout\
    \ << '?' << '\\n';\n            else std::cout << wuf.diff(x, y) << '\\n';\n \
    \       }\n    }\n\n    return 0;\n}"
  dependsOn:
  - snow/datastructure/weighted-unionfind.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-03-20 06:10:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---
