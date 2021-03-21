---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':x:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':x:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':x:'
    path: snow/utils/acl-wrapper.hpp
    title: snow/utils/acl-wrapper.hpp
  - icon: ':warning:'
    path: test/oj/range_chmin_chmax_add_range_sum.cpp
    title: test/oj/range_chmin_chmax_add_range_sum.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/oj/range_affine_range_sum.test.cpp
    title: test/oj/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param\
    \ n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n\
    \ & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned\
    \ long index;\n    _BitScanForward(&index, n);\n    return index;\n#else\n   \
    \ return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n)\
    \ {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index, n);\n\
    \    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_bit.hpp
  requiredBy:
  - test/oj/range_chmin_chmax_add_range_sum.cpp
  - snow/utils/acl-wrapper.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/segtree.hpp
  - atcoder/convolution.hpp
  timestamp: '2021-03-21 08:31:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/oj/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
