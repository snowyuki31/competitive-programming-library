---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  - icon: ':heavy_check_mark:'
    path: snow/io/setup.hpp
    title: snow/io/setup.hpp
  - icon: ':heavy_check_mark:'
    path: snow/math/simple-sieve.hpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate Primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/oj/enumerate_primes.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
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
    \        std::vector<bool> prime;\n};\n\n} // namespace snow\n#line 3 \"snow/io/setup.hpp\"\
    \n#include <iomanip>\n\nnamespace snow{\n\nstruct IoSetup {\n    IoSetup() {\n\
    \        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n \
    \       std::cout << std::fixed << std::setprecision(10);\n    }\n} iosetup;\n\
    \n}\n#line 4 \"snow/io/helper.hpp\"\n#include <set>\n\ntemplate< typename T1,\
    \ typename T2 >\nstd::ostream &operator << (std::ostream &os, const std::pair<\
    \ T1, T2 > &p) {\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\
    \ntemplate< typename T1, typename T2 >\nstd::istream &operator >> (std::istream\
    \ &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b,\
    \ c] = t;\n    os << a << \" \" << b << \" \" << c;\n    return os;\n}\n\ntemplate<\
    \ typename T1, typename T2, typename T3 >\nstd::istream &operator >> (std::istream\
    \ &is, std::tuple< T1, T2, T3 > &t) {\n    auto &[a, b, c] = t;\n    is >> a >>\
    \ b >> c;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::vector< T > &v){\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n \
    \   return os;\n}\n\ntemplate< typename T >\nstd::istream &operator >>  (std::istream\
    \ &is, std::vector< T > &v){\n    for(T &in : v) is >> in;\n    return is;\n}\n\
    \ntemplate< typename T >\nstd::ostream &operator << (std::ostream &os, const std::set<\
    \ T > &st){\n    int ct = 0;\n    for(auto& s : st) os << s << (++ct != st.size()\
    \ ? \" \" : \"\");\n    return os;\n}\n\ntemplate<class... T>\nvoid input(T&...\
    \ a){\n    (std::cin >> ... >> a);\n}\n\nvoid print() {\n    std::cout << '\\\
    n';\n}\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n\
    \    std::cout << a;\n    (std::cout << ... << (std::cout << ' ', b));\n    std::cout\
    \ << '\\n';\n}\n\nint drop() {\n    std::cout << '\\n';\n    exit(1);\n}\ntemplate<class\
    \ T, class... Ts>\nint drop(const T& a, const Ts&... b){\n    std::cout << a;\n\
    \    (std::cout << ... << (std::cout << ' ', b));\n    std::cout << '\\n';\n \
    \   exit(1);\n}\n#line 7 \"test/oj/enumerate_primes.cpp\"\n\n/**\n * @brief Enumerate\
    \ Primes\n * \n */\nint main() {\n    int N, A, B;\n    std::cin >> N >> A >>\
    \ B;\n\n    snow::simple_sieve sieve(N);\n    auto ret = sieve.enumerate_primes();\n\
    \    \n    std::vector<int> ans;\n    for(int i = B; i < ret.size(); i += A){\n\
    \        ans.emplace_back(ret[i]);\n    }\n\n    std::cout << ret.size() << '\
    \ ' << ans.size() << '\\n';\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include \"snow/math/simple-sieve.hpp\"\n#include \"snow/io/setup.hpp\"\
    \n#include \"snow/io/helper.hpp\"\n\n/**\n * @brief Enumerate Primes\n * \n */\n\
    int main() {\n    int N, A, B;\n    std::cin >> N >> A >> B;\n\n    snow::simple_sieve\
    \ sieve(N);\n    auto ret = sieve.enumerate_primes();\n    \n    std::vector<int>\
    \ ans;\n    for(int i = B; i < ret.size(); i += A){\n        ans.emplace_back(ret[i]);\n\
    \    }\n\n    std::cout << ret.size() << ' ' << ans.size() << '\\n';\n    std::cout\
    \ << ans << '\\n';\n}"
  dependsOn:
  - snow/math/simple-sieve.hpp
  - snow/io/setup.hpp
  - snow/io/helper.hpp
  isVerificationFile: false
  path: test/oj/enumerate_primes.cpp
  requiredBy: []
  timestamp: '2021-03-23 03:17:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/oj/enumerate_primes.cpp
layout: document
redirect_from:
- /library/test/oj/enumerate_primes.cpp
- /library/test/oj/enumerate_primes.cpp.html
title: Enumerate Primes
---
