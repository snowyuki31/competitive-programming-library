#pragma once
#include <vector>
#include <algorithm>
#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Diameter (木の直径)
 * @tparam T edge weight type
 */
template < typename T = int >
struct Diameter {
    public:
        Diameter(snow::Graph<T> const& G) : N(G.size()), G(G), dist(N, 0), dist_(N, 0) {
            dfs(G, 0, -1, dist);
            left = std::max_element(dist.begin(), dist.end()) - dist.begin();
            dist[left] = 0;
            dfs(G, left, -1, dist);
            right = std::max_element(dist.begin(), dist.end()) - dist.begin();
            dfs(G, right, -1, dist_);
        }

        std::pair<int, int> get_ends(){
            return {left, right};
        }

        T size(){
            return dist[right];
        }

        bool is_on(int x){
            return dist[x] + dist_[x] == dist[right];
        }

        std::vector<int> get_path(){
            std::vector<int> path{left};
            _dfs(G, left, -1, path);
            return path;
        }

    private:
        int N;
        snow::Graph<T> G;
        std::vector<T> dist;
        std::vector<T> dist_;
        int left, right;

        void dfs(snow::Graph<T> const& G, int s, int p, std::vector<T>& dist) {
            for(auto e : G[s]) if(e.to != p){
                dist[e.to] = dist[s] + e.weight;
                dfs(G, e.to, s, dist);
            }
        }

        void _dfs(snow::Graph<T> const &G, int s, int p, std::vector<int> &path){
            for(auto e : G[s]) if(e.to != p and is_on(e.to)){
                path.emplace_back(e.to);
                _dfs(G, e.to, s, path);
            }
        }
};

} // namespace snow