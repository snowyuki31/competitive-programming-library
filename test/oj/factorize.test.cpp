#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>

#include "src/math/factorize.hpp"

int main(){
    int Q;
    std::cin >> Q;
    while(Q--){
        long long a;
        std::cin >> a;
        auto ret = snow::factorize(a);
        
        int counter = 0;
        for(auto [k, v] : ret) counter += v;
        std::cout << counter;

        for(auto [k, v] : ret){
            while(v--) std::cout << ' ' << k;
        }
        std::cout << '\n';
    }
}
