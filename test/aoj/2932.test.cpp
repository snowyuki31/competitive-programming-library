#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932"

#include <iostream>
#include "snow/math/divisor.hpp"
#include "snow/math/factorize.hpp"

int main() {
    long long N;
    std::cin >> N;
    auto div = snow::divisor(N);
    auto fac = snow::factorize(N);
    std::cout << fac.size() << ' ' << div.size() - 1 << '\n';
}