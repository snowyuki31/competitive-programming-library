---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1013.test.cpp
    title: Rolling Hash
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"snow/string/rolling-hash.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\nnamespace snow {\n\n/* refference : https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\
    \ */\nstruct RollingHash {\n    public:\n        using ull = unsigned long long;\n\
    \n        RollingHash(const std::string& s, ull BASE = 8901016) : hashed(s.size()\
    \ + 1, 0), power(s.size() + 1, 0), BASE(BASE) {\n            power[0] = 1;\n \
    \           for(int i = 0; i < (int)s.size(); ++i) power[i + 1] = CalcMod(Mul(power[i],\
    \ BASE));\n            for(int i = 0; i < (int)s.size(); ++i) hashed[i + 1] =\
    \ CalcMod(Mul(hashed[i], BASE) + s[i]);\n        }\n\n        //[L, r)\n     \
    \   ull get(int l, int r){\n            return CalcMod(hashed[r] + POSITIVIZER\
    \ - Mul(hashed[l], power[r - l]));\n        }\n\n        ull Mul(ull a, ull b){\n\
    \            ull au = a >> 31;\n            ull ad = a & MASK31;\n           \
    \ ull bu = b >> 31;\n            ull bd = b & MASK31;\n            ull mid = ad\
    \ * bu + au * bd;\n            ull midu = mid >> 30;\n            ull midd = mid\
    \ & MASK30;\n            return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    \        }\n\n        ull CalcMod(ull x){\n            ull xu = x >> 61;\n   \
    \         ull xd = x & MASK61;\n            ull res = xu + xd;\n            if\
    \ (res >= MOD) res -= MOD;\n            return res;\n        }\n\n    protected:\n\
    \        std::vector<ull> hashed, power;\n        const unsigned long long BASE;\n\
    \        const ull MASK30 = (1ull << 30) - 1;\n        const ull MASK31 = (1ull\
    \ << 31) - 1;\n        const ull MOD = (1ull << 61) - 1;\n        const ull MASK61\
    \ = MOD;\n        const ull POSITIVIZER = MOD * ((1ull << 3) - 1);\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace snow {\n\
    \n/* refference : https://qiita.com/keymoon/items/11fac5627672a6d6a9f6 */\nstruct\
    \ RollingHash {\n    public:\n        using ull = unsigned long long;\n\n    \
    \    RollingHash(const std::string& s, ull BASE = 8901016) : hashed(s.size() +\
    \ 1, 0), power(s.size() + 1, 0), BASE(BASE) {\n            power[0] = 1;\n   \
    \         for(int i = 0; i < (int)s.size(); ++i) power[i + 1] = CalcMod(Mul(power[i],\
    \ BASE));\n            for(int i = 0; i < (int)s.size(); ++i) hashed[i + 1] =\
    \ CalcMod(Mul(hashed[i], BASE) + s[i]);\n        }\n\n        //[L, r)\n     \
    \   ull get(int l, int r){\n            return CalcMod(hashed[r] + POSITIVIZER\
    \ - Mul(hashed[l], power[r - l]));\n        }\n\n        ull Mul(ull a, ull b){\n\
    \            ull au = a >> 31;\n            ull ad = a & MASK31;\n           \
    \ ull bu = b >> 31;\n            ull bd = b & MASK31;\n            ull mid = ad\
    \ * bu + au * bd;\n            ull midu = mid >> 30;\n            ull midd = mid\
    \ & MASK30;\n            return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    \        }\n\n        ull CalcMod(ull x){\n            ull xu = x >> 61;\n   \
    \         ull xd = x & MASK61;\n            ull res = xu + xd;\n            if\
    \ (res >= MOD) res -= MOD;\n            return res;\n        }\n\n    protected:\n\
    \        std::vector<ull> hashed, power;\n        const unsigned long long BASE;\n\
    \        const ull MASK30 = (1ull << 30) - 1;\n        const ull MASK31 = (1ull\
    \ << 31) - 1;\n        const ull MOD = (1ull << 61) - 1;\n        const ull MASK61\
    \ = MOD;\n        const ull POSITIVIZER = MOD * ((1ull << 3) - 1);\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: snow/string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2021-03-22 05:13:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1013.test.cpp
documentation_of: snow/string/rolling-hash.hpp
layout: document
title: Rolling Hash
---

## About

Rolling Hashです．

実装は[こちら](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)を参考にしています．

## How to use

```RollingHash RH(string S, ull seed)``` : seedをもとに文字列$S$に対してローリングハッシュを行う．

```ull RH.get(l, r)``` : $[l, r)$のハッシュを取得．

seedにはxorshiftによる乱数生成器```snow::xorShift128```を利用するといいかも．