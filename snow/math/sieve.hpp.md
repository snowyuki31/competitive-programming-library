---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/oj/enumerate_primes.cpp
    title: test/oj/enumerate_primes.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/math/sieve.hpp\"\n\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n#include <map>\n\nnamespace snow {\n\nstruct sieve\
    \ {\n    std::vector<int> _sieve;\n\n    sieve(int n) : _sieve(++n){\n       \
    \ std::iota(_sieve.begin(), _sieve.end(), 0);\n        for(int i = 2; i * i <\
    \ n; ++i){\n            if(_sieve[i] < i) continue;\n            for(int j = i\
    \ * i; j < n; j += i) if(_sieve[j] == j) _sieve[j] = i;\n        }\n    };\n\n\
    \    std::map<int, int> factorize(int n){\n        std::map<int, int> res;\n \
    \       while(n != 1){\n            res[_sieve[n]]++;\n            n /= _sieve[n];\n\
    \        }\n        return res;\n    };\n\n    std::vector<int> divisor(int n){\n\
    \        std::map<int, int> pf = factorize(n);\n        std::vector<std::pair<int,\
    \ int>> p;\n        for(auto& [k, v] : pf) p.emplace_back(k, v);\n\n        std::vector<int>\
    \ res;\n        auto culc = [&](auto &&self, int val, int ct)->void{\n       \
    \     if(ct == p.size()){\n                res.emplace_back(val);\n          \
    \      return;\n            }\n            auto [prime, num] = p[ct];\n      \
    \      int tmp = 1;\n            for(int _ = 0; _ < num + 1; ++_){\n         \
    \       self(self, val * tmp, ct + 1);\n                tmp *= prime;\n      \
    \      }\n        };\n        culc(culc, 1, 0);\n        //sort(ALL(res));\n \
    \       return res;\n    };\n\n    std::vector<int> enumerate_prime() {\n    \
    \    std::vector<int> primes;\n        for(int i = 2; i < _sieve.size(); ++i)\
    \ {\n            if(_sieve[i] == i) primes.emplace_back(i);\n        }\n     \
    \   return primes;\n    }\n};\n\n} // namespace snow\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    #include <map>\n\nnamespace snow {\n\nstruct sieve {\n    std::vector<int> _sieve;\n\
    \n    sieve(int n) : _sieve(++n){\n        std::iota(_sieve.begin(), _sieve.end(),\
    \ 0);\n        for(int i = 2; i * i < n; ++i){\n            if(_sieve[i] < i)\
    \ continue;\n            for(int j = i * i; j < n; j += i) if(_sieve[j] == j)\
    \ _sieve[j] = i;\n        }\n    };\n\n    std::map<int, int> factorize(int n){\n\
    \        std::map<int, int> res;\n        while(n != 1){\n            res[_sieve[n]]++;\n\
    \            n /= _sieve[n];\n        }\n        return res;\n    };\n\n    std::vector<int>\
    \ divisor(int n){\n        std::map<int, int> pf = factorize(n);\n        std::vector<std::pair<int,\
    \ int>> p;\n        for(auto& [k, v] : pf) p.emplace_back(k, v);\n\n        std::vector<int>\
    \ res;\n        auto culc = [&](auto &&self, int val, int ct)->void{\n       \
    \     if(ct == p.size()){\n                res.emplace_back(val);\n          \
    \      return;\n            }\n            auto [prime, num] = p[ct];\n      \
    \      int tmp = 1;\n            for(int _ = 0; _ < num + 1; ++_){\n         \
    \       self(self, val * tmp, ct + 1);\n                tmp *= prime;\n      \
    \      }\n        };\n        culc(culc, 1, 0);\n        //sort(ALL(res));\n \
    \       return res;\n    };\n\n    std::vector<int> enumerate_prime() {\n    \
    \    std::vector<int> primes;\n        for(int i = 2; i < _sieve.size(); ++i)\
    \ {\n            if(_sieve[i] == i) primes.emplace_back(i);\n        }\n     \
    \   return primes;\n    }\n};\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/math/sieve.hpp
  requiredBy:
  - test/oj/enumerate_primes.cpp
  timestamp: '2021-03-20 08:17:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/math/sieve.hpp
layout: document
title: Sieve of Eratosthenes
---

