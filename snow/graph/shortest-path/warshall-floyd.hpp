#pragma once

#include <vector>

#include "snow/graph/template.hpp"

namespace snow{

/**
 * @brief Warshall-Floyd
 * 
 * @tparam T 
 */
template < typename T >
std::vector<std::vector<T>> Graph<T>::warshall_floyd() const{
    int N = G.size();
    std::vector<std::vector<T>> d(N, std::vector<T>(N, INF));
    
    for(int i = 0; i < N; ++i) d[i][i] = 0;

    for(int i = 0; i < N; ++i) for(auto &e : G[i]) d[i][e.to] = e.weight;

    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(d[i][k] == INF or d[k][j] == INF) continue;

                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
 
}

}