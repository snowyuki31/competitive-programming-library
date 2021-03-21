#pragma once

namespace snow {

    template <typename T> inline T second_lowest(T a, T a2, T c, T c2) noexcept {
        return a == c ? std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : std::max(a, c);
    }
    template <typename T> inline T second_highest(T a, T a2, T b, T b2) noexcept {
        return a == b ? std::max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : std::min(a, b);
    }

    template < typename T >
    struct beats {
        T inf = std::numelic_limits<T>::max();
        T minf = std::numelic_limits<T>::lowest();
        
        struct value_type {
            T lo, hi, lo2, hi2, sum;
            unsigned sz, nlo, nhi;
            bool fail;
            value_type() : lo(inf), hi(minf), lo2(inf), hi2(minf), sum(0), sz(0), nlo(0), nhi(0), fail(0) {}
            value_type(T x, unsigned sz_ = 1)
                : lo(x), hi(x), lo2(inf), hi2(minf), sum(x * sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(0) {}
        };

        static value_type e() { return value_type(); };
        static value_type op(value_type l, value_type r) {
            static value_type ret;
            ret.lo = std::min(l.lo, r.lo), ret.hi = std::max(l.hi, r.hi);
            ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);
            ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);
            ret.sum = l.sum + r.sum, ret.sz = l.sz + r.sz;
            ret.nlo = l.nlo * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo);
            ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi >= l.hi);
            return ret;
        }

        struct mapping {
            struct f_type {
                T lb, ub, bias;
                f_type(T chmax_ = minf, T chmin_ = inf, T add = 0) : lb(chmax_), ub(chmin_), bias(add) {}
                static f_type chmin(T x) noexcept { return f_type(minf, x, T(0)); }
                static f_type chmax(T x) noexcept { return f_type(x, inf, T(0)); }
                static f_type add(T x) noexcept { return f_type(minf, inf, x); };
            };

            static f_type composition(f_type fnew, f_type fold) {
                static f_type ret;
                ret.lb = std::max(std::min(fold.lb + fold.bias, fnew.ub), fnew.lb) - fold.bias;
                ret.ub = std::min(std::max(fold.ub + fold.bias, fnew.lb), fnew.ub) - fold.bias;
                ret.bias = fold.bias + fnew.bias;
                return ret;
            }

            static f_type id() { return f_type(); }

            value_type mapping(f_type f, value_type x) {
                if (x.sz == 0) return e();
                else if (x.lo == x.hi or f.lb == f.ub or f.lb >= x.hi or f.ub < x.lo) {
                    return value_type(std::min(std::max(x.lo, f.lb), f.ub) + f.bias, x.sz);
                } else if (x.lo2 == x.hi) {
                    x.lo = x.hi2 = std::max(x.lo, f.lb) + f.bias;
                    x.hi = x.lo2 = std::min(x.hi, f.ub) + f.bias;
                    x.sum = x.lo * x.nlo + x.hi * x.nhi;
                    return x;
                } else if (f.lb < x.lo2 and f.ub > x.hi2) {
                    T nxt_lo = std::max(x.lo, f.lb), nxt_hi = std::min(x.hi, f.ub);
                    x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias * x.sz;
                    x.lo = nxt_lo + f.bias, x.hi = nxt_hi + f.bias, x.lo2 += f.bias, x.hi2 += f.bias;
                    return x;
                }
                x.fail = true;
                return x;
            }
        };
    };

} // namespace snow