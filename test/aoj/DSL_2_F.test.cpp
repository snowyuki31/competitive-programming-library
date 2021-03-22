#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include "snow/utils/acl-wrapper.hpp"
#include "snow/monoids/min.hpp"

/**
 * @brief Segment Tree (Range Min and Range Update)
 * 
 */
int main() {
    int n, q;
    std::cin >> n >> q;

    snow::lazy_segtree<snow::min_monoid<int>, snow::min_monoid<int>::update> segtree(n);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            segtree.apply(l, r + 1, {x, 1});
        }
        else {
            int s, t;
            std::cin >> s >> t;
            std::cout << segtree.prod(s, t + 1) << '\n';
        }
    }

    return 0;
}
