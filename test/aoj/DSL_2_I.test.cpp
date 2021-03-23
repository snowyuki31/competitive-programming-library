#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#include "snow/utils/lazyseg-wrapper.hpp"
#include "snow/monoids/plus-size.hpp"

/**
 * @brief Segment Tree (Range Add and Range Update)
 * 
 */
int main() {
    int n, q;
    std::cin >> n >> q;

    snow::lazy_segtree<snow::plus_size_monoid<int>, snow::plus_size_monoid<int>::update> segtree(n);
    for(int i = 0; i < n; ++i) segtree.set(i, {0, 1});

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
            std::cout << segtree.prod(s, t + 1).val << '\n';
        }
    }

    return 0;
}
