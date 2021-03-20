---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/math/sieve.hpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#line 2 \"snow/math/sieve.hpp\"\n\n#include <algorithm>\n\
    #include <numeric>\n#include <vector>\n#include <map>\n\nnamespace snow {\n\n\
    struct sieve {\n    public:\n        sieve(int n) : n(n + 1), _sieve(n + 1){\n\
    \            std::iota(_sieve.begin(), _sieve.end(), 0);\n            for(int\
    \ i = 2; i * i < n; ++i){\n                if(_sieve[i] < i) continue;\n     \
    \           for(int j = i * i; j < n; j += i) if(_sieve[j] == j) _sieve[j] = i;\n\
    \            }\n        }\n\n        std::map<int, int> factorize(int n){\n  \
    \          std::map<int, int> res;\n            while(n != 1){\n             \
    \   res[_sieve[n]]++;\n                n /= _sieve[n];\n            }\n      \
    \      return res;\n        }\n\n        std::vector<int> enumerate_prime() {\n\
    \            std::vector<int> primes;\n            for(int i = 2; i < _sieve.size();\
    \ ++i) {\n                if(_sieve[i] == i) primes.emplace_back(i);\n       \
    \     }\n            return primes;\n        }\n\n        bool isprime(int n){\n\
    \            return _sieve[n] == n;\n        }\n\n    protected:\n        std::vector<int>\
    \ _sieve;\n        int n;\n};\n\n} // namespace snow\n#line 5 \"test/aoj/ALDS1_1_C.test.cpp\"\
    \n\nint main() {\n    snow::sieve sieve(1e8);\n\n    int N;\n    std::cin >> N;\n\
    \    int ret = 0;\n    while(N--) {\n        int q;\n        std::cin >> q;\n\
    \        ret += sieve.isprime(q);\n    }\n    std::cout << ret << '\\n';\n   \
    \ \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#include \"snow/math/sieve.hpp\"\n\nint main() {\n  \
    \  snow::sieve sieve(1e8);\n\n    int N;\n    std::cin >> N;\n    int ret = 0;\n\
    \    while(N--) {\n        int q;\n        std::cin >> q;\n        ret += sieve.isprime(q);\n\
    \    }\n    std::cout << ret << '\\n';\n    \n    return 0;\n}"
  dependsOn:
  - snow/math/sieve.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-03-20 20:11:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C.test.cpp
- /verify/test/aoj/ALDS1_1_C.test.cpp.html
title: test/aoj/ALDS1_1_C.test.cpp
---
