---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  - icon: ':warning:'
    path: snow/math/sieve.hpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/oj/enumerate_primes.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \n\n#include <iostream>\n#line 2 \"snow/math/sieve.hpp\"\n\n#include <algorithm>\n\
    #include <numeric>\n#include <vector>\n#include <map>\n\nnamespace snow {\n\n\
    struct sieve {\n    std::vector<int> _sieve;\n\n    sieve(int n) : _sieve(++n){\n\
    \        std::iota(_sieve.begin(), _sieve.end(), 0);\n        for(int i = 2; i\
    \ * i < n; ++i){\n            if(_sieve[i] < i) continue;\n            for(int\
    \ j = i * i; j < n; j += i) if(_sieve[j] == j) _sieve[j] = i;\n        }\n   \
    \ };\n\n    std::map<int, int> factorize(int n){\n        std::map<int, int> res;\n\
    \        while(n != 1){\n            res[_sieve[n]]++;\n            n /= _sieve[n];\n\
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
    \   return primes;\n    }\n};\n\n} // namespace snow\n#line 4 \"snow/io/helper.hpp\"\
    \n#include <set>\n\ntemplate< typename T1, typename T2 >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::pair< T1, T2 > &p) {\n    os << p.first <<\
    \ \" \" << p.second;\n    return os;\n}\n\ntemplate< typename T1, typename T2\
    \ >\nstd::istream &operator >> (std::istream &is, std::pair< T1, T2 > &p) {\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate< typename T1, typename\
    \ T2, typename T3 >\nstd::ostream &operator << (std::ostream &os, const std::tuple<\
    \ T1, T2, T3 > &t) {\n    auto &[a, b, c] = t;\n    os << a << \" \" << b << \"\
    \ \" << c;\n    return os;\n}\n\ntemplate< typename T1, typename T2, typename\
    \ T3 >\nstd::istream &operator >> (std::istream &is, std::tuple< T1, T2, T3 >\
    \ &t) {\n    auto &[a, b, c] = t;\n    is >> a >> b >> c;\n    return is;\n}\n\
    \ntemplate< typename T >\nstd::ostream &operator << (std::ostream &os, const std::vector<\
    \ T > &v){\n    for (int i = 0; i < (int)v.size(); ++i) {\n        os << v[i]\
    \ << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate<\
    \ typename T >\nstd::istream &operator >>  (std::istream &is, std::vector< T >\
    \ &v){\n    for(T &in : v) is >> in;\n    return is;\n}\n\ntemplate< typename\
    \ T >\nstd::ostream &operator << (std::ostream &os, const std::set< T > &st){\n\
    \    int ct = 0;\n    for(auto& s : st) os << s << (++ct != st.size() ? \" \"\
    \ : \"\");\n    return os;\n}\n#line 6 \"test/oj/enumerate_primes.cpp\"\n\nint\
    \ main() {\n    int N, A, B;\n    std::cin >> N >> A >> B;\n\n    snow::sieve\
    \ sieve(N);\n    auto ret = sieve.enumerate_prime();\n    std::vector<int> ans;\n\
    \    for(int i = B; i < ret.size(); i += A){\n        ans.emplace_back(ret[i]);\n\
    \    }\n\n    std::cout << ret.size() << ' ' << ans.size() << '\\n';\n    std::cout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include \"snow/math/sieve.hpp\"\n#include \"snow/io/helper.hpp\"\
    \n\nint main() {\n    int N, A, B;\n    std::cin >> N >> A >> B;\n\n    snow::sieve\
    \ sieve(N);\n    auto ret = sieve.enumerate_prime();\n    std::vector<int> ans;\n\
    \    for(int i = B; i < ret.size(); i += A){\n        ans.emplace_back(ret[i]);\n\
    \    }\n\n    std::cout << ret.size() << ' ' << ans.size() << '\\n';\n    std::cout\
    \ << ans << '\\n';\n}"
  dependsOn:
  - snow/math/sieve.hpp
  - snow/io/helper.hpp
  isVerificationFile: false
  path: test/oj/enumerate_primes.cpp
  requiredBy: []
  timestamp: '2021-03-20 08:17:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/oj/enumerate_primes.cpp
layout: document
redirect_from:
- /library/test/oj/enumerate_primes.cpp
- /library/test/oj/enumerate_primes.cpp.html
title: test/oj/enumerate_primes.cpp
---
