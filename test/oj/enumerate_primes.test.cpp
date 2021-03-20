#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <iostream>
#include "snow/math/simple-sieve.hpp"
#include "snow/io/helper.hpp"

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    snow::simple_sieve sieve(N);
    auto ret = sieve.enumerate_prime();
    
    std::vector<int> ans;
    for(int i = B; i < ret.size(); i += A){
        ans.emplace_back(ret[i]);
    }

    std::cout << ret.size() << ' ' << ans.size() << '\n';
    std::cout << ans << '\n';
}