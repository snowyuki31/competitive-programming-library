#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"

#include <iostream>
#include <algorithm>
#include <vector>
#include "snow/algorithm/binary-search.hpp"
#include "snow/io/helper.hpp"

/**
 * @brief Binary Search
 * 
 */
int main() {
    int n;
    std::cin >> n;
    std::vector<int> S(n);
    std::cin >> S;

    int target;
    bool lower_bound = true;
    auto f = [&](int x) {
        if(lower_bound) return S[x] >= target;
        return S[x] > target;
    };

    int q;
    std::cin >> q;
    int ret = 0;
    while(q--){
        std::cin >> target;

        lower_bound = true;
        int left = snow::binary_search<int>(0, n, f);
        lower_bound = false;
        int right = snow::binary_search<int>(0, n, f);
        ret += right > left;
    }
    std::cout << ret << '\n';

    return 0;
}