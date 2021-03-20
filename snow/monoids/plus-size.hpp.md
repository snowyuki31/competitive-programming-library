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
  bundledCode: "#line 2 \"snow/monoids/plus-size.hpp\"\n\nnamespace snow {\n\n   \
    \ template < typename T >\n    struct plus_size_monoid {\n        struct S {\n\
    \            T val;\n            int size;\n        };\n        static S e() {\
    \ return S{0, 0}; };\n        static S op(S l, S r) { return {l.val + r.val, l.size\
    \ + r.size}; };\n    };\n\n} // namespace snow\n"
  code: "#pragma once\n\nnamespace snow {\n\n    template < typename T >\n    struct\
    \ plus_size_monoid {\n        struct S {\n            T val;\n            int\
    \ size;\n        };\n        static S e() { return S{0, 0}; };\n        static\
    \ S op(S l, S r) { return {l.val + r.val, l.size + r.size}; };\n    };\n\n} //\
    \ namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/monoids/plus-size.hpp
  requiredBy: []
  timestamp: '2021-03-21 08:45:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/monoids/plus-size.hpp
layout: document
redirect_from:
- /library/snow/monoids/plus-size.hpp
- /library/snow/monoids/plus-size.hpp.html
title: snow/monoids/plus-size.hpp
---
