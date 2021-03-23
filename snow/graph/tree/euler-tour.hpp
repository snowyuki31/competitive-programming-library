#pragma once

#include <vector>
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Euler Tour (Point Set and Subtree Query)
 * @tparam S vertex value type
 * @tparam T edge weight type
 */
template < typename S, typename T = int >
struct EulerTour {
    public:
        EulerTour(snow::Graph<T> const& G, int root) : N(G.size()), vs(2 * N, 0), in(N, 0), out(N, 0), segtree(2 * N) {
            euler_tour(G, root, -1, 0);
        }

        void set(int u, S x) {
            segtree.set(in[u], x);
            // segtree.set(out[u], -x); for path query
        }

        S get(int u) {
            return segtree.get(in[u]);
        }

        S prod_subtree(int u) {
            int l = in[u], r = out[u];
            return segtree.prod(l, r);
        }

    private:
        int N;
        std::vector<int> vs;    // order->vertex number
        std::vector<int> in;    // vertex number->order(in)
        std::vector<int> out;   // vertex number->order(out)
        snow::segtree<snow::plus_monoid<S>> segtree;

        int order = 0;
        void euler_tour(snow::Graph<T> const& G, int v, int p, int d) {
            vs[order] = v;
            in[v] = order++;
            for(auto &e : G[v]) if(e.to != p) euler_tour(G, e.to, v, d + 1);
            vs[order] = v;
            out[v] = order++;
        }
};

} // namespace snow