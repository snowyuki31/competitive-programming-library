#pragma once

#include <vector>
#include <limits>

#include "src/graph/graph-template.hpp"

namespace snow{

template < typename T >
std::vector<T> Graph<T>::bellman_ford(int s) const{
    const auto INF = std::numeric_limits<T>::max();
    std::vector<T> dist(G.size(), INF);
    dist[s] = 0;
    for(int i = 0; i < G.size(); ++i){
        for(int j = 0; j < G.size(); ++j){
            for(auto& e : G[j]){
                if(dist[e.from] == INF) continue;
                if(dist[e.to] > dist[e.from] + e.weight){
                    dist[e.to] = dist[e.from] + e.weight;
                    if(i == G.size() - 1) return {};
                }
            }
        }
    }
    return dist;
}

}