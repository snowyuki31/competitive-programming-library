#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include <limits>

#include "src/graph/shortest/bellman-ford.hpp"

int main(){
    int V, E, r;
    std::cin >> V >> E >> r;

    snow::Graph<int> G(V);
    while(E--){
        int s, t, d;
        std::cin >> s >> t >> d;
        G.add_arrow(s, t, d);
    }

    const auto INF = std::numeric_limits<int>::max();
    auto ret = G.bellman_ford(r);
    if(ret.empty()) std::cout << "NEGATIVE CYCLE" << '\n';
    else{
        for(auto r : ret){
            if(r == INF) std::cout << "INF" << '\n';
            else std::cout << r << '\n';
        }
    }
}