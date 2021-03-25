#define PROBLEM "https://old.yosupo.jp/problem/vertex_add_path_sum"
#include <iostream>
#include <vector>
#include "snow/io/helper.hpp"
#include "snow/graph/template.hpp"
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/tree/heavy-light-decomposition.hpp"

/**
 * @brief Vertex Add Path Sum (Heavy Light Decomposition ver.)
 * 
 */
int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    std::cin >> A;

    snow::Graph<int> G(N);
    for (int i = 0; i < N - 1; ++i){
        int u, v;
        std::cin >> u >> v;
        G.add_edge(u, v);
    }

    snow::HeavyLightDecomposition HLD(G, 0);
    snow::segtree<snow::plus_monoid<long long>> segtree(N);
    for(int i = 0; i < N; ++i) segtree.set(HLD.get_id(i), A[i]);

    while(Q--){
        int t, u;
        std::cin >> t >> u;

        if(t == 0){
            int x;
            std::cin >> x;
            int id = HLD.get_id(u);
            segtree.set(id, segtree.get(id) + x);
        }
        else {
            int v;
            std::cin >> v;
            auto path = HLD.get_path(u, v);
            long long ret = 0;
            for(auto [l, r] : path) ret += segtree.prod(l, r);
            std::cout << ret << '\n';
        }
    }
}