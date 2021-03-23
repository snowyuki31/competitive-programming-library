#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include "snow/utils/lazyseg-wrapper.hpp"
#include "snow/monoids/min.hpp"

/**
 * @brief Segment Tree (Range Add and Range Min)
 * 
 */
int main() {
    int n, q;
    std::cin >> n >> q;

    snow::lazy_segtree<snow::min_monoid<int>, snow::min_monoid<int>::add> segtree(n);
    for(int i = 0; i < n; ++i) segtree.set(i, 0);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            segtree.apply(l, r + 1, x);
        }
        else {
            int s, t;
            std::cin >> s >> t;
            std::cout << segtree.prod(s, t + 1) << '\n';
        }
    }

    return 0;
}
