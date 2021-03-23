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
  bundledCode: "#line 2 \"snow/monoids/beats.hpp\"\n\nnamespace snow {\n\n    template\
    \ <typename T> inline T second_lowest(T a, T a2, T c, T c2) noexcept {\n     \
    \   return a == c ? std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : std::max(a,\
    \ c);\n    }\n    template <typename T> inline T second_highest(T a, T a2, T b,\
    \ T b2) noexcept {\n        return a == b ? std::max(a2, b2) : a2 >= b ? a2 :\
    \ b2 >= a ? b2 : std::min(a, b);\n    }\n\n    template < typename T >\n    struct\
    \ beats {\n        T inf = std::numelic_limits<T>::max();\n        T minf = std::numelic_limits<T>::lowest();\n\
    \        \n        struct value_type {\n            T lo, hi, lo2, hi2, sum;\n\
    \            unsigned sz, nlo, nhi;\n            bool fail;\n            value_type()\
    \ : lo(inf), hi(minf), lo2(inf), hi2(minf), sum(0), sz(0), nlo(0), nhi(0), fail(0)\
    \ {}\n            value_type(T x, unsigned sz_ = 1)\n                : lo(x),\
    \ hi(x), lo2(inf), hi2(minf), sum(x * sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(0)\
    \ {}\n        };\n\n        static value_type e() { return value_type(); };\n\
    \        static value_type op(value_type l, value_type r) {\n            static\
    \ value_type ret;\n            ret.lo = std::min(l.lo, r.lo), ret.hi = std::max(l.hi,\
    \ r.hi);\n            ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);\n   \
    \         ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);\n            ret.sum\
    \ = l.sum + r.sum, ret.sz = l.sz + r.sz;\n            ret.nlo = l.nlo * (l.lo\
    \ <= r.lo) + r.nlo * (r.lo <= l.lo);\n            ret.nhi = l.nhi * (l.hi >= r.hi)\
    \ + r.nhi * (r.hi >= l.hi);\n            return ret;\n        }\n\n        struct\
    \ mapping {\n            struct f_type {\n                T lb, ub, bias;\n  \
    \              f_type(T chmax_ = minf, T chmin_ = inf, T add = 0) : lb(chmax_),\
    \ ub(chmin_), bias(add) {}\n                static f_type chmin(T x) noexcept\
    \ { return f_type(minf, x, T(0)); }\n                static f_type chmax(T x)\
    \ noexcept { return f_type(x, inf, T(0)); }\n                static f_type add(T\
    \ x) noexcept { return f_type(minf, inf, x); };\n            };\n\n          \
    \  static f_type composition(f_type fnew, f_type fold) {\n                static\
    \ f_type ret;\n                ret.lb = std::max(std::min(fold.lb + fold.bias,\
    \ fnew.ub), fnew.lb) - fold.bias;\n                ret.ub = std::min(std::max(fold.ub\
    \ + fold.bias, fnew.lb), fnew.ub) - fold.bias;\n                ret.bias = fold.bias\
    \ + fnew.bias;\n                return ret;\n            }\n\n            static\
    \ f_type id() { return f_type(); }\n\n            value_type mapping(f_type f,\
    \ value_type x) {\n                if (x.sz == 0) return e();\n              \
    \  else if (x.lo == x.hi or f.lb == f.ub or f.lb >= x.hi or f.ub < x.lo) {\n \
    \                   return value_type(std::min(std::max(x.lo, f.lb), f.ub) + f.bias,\
    \ x.sz);\n                } else if (x.lo2 == x.hi) {\n                    x.lo\
    \ = x.hi2 = std::max(x.lo, f.lb) + f.bias;\n                    x.hi = x.lo2 =\
    \ std::min(x.hi, f.ub) + f.bias;\n                    x.sum = x.lo * x.nlo + x.hi\
    \ * x.nhi;\n                    return x;\n                } else if (f.lb < x.lo2\
    \ and f.ub > x.hi2) {\n                    T nxt_lo = std::max(x.lo, f.lb), nxt_hi\
    \ = std::min(x.hi, f.ub);\n                    x.sum += (nxt_lo - x.lo) * x.nlo\
    \ - (x.hi - nxt_hi) * x.nhi + f.bias * x.sz;\n                    x.lo = nxt_lo\
    \ + f.bias, x.hi = nxt_hi + f.bias, x.lo2 += f.bias, x.hi2 += f.bias;\n      \
    \              return x;\n                }\n                x.fail = true;\n\
    \                return x;\n            }\n        };\n    };\n\n} // namespace\
    \ snow\n"
  code: "#pragma once\n\nnamespace snow {\n\n    template <typename T> inline T second_lowest(T\
    \ a, T a2, T c, T c2) noexcept {\n        return a == c ? std::min(a2, c2) : a2\
    \ <= c ? a2 : c2 <= a ? c2 : std::max(a, c);\n    }\n    template <typename T>\
    \ inline T second_highest(T a, T a2, T b, T b2) noexcept {\n        return a ==\
    \ b ? std::max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : std::min(a, b);\n    }\n\
    \n    template < typename T >\n    struct beats {\n        T inf = std::numelic_limits<T>::max();\n\
    \        T minf = std::numelic_limits<T>::lowest();\n        \n        struct\
    \ value_type {\n            T lo, hi, lo2, hi2, sum;\n            unsigned sz,\
    \ nlo, nhi;\n            bool fail;\n            value_type() : lo(inf), hi(minf),\
    \ lo2(inf), hi2(minf), sum(0), sz(0), nlo(0), nhi(0), fail(0) {}\n           \
    \ value_type(T x, unsigned sz_ = 1)\n                : lo(x), hi(x), lo2(inf),\
    \ hi2(minf), sum(x * sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(0) {}\n        };\n\
    \n        static value_type e() { return value_type(); };\n        static value_type\
    \ op(value_type l, value_type r) {\n            static value_type ret;\n     \
    \       ret.lo = std::min(l.lo, r.lo), ret.hi = std::max(l.hi, r.hi);\n      \
    \      ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);\n            ret.hi2\
    \ = second_highest(l.hi, l.hi2, r.hi, r.hi2);\n            ret.sum = l.sum + r.sum,\
    \ ret.sz = l.sz + r.sz;\n            ret.nlo = l.nlo * (l.lo <= r.lo) + r.nlo\
    \ * (r.lo <= l.lo);\n            ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi\
    \ >= l.hi);\n            return ret;\n        }\n\n        struct mapping {\n\
    \            struct f_type {\n                T lb, ub, bias;\n              \
    \  f_type(T chmax_ = minf, T chmin_ = inf, T add = 0) : lb(chmax_), ub(chmin_),\
    \ bias(add) {}\n                static f_type chmin(T x) noexcept { return f_type(minf,\
    \ x, T(0)); }\n                static f_type chmax(T x) noexcept { return f_type(x,\
    \ inf, T(0)); }\n                static f_type add(T x) noexcept { return f_type(minf,\
    \ inf, x); };\n            };\n\n            static f_type composition(f_type\
    \ fnew, f_type fold) {\n                static f_type ret;\n                ret.lb\
    \ = std::max(std::min(fold.lb + fold.bias, fnew.ub), fnew.lb) - fold.bias;\n \
    \               ret.ub = std::min(std::max(fold.ub + fold.bias, fnew.lb), fnew.ub)\
    \ - fold.bias;\n                ret.bias = fold.bias + fnew.bias;\n          \
    \      return ret;\n            }\n\n            static f_type id() { return f_type();\
    \ }\n\n            value_type mapping(f_type f, value_type x) {\n            \
    \    if (x.sz == 0) return e();\n                else if (x.lo == x.hi or f.lb\
    \ == f.ub or f.lb >= x.hi or f.ub < x.lo) {\n                    return value_type(std::min(std::max(x.lo,\
    \ f.lb), f.ub) + f.bias, x.sz);\n                } else if (x.lo2 == x.hi) {\n\
    \                    x.lo = x.hi2 = std::max(x.lo, f.lb) + f.bias;\n         \
    \           x.hi = x.lo2 = std::min(x.hi, f.ub) + f.bias;\n                  \
    \  x.sum = x.lo * x.nlo + x.hi * x.nhi;\n                    return x;\n     \
    \           } else if (f.lb < x.lo2 and f.ub > x.hi2) {\n                    T\
    \ nxt_lo = std::max(x.lo, f.lb), nxt_hi = std::min(x.hi, f.ub);\n            \
    \        x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias *\
    \ x.sz;\n                    x.lo = nxt_lo + f.bias, x.hi = nxt_hi + f.bias, x.lo2\
    \ += f.bias, x.hi2 += f.bias;\n                    return x;\n               \
    \ }\n                x.fail = true;\n                return x;\n            }\n\
    \        };\n    };\n\n} // namespace snow"
  dependsOn: []
  isVerificationFile: false
  path: snow/monoids/beats.hpp
  requiredBy: []
  timestamp: '2021-03-21 19:40:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snow/monoids/beats.hpp
layout: document
redirect_from:
- /library/snow/monoids/beats.hpp
- /library/snow/monoids/beats.hpp.html
title: snow/monoids/beats.hpp
---
