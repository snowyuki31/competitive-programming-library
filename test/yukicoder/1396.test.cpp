#define PROBLEM "https://yukicoder.me/problems/no/1396"

#include <iostream>
#include <unordered_map>
#include "atcoder/modint"
#include "snow/math/sieve.hpp"
using mint = atcoder::modint998244353;

/**
 * @brief Sieve of Eratosthenes for faster factorization
 * 
 */
int main() {
    int N;
    std::cin >> N;

    snow::Sieve sieve(N);
    std::unordered_map<int, int> memo;

    bool found = false;
    for(int i = N; i >= 1; --i){
        if(!found and sieve.isprime(i)){
            found = true;
            continue;
        }
        auto ret = sieve.factorize(i);
        for(auto [k, v] : ret){
            memo[k] = std::max(memo[k], v);
        }
    }
    mint ans = 1;
    for(auto [k, v] : memo) ans *= mint(k).pow(v);
    std::cout << ans.val() << '\n';

    return 0;
}