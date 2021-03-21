---
title: Rolling Hash
documentation_of: snow/string/rolling-hash.hpp
---

## About

Rolling Hashです．

実装は[こちら](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)を参考にしています．

## How to use

```RollingHash RH(string S, ull seed)``` : seedをもとに文字列$S$に対してローリングハッシュを行う．

```ull RH.get(l, r)``` : $[l, r)$のハッシュを取得．

seedにはxorshiftによる乱数生成器```snow::xorShift128```を利用するといいかも．