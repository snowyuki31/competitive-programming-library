#define PROBLEM "https://yukicoder.me/problems/no/1035"

#include <iostream>
#include "atcoder/modint"
#include "snow/math/binomial.hpp"
using mint = atcoder::modint1000000007;

/**
 * @brief Twelvefold way III
 * 
 */
int main() {
    int N, M;
    std::cin >> N >> M;
    snow::Binomial<mint> binom(N);

    mint ans = 0;
    for(int i = 0; i <= M; ++i){
        ans += mint(M - i).pow(N) * binom.get(M, i) * (i % 2 ? -1 : 1);
    }
    std::cout << ans.val() << '\n';
}