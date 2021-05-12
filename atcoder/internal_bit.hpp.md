---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':question:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-lca.hpp
    title: "Euler Tour (Lowest Common Ancestor Query)- \u524D\u51E6\u7406$O(N\\log\
      \ N)$, $O(\\log N)$"
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-path.hpp
    title: Euler Tour (Point Set and Path Sum Query)
  - icon: ':heavy_check_mark:'
    path: snow/graph/tree/euler-tour-subtree.hpp
    title: Euler Tour (Point Set and Subtree Query)
  - icon: ':heavy_check_mark:'
    path: snow/utils/lazyseg-wrapper.hpp
    title: snow/utils/lazyseg-wrapper.hpp
  - icon: ':question:'
    path: snow/utils/seg-wrapper.hpp
    title: snow/utils/seg-wrapper.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: Segment Tree (Point Set and Range Sum)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: Segment Tree (Range Min and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: Segment Tree (Range Add and Range Sum)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: Segment Tree (Range Add and Range Min)
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: Segment Tree (Range Add and Range Update)
  - icon: ':heavy_check_mark:'
    path: test/oj/lowest_common_ancestor_1.test.cpp
    title: Lowest Common Ancestor (Euler Tour ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/range_affine_range_sum.test.cpp
    title: Segment Tree (Range Affine and Range Sum with Modint)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_path_sum.test.cpp
    title: Vertex Add Path Sum (Euler Tour ver.)
  - icon: ':x:'
    path: test/oj/vertex_add_path_sum_2.test.cpp
    title: Vertex Add Path Sum (Heavy Light Decomposition ver.)
  - icon: ':heavy_check_mark:'
    path: test/oj/vertex_add_subtree_sum.test.cpp
    title: Vertex Add Subtree Sum (Euler Tour ver.)
  - icon: ':x:'
    path: test/oj/vertex_add_subtree_sum_2.test.cpp
    title: Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - snow/utils/lazyseg-wrapper.hpp
  - snow/utils/seg-wrapper.hpp
  - snow/graph/tree/euler-tour-lca.hpp
  - snow/graph/tree/euler-tour-path.hpp
  - snow/graph/tree/euler-tour-subtree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/segtree.hpp
  - atcoder/convolution.hpp
  timestamp: '2021-03-21 08:31:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/oj/vertex_add_subtree_sum_2.test.cpp
  - test/oj/range_affine_range_sum.test.cpp
  - test/oj/vertex_add_subtree_sum.test.cpp
  - test/oj/vertex_add_path_sum_2.test.cpp
  - test/oj/lowest_common_ancestor_1.test.cpp
  - test/oj/vertex_add_path_sum.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
