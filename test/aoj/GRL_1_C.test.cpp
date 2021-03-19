#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>

#include "snow/graph/shortest-path/warshall-floyd.hpp"

int main(){
    int V, E;
    std::cin >> V >> E;

    snow::Graph<int> G(V);
    
    while(E--){
        int s, t, d;
        std::cin >> s >> t >> d;
        G.add_directed_edge(s, t, d);
    }

    auto ret = G.warshall_floyd();

    for(int i = 0; i < V; ++i){
        if(ret[i][i] < 0){
            std::cout << "NEGATIVE CYCLE" << '\n';
            return 0;
        }
    }

    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(j > 0) std::cout << ' ';
            if(ret[i][j] == G.INF) std::cout << "INF";
            else std::cout << ret[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
