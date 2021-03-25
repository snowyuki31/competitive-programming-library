#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <iostream>
#include <vector>
#include "snow/io/helper.hpp"
#include "snow/graph/template.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/tree/euler-tour-subtree.hpp"

/**
 * @brief Vertex Add Subtree Sum (Euler Tour ver.)
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

    snow::EulerTourSubtree<snow::plus_monoid<long long>> euler(G, 0);
    for(int i = 0; i < N; ++i) euler.set(i, A[i]);

    while(Q--){
        int t, u;
        std::cin >> t >> u;

        if(t == 0){
            int x;
            std::cin >> x;
            euler.set(u, euler.get(u) + x);
        }
        else std::cout << euler.prod(u) << '\n';
    }

}