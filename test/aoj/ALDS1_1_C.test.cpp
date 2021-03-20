#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#include "snow/math/sieve.hpp"

int main() {
    snow::sieve sieve(1e8);

    int N;
    std::cin >> N;
    int ret = 0;
    while(N--) {
        int q;
        std::cin >> q;
        ret += sieve.isprime(q);
    }
    std::cout << ret << '\n';
    
    return 0;
}