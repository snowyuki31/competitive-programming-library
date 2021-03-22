---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/math/simple-sieve.hpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    document_title: Eratosthenes's sieve (upto 1e8)
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#line 2 \"snow/math/simple-sieve.hpp\"\n\n#include <vector>\n\
    #include <algorithm>\n#include <numeric>\n\nnamespace snow {\n\nstruct simple_sieve\
    \ {\n    public:\n        simple_sieve(int n) : _n(n + 1), prime(_n, true) {\n\
    \            if(n >= 0) prime[0] = false;\n            if(n >= 1) prime[1] = false;\n\
    \            for(int i = 2; i * i <= n; ++i) if(prime[i]) {\n                for\
    \ (int j = i * i; j <= n; j += i) prime[j] = false;\n            }\n        }\n\
    \n        bool isprime(int x){\n            return !!prime[x];\n        }\n\n\
    \        std::vector<int> enumerate_primes() {\n            std::vector<int> prime_list;\n\
    \            prime_list.reserve(std::count(prime.begin(), prime.end(), true));\n\
    \            for(int i = 0; i < prime.size(); ++i) if(prime[i]) prime_list.emplace_back(i);\n\
    \            return prime_list;\n        }\n\n    protected:\n        int _n;\n\
    \        std::vector<bool> prime;\n};\n\n} // namespace snow\n#line 5 \"test/aoj/ALDS1_1_C.test.cpp\"\
    \n\n/**\n * @brief Eratosthenes's sieve (upto 1e8)\n * \n */\nint main() {\n \
    \   snow::simple_sieve sieve(1e8);\n\n    int N;\n    std::cin >> N;\n    int\
    \ ret = 0;\n    while(N--) {\n        int q;\n        std::cin >> q;\n       \
    \ ret += sieve.isprime(q);\n    }\n    std::cout << ret << '\\n';\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#include \"snow/math/simple-sieve.hpp\"\n\n/**\n * @brief\
    \ Eratosthenes's sieve (upto 1e8)\n * \n */\nint main() {\n    snow::simple_sieve\
    \ sieve(1e8);\n\n    int N;\n    std::cin >> N;\n    int ret = 0;\n    while(N--)\
    \ {\n        int q;\n        std::cin >> q;\n        ret += sieve.isprime(q);\n\
    \    }\n    std::cout << ret << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - snow/math/simple-sieve.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-03-22 12:08:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C.test.cpp
- /verify/test/aoj/ALDS1_1_C.test.cpp.html
title: Eratosthenes's sieve (upto 1e8)
---
