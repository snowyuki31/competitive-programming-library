#pragma once

inline namespace snow {

    template < typename T >
    struct min_monoid {
        using value_type = T;
        static value_type e() { return std::numeric_limits<T>::max(); };
        static value_type op(value_type l, value_type r){ return std::min(l, r); };

        struct update {
            struct f_type{
                T val;
                bool flag;
            };
            static value_type mapping(f_type f, value_type x) { return f.flag ? f.val : x; }
            static f_type composition(f_type f, f_type g) { return f.flag ? f : g; }
            static f_type id(){ return {T(), false}; }
        };
    };

} // namespace snow