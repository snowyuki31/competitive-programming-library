---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snow/algorithm/binary-search.hpp
    title: snow/algorithm/binary-search.hpp
  - icon: ':question:'
    path: snow/io/helper.hpp
    title: snow/io/helper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_4_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n#line 2 \"snow/algorithm/binary-search.hpp\"\
    \n\n#include <utility>\n\nnamespace snow {\n\n// [left, right)\ntemplate< typename\
    \ T, typename F >\nT binary_search(T left, T right, F f, T EPS = 1) {\n    while(abs(right\
    \ - left) > EPS){\n        T mid = (right + left) / 2;\n        if(f(mid)) right\
    \ = mid;\n        else left = mid;\n    }\n    return right;\n}\n\n} // namespace\
    \ snow\n#line 4 \"snow/io/helper.hpp\"\n#include <set>\n\ntemplate< typename T1,\
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
    \ ? \" \" : \"\");\n    return os;\n}\n#line 8 \"test/aoj/ALDS1_4_B.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> S(n);\n\
    \    std::cin >> S;\n\n    int target;\n    bool lower_bound = true;\n    auto\
    \ f = [&](int x) {\n        if(lower_bound) return S[x] >= target;\n        return\
    \ S[x] > target;\n    };\n\n    int q;\n    std::cin >> q;\n    int ret = 0;\n\
    \    while(q--){\n        std::cin >> target;\n\n        lower_bound = true;\n\
    \        int left = snow::binary_search<int>(0, n, f);\n        lower_bound =\
    \ false;\n        int right = snow::binary_search<int>(0, n, f);\n        ret\
    \ += right > left;\n    }\n    std::cout << ret << '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n#include \"\
    snow/algorithm/binary-search.hpp\"\n#include \"snow/io/helper.hpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<int> S(n);\n    std::cin\
    \ >> S;\n\n    int target;\n    bool lower_bound = true;\n    auto f = [&](int\
    \ x) {\n        if(lower_bound) return S[x] >= target;\n        return S[x] >\
    \ target;\n    };\n\n    int q;\n    std::cin >> q;\n    int ret = 0;\n    while(q--){\n\
    \        std::cin >> target;\n\n        lower_bound = true;\n        int left\
    \ = snow::binary_search<int>(0, n, f);\n        lower_bound = false;\n       \
    \ int right = snow::binary_search<int>(0, n, f);\n        ret += right > left;\n\
    \    }\n    std::cout << ret << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - snow/algorithm/binary-search.hpp
  - snow/io/helper.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_4_B.test.cpp
  requiredBy: []
  timestamp: '2021-03-20 06:51:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_4_B.test.cpp
- /verify/test/aoj/ALDS1_4_B.test.cpp.html
title: test/aoj/ALDS1_4_B.test.cpp
---
