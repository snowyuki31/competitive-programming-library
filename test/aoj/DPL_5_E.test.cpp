#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"

#include <iostream>
#include "atcoder/modint"
#include "snow/math/binomial.hpp"
using mint = atcoder::modint1000000007;

/**
 * @brief Twelvefold way V
 * 
 */
int main() {
    int n, k;
    std::cin >> n >> k;
    snow::Binomial<mint> binom(k);
    std::cout << binom.get(k, n).val() << '\n';
}