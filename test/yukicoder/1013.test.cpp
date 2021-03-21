#define PROBLEM "https://yukicoder.me/problems/1013"

#include <iostream>
#include <string>
#include <time.h>
#include <map>
#include "snow/utils/xorshift.hpp"
#include "snow/string/rolling-hash.hpp"

int main() {
    std::string S;
    std::cin >> S;
    int N = S.size();

    snow::xorShift128 xs(time(NULL));
    auto seed = xs();

    snow::RollingHash RH(S, seed);
    
    std::map<unsigned long long, int> hash;
    for(int i = 0; i < N; ++i){
        for(int j = 1; j <= 10; ++j) if(i + j <= N){
            hash[RH.get(i, i + j)]++;
        }
    }

    int M;
    std::cin >> M;
    int ans = 0;
    while (M--) {
        std::string C;
        std::cin >> C;
        snow::RollingHash rh(C, seed);
        ans += hash[rh.get(0, (int)C.size())];
    }

    std::cout << ans << '\n';

    return 0;
}