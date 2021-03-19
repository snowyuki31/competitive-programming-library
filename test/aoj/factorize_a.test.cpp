#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>

#include "src/math/factorize.hpp"

int main(){
    int n;
    std::cin >> n;
    auto ret = snow::factorize(n);
    std::cout << n << ':';
    for(auto [k, v] : ret){
        while(v--) std::cout << ' ' << k;
    }
    std::cout << '\n';
}
