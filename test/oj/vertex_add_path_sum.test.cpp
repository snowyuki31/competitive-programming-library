#define PROBLEM "https://old.yosupo.jp/problem/vertex_add_path_sum"
#include <iostream>
#include <vector>
#include "snow/io/helper.hpp"
#include "snow/graph/template.hpp"
#include "snow/monoids/plus.hpp"
#include "snow/graph/tree/euler-tour-path.hpp"

/**
 * @brief Vertex Add Path Sum (Euler Tour ver.)
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

    snow::EulerTourPath<long long> euler(G, 0);
    for(int i = 0; i < N; ++i) euler.set(i, A[i]);

    while(Q--){
        int t, u;
        std::cin >> t >> u;

        if(t == 0){
            int x;
            std::cin >> x;
            euler.set(u, euler.get(u) + x);
        }
        else {
            int v;
            std::cin >> v;
            std::cout << euler.prod(u, v) << '\n';
        }
    }

}