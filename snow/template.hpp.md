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
  bundledCode: "#line 2 \"snow/template.hpp\"\n#pragma GCC target(\"avx2\")\n#pragma\
    \ GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    \nconstexpr long long INF = 1LL << 60;\n\n#define rep(i, n) for (ll i = 0; i <\
    \ (n); ++i)\n#define rep1(i, n) for (ll i = 1; i <= (n); ++i)\n#define rrep(i,\
    \ n) for (ll i = (n - 1); i >= 0; --i)\n#define ALL(obj) (obj).begin(), (obj).end()\n\
    #define RALL(obj) (obj).rbegin(), (obj).rend()\n#define pb push_back\n#define\
    \ to_s to_string\n#define len(v) (ll) v.size()\n#define print(x) cout << (x) <<\
    \ '\\n'\n#define drop(x) cout << (x) << '\\n', exit(0)\n#define debug(x) cout\
    \ << #x << \": \" << (x) << '\\n'\n\nusing namespace std;\n\ntypedef long long\
    \ ll;\ntypedef unsigned long long ull;\ntypedef long double ld;\ntypedef pair<ll,\
    \ ll> P;\ntypedef tuple<ll, ll, ll> tpl;\ntypedef vector<ll> vec;\ntypedef vector<vector<ll>>\
    \ vec2;\ntypedef vector<vector<vector<ll>>> vec3;\n\ntemplate < typename T >\n\
    inline bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n    \
    \    return 1;\n    }\n    return 0;\n}\n\ntemplate < typename T >\ninline bool\
    \ chmin(T &a, const T &b) {\n    if (b < a) {\n        a = b;\n        return\
    \ 1;\n    }\n    return 0;\n}\n"
  code: "#pragma once\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nconstexpr\
    \ long long INF = 1LL << 60;\n\n#define rep(i, n) for (ll i = 0; i < (n); ++i)\n\
    #define rep1(i, n) for (ll i = 1; i <= (n); ++i)\n#define rrep(i, n) for (ll i\
    \ = (n - 1); i >= 0; --i)\n#define ALL(obj) (obj).begin(), (obj).end()\n#define\
    \ RALL(obj) (obj).rbegin(), (obj).rend()\n#define pb push_back\n#define to_s to_string\n\
    #define len(v) (ll) v.size()\n#define print(x) cout << (x) << '\\n'\n#define drop(x)\
    \ cout << (x) << '\\n', exit(0)\n#define debug(x) cout << #x << \": \" << (x)\
    \ << '\\n'\n\nusing namespace std;\n\ntypedef long long ll;\ntypedef unsigned\
    \ long long ull;\ntypedef long double ld;\ntypedef pair<ll, ll> P;\ntypedef tuple<ll,\
    \ ll, ll> tpl;\ntypedef vector<ll> vec;\ntypedef vector<vector<ll>> vec2;\ntypedef\
    \ vector<vector<vector<ll>>> vec3;\n\ntemplate < typename T >\ninline bool chmax(T\
    \ &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\n\ntemplate < typename T >\ninline bool chmin(T &a, const\
    \ T &b) {\n    if (b < a) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: snow/template.hpp
  requiredBy: []
  timestamp: '2021-03-20 02:37:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/template.hpp
layout: document
redirect_from:
- /library/snow/template.hpp
- /library/snow/template.hpp.html
title: snow/template.hpp
---
