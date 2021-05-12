#pragma once
#include <utility>
#include <vector>
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Heavy Light Decomposition
 * 
 * @tparam T 
 * @ref https://codeforces.com/blog/entry/53170
 */
template < typename T = int >
struct HeavyLightDecomposition {
    public:
        HeavyLightDecomposition(snow::Graph<T>& G, int root) : N(G.size()), sz(N), in(N), par(N), next(N), depth(N) {
            dfs_sz(G, root);
            next[root] = root;
            dfs_hld(G, root);
        }

        /**
         * @brief Get vertex id.
         * @param v 
         */
        int get_id(int v){
            return in[v];
        }

        /**
         * @brief Get Edge id.
         */
        int get_edge_id(int u, int v){
            if(depth[u] > depth[v]) swap(u, v);
            return get_id(v);
        }

        /**
         * @brief Get depth.
         * 
         */
        int get_depth(int u){
            return depth[u];
        }

        /**
         * @brief Get Lowest Common Ancestor of (u, v).
         * 
         * @param u 
         * @param v 
         */
        int get_lca(int u, int v){
            while (true){
                if(in[u] > in[v]) std::swap(u, v);
                if(next[u] == next[v]) return u;
                v = par[next[v]];
            }
        }

        /**
         * @brief Get a segment of id corresponding to the subtree of v.
         * @param v 
         */
        std::pair<int, int> get_subtree(int v){
            return {in[v], in[v] + sz[v]};
        }

        /**
         * @brief Get segments of id corresponding to the path from u to v inclusive.
         * @param u
         * @param v
         * @return vector<pair<int, int>> : set of segments [l_i, r_i)
         */
        std::vector<std::pair<int, int>> get_path(int u, int v) {
            std::vector<std::pair<int, int>> path;
            while (true){
                if(in[u] > in[v]) std::swap(u, v);
                path.emplace_back(std::max(in[next[v]], in[u]), in[v] + 1);

                if(next[u] != next[v]) v = par[next[v]];
                else break;
            }
            return path;
        }

        /**
         * @brief Get segments of id corresponding to the edge-wise path from u to v inclusive.
         * @param u
         * @param v
         * @return vector<pair<int, int>> : set of segments [l_i, r_i)
         */
        std::vector<std::pair<int, int>> get_edge_path(int u, int v){
            std::vector<std::pair<int, int>> path;
            while (true){
                if(in[u] > in[v]) std::swap(u, v);
                if(next[u] != next[v]) {
                    path.emplace_back(in[next[v]], in[v] + 1);
                    v = par[next[v]];
                }
                else{
                    if(u != v) path.emplace_back(in[u] + 1, in[v] + 1);
                    break;
                }
            }
            return path;
        }

    private:
        int N;
        std::vector<int> sz;
        std::vector<int> in;
        std::vector<int> out;
        std::vector<int> par;
        std::vector<int> next; // last vertex of heavy chain of x
        std::vector<int> depth;

        void dfs_sz(snow::Graph<T>& G, int v, int p = -1){
            sz[v] = 1;
            if(p != -1) depth[v] = depth[p] + 1;
            for(auto &e : G[v]) if(e.to != p) {
                dfs_sz(G, e.to, v);
                sz[v] += sz[e.to];
                if(sz[e.to] > sz[G[v][0].to]) std::swap(e, G[v][0]);
            }
        }

        int order = 0;
        void dfs_hld(snow::Graph<T>& G, int v, int p = -1){
            par[v] = p, in[v] = order++;
            for(auto e : G[v]) if(e.to != p) {
                next[e.to] = ((e.to == G[v].front().to) ? next[v] : e.to);
                dfs_hld(G, e.to, v);
            }
        }
};

} // namespace snow