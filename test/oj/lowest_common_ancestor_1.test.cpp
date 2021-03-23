#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "snow/graph/template.hpp"
#include "snow/graph/tree/lowest-common-ancestor-segtree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;

    snow::Graph<int> G(N);
    for(int i = 1; i <= N - 1; ++i) {
        int p;
        std::cin >> p;
        G.add_edge(i, p);
    }

    snow::LowestCommonAncestorBySeg LCA(G, 0);
    while(Q--){
        int u, v;
        std::cin >> u >> v;
        std::cout << LCA.get(u, v) << '\n';
    }

    return 0;
}