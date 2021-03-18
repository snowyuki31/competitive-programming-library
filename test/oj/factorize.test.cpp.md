---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/factorize.hpp
    title: src/math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/oj/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#include<iostream>\r\n\r\n#include<src/math/factorize.hpp>\r\n\r\nint\
    \ main(){\r\n    int Q;\r\n    std::cin >> Q;\r\n    while(Q--){\r\n        long\
    \ long a;\r\n        std::cin >> a;\r\n        auto ret = snow::factorize(a);\r\
    \n        std::cout << ret.size();\r\n        for(auto [k, v] : ret) std::cout\
    \ << ' ' << k;\r\n        std::cout << '\\n';\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include<iostream>\r\
    \n\r\n#include<src/math/factorize.hpp>\r\n\r\nint main(){\r\n    int Q;\r\n  \
    \  std::cin >> Q;\r\n    while(Q--){\r\n        long long a;\r\n        std::cin\
    \ >> a;\r\n        auto ret = snow::factorize(a);\r\n        std::cout << ret.size();\r\
    \n        for(auto [k, v] : ret) std::cout << ' ' << k;\r\n        std::cout <<\
    \ '\\n';\r\n    }\r\n}\r\n"
  dependsOn:
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/oj/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-03-19 07:19:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/oj/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/oj/factorize.test.cpp
- /verify/test/oj/factorize.test.cpp.html
title: test/oj/factorize.test.cpp
---
