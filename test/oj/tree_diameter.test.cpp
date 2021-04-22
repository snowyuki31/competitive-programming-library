#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include <iostream>
#include "snow/io/helper.hpp"
#include "snow/graph/tree/diameter.hpp"

/**
 * @brief Tree Diameter
 * 
 */
int main() {
    int N;
    std::cin >> N;
    snow::Graph<long long> G(N);
    for (int i = 0; i < N - 1; ++i){
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    snow::Diameter diameter(G);
    auto path = diameter.get_path();
    print(diameter.size(), path.size());
    print(path);
}