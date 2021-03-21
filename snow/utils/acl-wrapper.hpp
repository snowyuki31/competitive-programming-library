#pragma once

#include "atcoder/segtree.hpp"
#include "atcoder/lazysegtree.hpp"

namespace snow {

    template < class Monoid >
    using segtree = atcoder::segtree<typename Monoid::value_type, Monoid::op, Monoid::e>;

    template < class Monoid, class Mapping >
    using lazy_segtree = atcoder::lazy_segtree<typename Monoid::value_type, Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition, Mapping::id>;

    template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
    struct _segtree_beats : atcoder::lazy_segtree<> {
        void all_apply(int k, F f) {
            d[k] = mapping(f, d[k]);
            if (k < size){
                lz[k] = composition(f, lz[k]);
                if (d[k].fail) push(k), update(k);
            }
        }
    };

    template < class Monoid, class Mapping >
    using segtree_beats = _segtree_beats<typename Monoid::value_type, Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition, Mapping::id>;


} // namespace snow