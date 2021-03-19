---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/factorize.hpp
    title: src/math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/aoj/factorize_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"src/math/factorize.hpp\"\n\r\n#include\
    \ <map>\r\n\r\nnamespace snow {\r\n\r\ntemplate <typename T>\r\nstd::map<T, int>\
    \ factorize(T v){\r\n    std::map<T, int> ret;\r\n    for(T i = 2; i * i <= v;\
    \ ++i){\r\n        while(!(v % i)) ret[i]++, v /= i;\r\n    }\r\n    if(v != 1)\
    \ ret[v]++;\r\n    return ret;\r\n}\r\n\r\n} // namespace snow\n#line 6 \"test/aoj/factorize_a.test.cpp\"\
    \n\r\nint main(){\r\n    int n;\r\n    std::cin >> n;\r\n    auto ret = snow::factorize(n);\r\
    \n    std::cout << n << ':';\r\n    for(auto [k, v] : ret){\r\n        while(v--)\
    \ std::cout << ' ' << k;\r\n    }\r\n    std::cout << '\\n';\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"src/math/factorize.hpp\"\r\n\r\n\
    int main(){\r\n    int n;\r\n    std::cin >> n;\r\n    auto ret = snow::factorize(n);\r\
    \n    std::cout << n << ':';\r\n    for(auto [k, v] : ret){\r\n        while(v--)\
    \ std::cout << ' ' << k;\r\n    }\r\n    std::cout << '\\n';\r\n}\r\n"
  dependsOn:
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/aoj/factorize_a.test.cpp
  requiredBy: []
  timestamp: '2021-03-19 09:17:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/factorize_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/factorize_a.test.cpp
- /verify/test/aoj/factorize_a.test.cpp.html
title: test/aoj/factorize_a.test.cpp
---
