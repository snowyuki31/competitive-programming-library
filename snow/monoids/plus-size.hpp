#pragma once

namespace snow {

    template < typename T >
    struct plus_size_monoid {
        struct value_type {
            T val;
            int size;
        };
        static value_type e() { return value_type{0, 0}; };
        static value_type op(value_type l, value_type r) { return {l.val + r.val, l.size + r.size}; };

        struct add {
            using f_type = T;
            static value_type mapping(f_type f, value_type x) { return {f * x.size + x.val, x.size}; }
            static f_type composition(f_type f, f_type g) { return f + g; }
            static f_type id(){ return T(); }
        };

        struct update {
            struct f_type{
                T val;
                bool flag;
            };
            static value_type mapping(f_type f, value_type x) { return {(f.flag ? f.val * x.size : x.val), x.size}; }
            static f_type composition(f_type f, f_type g) { return f.flag ? f : g; }
            static f_type id(){ return {T(), false}; }
        };

        struct affine {
            using f_type = std::pair<T, T>;
            static value_type mapping(f_type f, value_type x) { return {x.val * f.first + x.size * f.second, x.size}; }
            static f_type composition(f_type f, f_type g) { return {g.first * f.first, g.second * f.first + f.second}; }
            static f_type id(){ return {1, 0}; }
        };
    };

} // namespace snow