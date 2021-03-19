#pragma once

#include <vector>
#include <queue>
#include <limits>

#include "snow/graph/graph.hpp"

namespace snow{

template < typename T >
std::vector<T> Graph<T>::dijkstra(int s) const{
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> que;
    std::vector<T> dist(G.size(), INF);
    dist[s] = 0;
    que.emplace(dist[s], s);

    while(!que.empty()){
        auto [cost, idx] = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : G[idx]){
            auto next_cost = cost + e.weight;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

}