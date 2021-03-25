#pragma once

#include <vector>

#include "snow/graph/template.hpp"

namespace snow{

/**
 * @brief Bellman-Ford
 * 
 * @param s 
 */
template < typename T >
std::vector<T> Graph<T>::bellman_ford(int s) const{
    std::vector<T> dist(G.size(), INF);
    dist[s] = 0;
    for(int i = 0; i < (int)G.size(); ++i){
        for(int j = 0; j < (int)G.size(); ++j){
            for(auto& e : G[j]){
                if(dist[j] == INF) continue;
                if(dist[e.to] > dist[j] + e.weight){
                    dist[e.to] = dist[j] + e.weight;
                    if(i == ((int)G.size() - 1)) return {};
                }
            }
        }
    }
    return dist;
}

}