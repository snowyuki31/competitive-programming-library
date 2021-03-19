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
  bundledCode: "#line 2 \"snow/io/helper.hpp\"\n#include <iostream>\n#include <vector>\n\
    #include <set>\n\ntemplate< typename T1, typename T2 >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::pair< T1, T2 > &p) {\n    os << p.first <<\
    \ \" \" << p.second;\n    return os;\n}\n\ntemplate< typename T1, typename T2\
    \ >\nstd::istream &operator >> (std::istream &is, std::pair< T1, T2 > &p) {\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate< typename T1, typename\
    \ T2, typename T3 >\nstd::ostream &operator << (std::ostream &os, const std::tuple<\
    \ T1, T2, T3 > &t) {\n    os << get<0>(t) << \" \" << get<1>(t) << \" \" << get<2>(t);\n\
    \    return os;\n}\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::istream\
    \ &operator >> (std::istream &is, std::tuple< T1, T2, T3 > &t) {\n    is >> get<0>(t)\
    \ >> get<1>(t) >> get<2>(t);\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::vector< T > &v){\n    for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n        os << v[i] << (i + 1 != v.size() ? \"\
    \ \" : \"\");\n    }\n    return os;\n}\n\ntemplate< typename T >\nstd::istream\
    \ &operator >>  (std::istream &is, std::vector< T > &v){\n    for(T &in : v) is\
    \ >> in;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::set< T > &st){\n    int ct = 0;\n    for(auto&\
    \ s : st) cout << s << (++ct != st.size() ? \" \" : \"\");\n    return os;\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <set>\n\n\
    template< typename T1, typename T2 >\nstd::ostream &operator << (std::ostream\
    \ &os, const std::pair< T1, T2 > &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\n\ntemplate< typename T1, typename T2 >\nstd::istream &operator\
    \ >> (std::istream &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {\n    os\
    \ << get<0>(t) << \" \" << get<1>(t) << \" \" << get<2>(t);\n    return os;\n\
    }\n\ntemplate< typename T1, typename T2, typename T3 >\nstd::istream &operator\
    \ >> (std::istream &is, std::tuple< T1, T2, T3 > &t) {\n    is >> get<0>(t) >>\
    \ get<1>(t) >> get<2>(t);\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream\
    \ &operator << (std::ostream &os, const std::vector< T > &v){\n    for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n        os << v[i] << (i + 1 != v.size() ? \"\
    \ \" : \"\");\n    }\n    return os;\n}\n\ntemplate< typename T >\nstd::istream\
    \ &operator >>  (std::istream &is, std::vector< T > &v){\n    for(T &in : v) is\
    \ >> in;\n    return is;\n}\n\ntemplate< typename T >\nstd::ostream &operator\
    \ << (std::ostream &os, const std::set< T > &st){\n    int ct = 0;\n    for(auto&\
    \ s : st) cout << s << (++ct != st.size() ? \" \" : \"\");\n    return os;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: snow/io/helper.hpp
  requiredBy: []
  timestamp: '2021-03-20 02:37:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/io/helper.hpp
layout: document
redirect_from:
- /library/snow/io/helper.hpp
- /library/snow/io/helper.hpp.html
title: snow/io/helper.hpp
---
