#pragma once
#include <vector>
#include "snow/graph/tree/euler-tour.hpp"
#include "snow/utils/seg-wrapper.hpp"
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Euler Tour (Point Set and Subtree Query)
 * @tparam Monoid Vertex value
 * @tparam T edge weight type
 */
template < class Monoid, typename T = int >
struct EulerTourSubtree : public EulerTour<T> {
    public:
        using S = typename Monoid::value_type;
        EulerTourSubtree(snow::Graph<T> const &G, int root) : EulerTour<T>(G, root), N(G.size()), segtree(2 * N) {}

        void set(int u, S x) {
            segtree.set(this->get_in(u), x);
        }

        S get(int u) {
            return segtree.get(this->get_in(u));
        }

        S prod(int u) {
            int l = this->get_in(u), r = this->get_out(u);
            return segtree.prod(l, r);
        }

    private:
        int N;
        snow::segtree<Monoid> segtree;
};

} // namespace snow