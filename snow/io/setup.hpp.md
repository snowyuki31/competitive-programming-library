---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/oj/enumerate_primes.cpp
    title: test/oj/enumerate_primes.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/io/setup.hpp\"\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace snow{\n\nstruct IoSetup {\n    IoSetup() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n        std::cout << std::fixed <<\
    \ std::setprecision(10);\n    }\n} iosetup;\n\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <iomanip>\n\nnamespace snow{\n\
    \nstruct IoSetup {\n    IoSetup() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout << std::fixed << std::setprecision(10);\n    }\n} iosetup;\n\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: snow/io/setup.hpp
  requiredBy:
  - test/oj/enumerate_primes.cpp
  timestamp: '2021-03-20 04:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/io/setup.hpp
layout: document
redirect_from:
- /library/snow/io/setup.hpp
- /library/snow/io/setup.hpp.html
title: snow/io/setup.hpp
---
