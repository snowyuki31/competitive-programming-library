#pragma once

namespace snow {

    template < typename T >
    struct plus_monoid {
        using value_type = T;
        static value_type e() { return T(); };
        static value_type op(value_type l, value_type r){ return l + r; };
    };

} // namespace snow