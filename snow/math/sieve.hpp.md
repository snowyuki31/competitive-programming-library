---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/sieve.hpp\"\n\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n#include <map>\n\nnamespace snow {\n\nstruct sieve\
    \ {\n    public:\n        sieve(int n) : _n(n + 1), _sieve(_n){\n            std::iota(_sieve.begin(),\
    \ _sieve.end(), 0);\n            for(int i = 2; i * i <= n; ++i){\n          \
    \      if(_sieve[i] < i) continue;\n                for(int j = i * i; j <= n;\
    \ j += i) if(_sieve[j] == j) _sieve[j] = i;\n            }\n        }\n\n    \
    \    std::map<int, int> factorize(int n){\n            std::map<int, int> res;\n\
    \            while(n != 1){\n                res[_sieve[n]]++;\n             \
    \   n /= _sieve[n];\n            }\n            return res;\n        }\n\n   \
    \     std::vector<int> enumerate_prime() {\n            std::vector<int> primes;\n\
    \            for(int i = 2; i < _sieve.size(); ++i) {\n                if(_sieve[i]\
    \ == i) primes.emplace_back(i);\n            }\n            return primes;\n \
    \       }\n\n        bool isprime(int n){\n            return _sieve[n] == n;\n\
    \        }\n\n    protected:\n        int _n;\n        std::vector<int> _sieve;\n\
    };\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    #include <map>\n\nnamespace snow {\n\nstruct sieve {\n    public:\n        sieve(int\
    \ n) : _n(n + 1), _sieve(_n){\n            std::iota(_sieve.begin(), _sieve.end(),\
    \ 0);\n            for(int i = 2; i * i <= n; ++i){\n                if(_sieve[i]\
    \ < i) continue;\n                for(int j = i * i; j <= n; j += i) if(_sieve[j]\
    \ == j) _sieve[j] = i;\n            }\n        }\n\n        std::map<int, int>\
    \ factorize(int n){\n            std::map<int, int> res;\n            while(n\
    \ != 1){\n                res[_sieve[n]]++;\n                n /= _sieve[n];\n\
    \            }\n            return res;\n        }\n\n        std::vector<int>\
    \ enumerate_prime() {\n            std::vector<int> primes;\n            for(int\
    \ i = 2; i < _sieve.size(); ++i) {\n                if(_sieve[i] == i) primes.emplace_back(i);\n\
    \            }\n            return primes;\n        }\n\n        bool isprime(int\
    \ n){\n            return _sieve[n] == n;\n        }\n\n    protected:\n     \
    \   int _n;\n        std::vector<int> _sieve;\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/sieve.hpp
  requiredBy: []
  timestamp: '2021-03-20 20:23:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/math/sieve.hpp
layout: document
title: Sieve of Eratosthenes
---

