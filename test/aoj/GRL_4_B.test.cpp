#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include <iostream>
#include <cassert>

#include "snow/graph/topological-sort.hpp"

int main(){
    int V, E;
    std::cin >> V >> E;

    snow::Graph<int> G(V);
    
    while(E--){
        int s, t;
        std::cin >> s >> t;
        G.add_directed_edge(s, t);
    }

    auto ret = G.topological_sort();

    for(auto r : ret) std::cout << r << '\n';

    return 0;
}