#pragma once

#include <vector>
#include <queue>

#include "snow/graph/template.hpp"

namespace snow {

/**
 * @brief Topological Sort
 * 
 */
template < typename T >
std::vector<int> Graph<T>::topological_sort() const {
    int N = G.size();
    std::vector<int> ind(N, 0);
    
    for(int i = 0; i < N; ++i) for (auto &e : G[i]) ind[e.to]++;
    
    std::queue<int> que;
    for(int i = 0; i < N; ++i) if (ind[i] == 0) que.push(i);

    std::vector<int> ans;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        ans.emplace_back(now);

        for(auto& e : G[now]) {
            ind[e.to]--;
            if(ind[e.to] == 0) que.push(e.to);
        }
    }

    if ((int)ans.size() != N) return {};
    return ans;
}

}