---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: snow/geometry/rotating-calipers.hpp
    title: "Rotating-Calipers (\u6700\u9060\u70B9\u5BFE)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: Diameter of a Convex Polygon
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1065.test.cpp
    title: Dijkstra (decimal floating point ver.)
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"snow/io/setup.hpp\"\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace snow{\n\nstruct IoSetup {\n    IoSetup() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n        std::cout << std::fixed <<\
    \ std::setprecision(10);\n    }\n} iosetup;\n\n} // namespace snow\n"
  code: "#pragma once\n#include <iostream>\n#include <iomanip>\n\nnamespace snow{\n\
    \nstruct IoSetup {\n    IoSetup() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout << std::fixed << std::setprecision(10);\n    }\n} iosetup;\n\
    \n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/io/setup.hpp
  requiredBy:
  - snow/geometry/rotating-calipers.hpp
  timestamp: '2021-04-21 03:38:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1065.test.cpp
  - test/aoj/CGL_4_B.test.cpp
documentation_of: snow/io/setup.hpp
layout: document
redirect_from:
- /library/snow/io/setup.hpp
- /library/snow/io/setup.hpp.html
title: snow/io/setup.hpp
---
