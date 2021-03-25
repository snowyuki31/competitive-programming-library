#pragma once
#include <vector>
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/min.hpp"
#include "snow/graph/template.hpp"
#include "snow/graph/tree/euler-tour.hpp"

namespace snow {

/**
 * @brief Euler Tour (Lowest Common Ancestor Query)- 前処理$O(N\log N)$, $O(\log N)$
 * 
 */
template < typename T = int >
struct EulerTourLCA : public EulerTour<T> {
    public:
        EulerTourLCA(snow::Graph<T> const& G, int root) : EulerTour<T>(G, root), N(G.size()), segtree(2 * N) {
            for(int i = 0; i < 2 * N; ++i) segtree.set(i, {this->get_depth(i), this->get_vertex(i)});
        }

        int lca(int u, int v) {
            int u_ = this->get_in(u), v_ = this->get_in(v);
            auto ret = segtree.prod(std::min(u_, v_), std::max(u_, v_) + 1);
            return ret.second;
        }

    private:
        int N;
        snow::segtree<snow::min_monoid<std::pair<int, int>>> segtree;
};

} // namespace snow