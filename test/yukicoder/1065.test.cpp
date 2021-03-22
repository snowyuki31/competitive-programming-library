#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4

#include <cmath>
#include <iostream>
#include <vector>

#include "snow/io/setup.hpp"
#include "snow/io/helper.hpp"
#include "snow/graph/shortest-path/dijkstra.hpp"

int main(){
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    --X, --Y;

    std::vector<std::pair<int, int>> pos(N);
    std::cin >> pos;

    snow::Graph<double> G(N);

    for(int i = 0; i < M; ++i){
        int p, q;
        std::cin >> p >> q;
        --p, --q;
        auto [x1, y1] = pos[p];
        auto [x2, y2] = pos[q];
        double d = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));

        G.add_edge(p, q, d);
    }

    auto ret = G.dijkstra(X);

    std::cout << ret[Y] << '\n';

    return 0;
}