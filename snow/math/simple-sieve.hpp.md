---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/oj/enumerate_primes.cpp
    title: test/oj/enumerate_primes.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.test.cpp
    title: test/aoj/ALDS1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/simple-sieve.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <numeric>\n\nnamespace snow {\n\nstruct simple_sieve {\n\
    \    public:\n        simple_sieve(int n) : _n(n + 1), prime(_n, true) {\n   \
    \         if(n >= 0) prime[0] = false;\n            if(n >= 1) prime[1] = false;\n\
    \            for(int i = 2; i * i <= n; ++i) if(prime[i]) {\n                for\
    \ (int j = i * i; j <= n; j += i) prime[j] = false;\n            }\n        }\n\
    \n        bool isprime(int x){\n            return !!prime[x];\n        }\n\n\
    \        std::vector<int> enumerate_primes() {\n            std::vector<int> prime_list;\n\
    \            prime_list.reserve(std::count(prime.begin(), prime.end(), true));\n\
    \            for(int i = 0; i < prime.size(); ++i) if(prime[i]) prime_list.emplace_back(i);\n\
    \            return prime_list;\n        }\n\n    protected:\n        int _n;\n\
    \        std::vector<bool> prime;\n};\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    \nnamespace snow {\n\nstruct simple_sieve {\n    public:\n        simple_sieve(int\
    \ n) : _n(n + 1), prime(_n, true) {\n            if(n >= 0) prime[0] = false;\n\
    \            if(n >= 1) prime[1] = false;\n            for(int i = 2; i * i <=\
    \ n; ++i) if(prime[i]) {\n                for (int j = i * i; j <= n; j += i)\
    \ prime[j] = false;\n            }\n        }\n\n        bool isprime(int x){\n\
    \            return !!prime[x];\n        }\n\n        std::vector<int> enumerate_primes()\
    \ {\n            std::vector<int> prime_list;\n            prime_list.reserve(std::count(prime.begin(),\
    \ prime.end(), true));\n            for(int i = 0; i < prime.size(); ++i) if(prime[i])\
    \ prime_list.emplace_back(i);\n            return prime_list;\n        }\n\n \
    \   protected:\n        int _n;\n        std::vector<bool> prime;\n};\n\n} //\
    \ namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/simple-sieve.hpp
  requiredBy:
  - test/oj/enumerate_primes.cpp
  timestamp: '2021-03-21 02:00:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.test.cpp
documentation_of: snow/math/simple-sieve.hpp
layout: document
title: Sieve of Eratosthenes
---

## About

エラトステネスの篩．

## How to

```simple_sieve sieve(n)``` : 前処理$O(n\log\log n)$

```bool sieve.isprime(x)``` : $x$が素数かどうかを返す

```vector<int> sieve.enumerate_primes()``` : 素数列挙