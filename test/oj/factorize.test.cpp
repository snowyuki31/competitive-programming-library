#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include<iostream>

#include<src/math/factorize.hpp>

int main(){
    int Q;
    std::cin >> Q;
    while(Q--){
        long long a;
        std::cin >> a;
        auto ret = snow::factorize(a);
        std::cout << ret.size();
        for(auto [k, v] : ret) std::cout << ' ' << k;
        std::cout << '\n';
    }
}
