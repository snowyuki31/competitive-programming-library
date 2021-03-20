#pragma once

#include "atcoder/segtree.hpp"
#include "atcoder/lazysegtree.hpp"

namespace snow {

    template < class Monoid >
    using segtree = atcoder::segtree<typename Monoid::value_type, Monoid::op, Monoid::e>;

    template < class Monoid, class Mapping >
    using lazy_segtree = atcoder::lazy_segtree<typename Monoid::value_type, Monoid::op, Monoid::e, typename Mapping::f_type, Mapping::mapping, Mapping::composition, Mapping::id>;

} // namespace snow