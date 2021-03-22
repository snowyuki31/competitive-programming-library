#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#include "snow/math/euler-phi.hpp"

/**
 * @brief Euler's totient function
 * 
 */
int main(){
    int n;
    std::cin >> n;
    
    std::cout << snow::euler_phi(n) << '\n';

    return 0;
}
