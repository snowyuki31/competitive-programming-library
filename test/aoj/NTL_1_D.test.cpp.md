---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/math/euler-phi.hpp
    title: snow/math/euler-phi.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: Euler's totient function
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"snow/math/euler-phi.hpp\"\n\r\nnamespace\
    \ snow {\r\n\r\ntemplate < typename T >\r\nT euler_phi(T n) {\r\n   T ret = n;\r\
    \n   for(T i = 2; i * i <= n; ++i){\r\n       if(n % i == 0) {\r\n           ret\
    \ -= ret / i;\r\n           while(n % i == 0) n /= i;\r\n       }\r\n   }\r\n\
    \   if(n > 1) ret -= ret / n;\r\n   return ret;\r\n}\r\n\r\n} // namespace snow\n\
    #line 6 \"test/aoj/NTL_1_D.test.cpp\"\n\r\n/**\r\n * @brief Euler's totient function\r\
    \n * \r\n */\r\nint main(){\r\n    int n;\r\n    std::cin >> n;\r\n    \r\n  \
    \  std::cout << snow::euler_phi(n) << '\\n';\r\n\r\n    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"snow/math/euler-phi.hpp\"\r\n\r\n\
    /**\r\n * @brief Euler's totient function\r\n * \r\n */\r\nint main(){\r\n   \
    \ int n;\r\n    std::cin >> n;\r\n    \r\n    std::cout << snow::euler_phi(n)\
    \ << '\\n';\r\n\r\n    return 0;\r\n}\r\n"
  dependsOn:
  - snow/math/euler-phi.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2021-03-22 12:08:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: Euler's totient function
---
