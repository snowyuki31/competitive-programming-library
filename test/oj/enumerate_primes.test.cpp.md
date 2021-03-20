---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  - icon: ':x:'
    path: snow/math/simple-sieve.hpp
    title: snow/math/simple-sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/oj/enumerate_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <iostream>\n#line\
    \ 2 \"snow/math/simple-sieve.hpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n\nnamespace snow {\n\nstruct simple_sieve {\n    public:\n\
    \        simple_sieve(int n) : _n(n + 1), prime(_n, true) {\n            if(n\
    \ >= 0) prime[0] = false;\n            if(n >= 1) prime[1] = false;\n        \
    \    for(int i = 2; i * i <= n; ++i) if(prime[i]) {\n                for (int\
    \ j = i * i; j <= n; j += i) prime[j] = false;\n            }\n        }\n\n \
    \       bool isprime(int n){\n            return !!prime[n];\n        }\n\n  \
    \      std::vector<int> enumerate_prime() {\n            std::vector<int> prime_list;\n\
    \            prime_list.reserve(std::count(prime.begin(), prime.end(), true));\n\
    \            for(int i = 0; i < prime.size(); ++i) if(prime[i]) prime_list.emplace_back(i);\n\
    \            return prime_list;\n        }\n\n    protected:\n        int _n;\n\
    \        std::vector<bool> prime;\n};\n\n} // namespace snow\n#line 4 \"snow/io/helper.hpp\"\
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
    \ : \"\");\n    return os;\n}\n#line 6 \"test/oj/enumerate_primes.test.cpp\"\n\
    \nint main() {\n    int N, A, B;\n    std::cin >> N >> A >> B;\n\n    snow::simple_sieve\
    \ sieve(N);\n    auto ret = sieve.enumerate_prime();\n    \n    std::vector<int>\
    \ ans;\n    for(int i = B; i < ret.size(); i += A){\n        ans.emplace_back(ret[i]);\n\
    \    }\n\n    std::cout << ret.size() << ' ' << ans.size() << '\\n';\n    std::cout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include \"snow/math/simple-sieve.hpp\"\n#include \"snow/io/helper.hpp\"\
    \n\nint main() {\n    int N, A, B;\n    std::cin >> N >> A >> B;\n\n    snow::simple_sieve\
    \ sieve(N);\n    auto ret = sieve.enumerate_prime();\n    \n    std::vector<int>\
    \ ans;\n    for(int i = B; i < ret.size(); i += A){\n        ans.emplace_back(ret[i]);\n\
    \    }\n\n    std::cout << ret.size() << ' ' << ans.size() << '\\n';\n    std::cout\
    \ << ans << '\\n';\n}"
  dependsOn:
  - snow/math/simple-sieve.hpp
  - snow/io/helper.hpp
  isVerificationFile: true
  path: test/oj/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2021-03-20 19:23:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/oj/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/oj/enumerate_primes.test.cpp
- /verify/test/oj/enumerate_primes.test.cpp.html
title: test/oj/enumerate_primes.test.cpp
---