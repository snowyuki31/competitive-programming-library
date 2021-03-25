#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "snow/graph/template.hpp"
#include "snow/graph/tree/heavy-light-decomposition.hpp"

/**
 * @brief Lowest Common Ancestor (Heavy Light Decomposition ver.)
 * 
 */
int main() {
    int N, Q;
    std::cin >> N >> Q;

    snow::Graph<int> G(N);
    for(int i = 1; i <= N - 1; ++i) {
        int p;
        std::cin >> p;
        G.add_edge(i, p);
    }

    snow::HeavyLightDecomposition HLD(G, 0);
    while(Q--){
        int u, v;
        std::cin >> u >> v;
        std::cout << HLD.get_lca(u, v) << '\n';
    }

    return 0;
}
