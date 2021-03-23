#pragma once

#include <vector>
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/min.hpp"
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Lowest Common Ancestor (Segment Tree ver.) - 前処理$O(N\log N)$, $O(\logN)$
 * 
 */
template < typename T = int >
struct LowestCommonAncestorBySeg {
    public:
        LowestCommonAncestorBySeg(snow::Graph<T> const& G, int root) : N(G.size()), depth(2 * N, 0), vs(2 * N, 0), id(N, 0), segtree(2 * N) {
            euler_tour(G, root, -1, 0);
            for(int i = 0; i < 2 * N; ++i) segtree.set(i, {depth[i], vs[i]});
        }

        int get(int u, int v) {
            int u_ = id[u], v_ = id[v];
            auto ret = segtree.prod(std::min(u_, v_), std::max(u_, v_) + 1);
            return ret.second;
        }

    private:
        int N;
        std::vector<int> depth; // order->depth
        std::vector<int> vs;    // order->vertex number
        std::vector<int> id;    // vertex number->order
        snow::segtree<snow::min_monoid<std::pair<int, int>>> segtree;

        int order = 0;
        void euler_tour(snow::Graph<T> const& G, int v, int p, int d){
            id[v] = order;
            vs[order] = v;
            depth[order++] = d;
            for(auto &e : G[v]) if(e.to != p){
                euler_tour(G, e.to, v, d + 1);
                vs[order] = v;
                depth[order++] = d;
            }
        }
};

} // namespace snow