#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include <limits>

#include "snow/graph/shortest-path/dijkstra.hpp"

int main(){
    int V, E, r;
    std::cin >> V >> E >> r;

    snow::Graph<int> G(V);
    while(E--){
        int s, t, d;
        std::cin >> s >> t >> d;
        G.add_directed_edge(s, t, d);
    }

    auto ret = G.dijkstra(r);
    for(auto r : ret){
        if(r == G.INF) std::cout << "INF" << '\n';
        else std::cout << r << '\n';
    }

    return 0;
}