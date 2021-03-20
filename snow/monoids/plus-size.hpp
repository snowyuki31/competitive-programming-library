#pragma once

inline namespace snow {

    template < typename T >
    struct plus_size_monoid {
        struct S {
            T val;
            int size;
        };
        static S e() { return S{0, 0}; };
        static S op(S l, S r) { return {l.val + r.val, l.size + r.size}; };
    };

} // namespace snow