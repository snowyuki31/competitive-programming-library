#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#include "src/math/euler_phi.hpp"

int main(){
    int n;
    std::cin >> n;
    std::cout << snow::euler_phi(n) << '\n';
}
