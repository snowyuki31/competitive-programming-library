#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include <iostream>
#include <vector>
#include <string>
#include "snow/io/helper.hpp"
#include "snow/algorithm/cumsum2D.hpp"

/**
 * @brief Cumurative Sum (2D)
 * 
 */
int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::string> grid(N);
    std::cin >> grid;

    std::vector<std::vector<int>> J(N, std::vector<int>(M));
    auto O = J, I = J;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(grid[i][j] == 'J') ++J[i][j];
            if(grid[i][j] == 'O') ++O[i][j];
            if(grid[i][j] == 'I') ++I[i][j];
        }
    }

    snow::cumsum2D cumj(J), cumo(O), cumi(I);

    while(K--) {
        int a, b, c, d;
        input(a, b, c, d);
        --a, --b, --c, --d;

        int j = cumj.get(a, b, c + 1, d + 1);
        int o = cumo.get(a, b, c + 1, d + 1);
        int i = cumi.get(a, b, c + 1, d + 1);
        print(j, o, i);
    }
}