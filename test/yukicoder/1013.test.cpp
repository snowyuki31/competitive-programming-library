#define PROBLEM "https://yukicoder.me/problems/no/1013"
#include <iostream>
#include <vector>
#include <utility>
#include "snow/algorithm/weighted-doubling.hpp"

/**
 * @brief Weighted Doubling
 * 
 */
int main() {
    int N;
    long long K;
    std::cin >> N >> K;
    std::vector<int> p(N);
    for (int i = 0; i < N; ++i) std::cin >> p[i];

    std::vector<std::pair<int, long long>> f(N);
    for(int i = 0; i < N; ++i){
        f[i] = {(i + p[i]) % N, p[i]};
    }

    snow::WeightedDoubling doubling(f, K);

    for (int i = 0; i < N; ++i){
        auto [p, v] = doubling.get(i, K);
        std::cout << v + 1 + i << '\n';
    }

    return 0;
}