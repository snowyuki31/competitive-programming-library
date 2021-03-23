#pragma once

#include <vector>
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Euler Tour
 * @tparam T edge weight type
 */
template < typename T = int >
struct EulerTour {
    public:
        EulerTour(snow::Graph<T> const& G, int root) : N(G.size()), vs(2 * N, 0), in(N, 0), out(N, 0), depth(2 * N, 0) {
            dfs(G, root, -1, 0);
        }

        int get_in(int x){
            return in[x];
        }

        int get_out(int x){
            return out[x];
        }

        int get_vertex(int x){
            return vs[x];
        }

        int get_depth(int x){
            return depth[x];
        }

    private:
        int N;
        std::vector<int> vs;    // order->vertex number
        std::vector<int> in;    // vertex number->order(in)
        std::vector<int> out;   // vertex number->order(out)
        std::vector<int> depth; // depth

        int order = 0;
        void dfs(snow::Graph<T> const& G, int v, int p, int d) {
            vs[order] = v;
            depth[order] = d;
            in[v] = order++;
            for(auto &e : G[v]) if(e.to != p) {
                dfs(G, e.to, v, d + 1);
                vs[order] = v;
                depth[order++] = d;
            }
            out[v] = order;
        }
};

} // namespace snow