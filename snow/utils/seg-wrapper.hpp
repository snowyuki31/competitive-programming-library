#pragma once
#include "atcoder/segtree.hpp"

namespace snow {

    template < class Monoid >
    using segtree = atcoder::segtree<typename Monoid::value_type, Monoid::op, Monoid::e>;

} // namespace snow