#pragma once

#include <vector>
#include "snow/graph/tree/euler-tour-lca.hpp"
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Euler Tour (Point Set and Path Sum Query)
 * @note Available if inverse element exists (i.e., Abel)
 * @tparam T edge weight type
 */
template < typename S, typename T = int >
struct EulerTourPath : public EulerTourLCA<T> {
    public:
        EulerTourPath(snow::Graph<T> const &G, int root) : EulerTourLCA<T>(G, root), N(G.size()), _root(root), segtree(2 * N) {}

        void set(int u, S x) {
            segtree.set(this->get_in(u), x);
            segtree.set(this->get_out(u), -x); // You need apply inverse value here
        }

        S get(int u) {
            return segtree.get(this->get_in(u));
        }

        // Path Query (from u to v, inclusive)
        S prod(int u, int v) {
            int lca = this->lca(u, v);
            return _prod(u) + _prod(v) - 2 * _prod(lca) + segtree.get(this->get_in(lca));
        }

    private:
        int N;
        int _root;
        snow::segtree<snow::plus_monoid<S>> segtree;

        S _prod(int u){
            int l = this->get_in(_root), r = this->get_out(u);
            return segtree.prod(l, r);
        }
};

} // namespace snow