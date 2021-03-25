#define PROBLEM "https://old.yosupo.jp/problem/vertex_add_subtree_sum"
#include <iostream>
#include <vector>
#include "snow/io/helper.hpp"
#include "snow/graph/template.hpp"
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/tree/heavy-light-decomposition.hpp"

/**
 * @brief Vertex Add Subtree Sum (Heavy Light Decomposition ver.)
 * 
 */
int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    std::cin >> A;

    snow::Graph<int> G(N);
    for (int i = 1; i <= N - 1; ++i){
        int p;
        std::cin >> p;
        G.add_edge(p, i);
    }

    snow::HeavyLightDecomposition<int> HLD(G, 0);
    snow::segtree<snow::plus_monoid<long long>> segtree(N);

    for(int i = 0; i < N; ++i) segtree.set(HLD.get_id(i), A[i]);

    while(Q--){
        int t, u;
        std::cin >> t >> u;

        if(t == 0){
            int x;
            std::cin >> x;
            segtree.set(HLD.get_id(u), segtree.get(HLD.get_id(u)) + x);
        }
        else{
            auto [l, r] = HLD.get_subtree(u);
            std::cout << segtree.prod(l, r) << '\n';
        }
    }

}