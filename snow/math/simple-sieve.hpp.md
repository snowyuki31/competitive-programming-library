---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/oj/enumerate_primes.test.cpp
    title: test/oj/enumerate_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/simple-sieve.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <numeric>\n\nnamespace snow {\n\nstruct simple_sieve {\n\
    \    public:\n        simple_sieve(int n) : _n(n + 1), prime(_n, true) {\n   \
    \         if(n >= 0) prime[0] = false;\n            if(n >= 1) prime[1] = false;\n\
    \            for(int i = 2; i * i <= n; ++i) if(prime[i]) {\n                for\
    \ (int j = i * i; j <= n; j += i) prime[j] = false;\n            }\n        }\n\
    \n        bool isprime(int n){\n            return !!prime[n];\n        }\n\n\
    \        std::vector<int> enumerate_prime() {\n            std::vector<int> prime_list;\n\
    \            prime_list.reserve(std::count(prime.begin(), prime.end(), true));\n\
    \            for(int i = 0; i < prime.size(); ++i) if(prime[i]) prime_list.emplace_back(i);\n\
    \            return prime_list;\n        }\n\n    protected:\n        int _n;\n\
    \        std::vector<bool> prime;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    \nnamespace snow {\n\nstruct simple_sieve {\n    public:\n        simple_sieve(int\
    \ n) : _n(n + 1), prime(_n, true) {\n            if(n >= 0) prime[0] = false;\n\
    \            if(n >= 1) prime[1] = false;\n            for(int i = 2; i * i <=\
    \ n; ++i) if(prime[i]) {\n                for (int j = i * i; j <= n; j += i)\
    \ prime[j] = false;\n            }\n        }\n\n        bool isprime(int n){\n\
    \            return !!prime[n];\n        }\n\n        std::vector<int> enumerate_prime()\
    \ {\n            std::vector<int> prime_list;\n            prime_list.reserve(std::count(prime.begin(),\
    \ prime.end(), true));\n            for(int i = 0; i < prime.size(); ++i) if(prime[i])\
    \ prime_list.emplace_back(i);\n            return prime_list;\n        }\n\n \
    \   protected:\n        int _n;\n        std::vector<bool> prime;\n};\n\n} //\
    \ namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/simple-sieve.hpp
  requiredBy: []
  timestamp: '2021-03-20 19:23:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/oj/enumerate_primes.test.cpp
documentation_of: snow/math/simple-sieve.hpp
layout: document
redirect_from:
- /library/snow/math/simple-sieve.hpp
- /library/snow/math/simple-sieve.hpp.html
title: snow/math/simple-sieve.hpp
---
