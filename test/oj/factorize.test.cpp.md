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
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"src/math/factorize.hpp\"\n\r\n#include<map>\r\
    \n\r\nnamespace snow {\r\n\r\ntemplate<typename T>\r\nstd::map<T, int> factorize(T\
    \ v){\r\n    std::map<T, int> ret;\r\n    for(T i = 2; i * i <= v; ++i){\r\n \
    \       while(!(v % i)) ret[i]++, v /= i;\r\n    }\r\n    if(v != 1) ret[v]++;\r\
    \n    return ret;\r\n}\r\n\r\n} // namespace snow\n#line 6 \"test/oj/factorize.test.cpp\"\
    \n\r\nint main(){\r\n    int Q;\r\n    std::cin >> Q;\r\n    while(Q--){\r\n \
    \       long long a;\r\n        std::cin >> a;\r\n        auto ret = snow::factorize(a);\r\
    \n        \r\n        int counter = 0;\r\n        for(auto [k, v] : ret) counter\
    \ += v;\r\n        std::cout << counter;\r\n\r\n        for(auto [k, v] : ret){\r\
    \n            while(v--) std::cout << ' ' << k;\r\n        }\r\n        std::cout\
    \ << '\\n';\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"src/math/factorize.hpp\"\r\n\r\nint main(){\r\n\
    \    int Q;\r\n    std::cin >> Q;\r\n    while(Q--){\r\n        long long a;\r\
    \n        std::cin >> a;\r\n        auto ret = snow::factorize(a);\r\n       \
    \ \r\n        int counter = 0;\r\n        for(auto [k, v] : ret) counter += v;\r\
    \n        std::cout << counter;\r\n\r\n        for(auto [k, v] : ret){\r\n   \
    \         while(v--) std::cout << ' ' << k;\r\n        }\r\n        std::cout\
    \ << '\\n';\r\n    }\r\n}\r\n"
  dependsOn:
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/oj/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-03-19 07:58:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/oj/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/oj/factorize.test.cpp
- /verify/test/oj/factorize.test.cpp.html
title: test/oj/factorize.test.cpp
---
