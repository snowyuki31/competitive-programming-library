#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include "snow/utils/seg-wrapper.hpp"
#include "snow/monoids/plus-size.hpp"

/**
 * @brief Segment Tree (Range Add and Range Sum)
 * 
 */
int main() {
    int n, q;
    std::cin >> n >> q;

    snow::lazy_segtree<snow::plus_size_monoid<long>, snow::plus_size_monoid<long>::add> segtree(n);
    for(int i = 0; i < n; ++i) segtree.set(i, {0, 1});

    while(q--) {
        int t;
        std::cin >> t;
        if(t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            --l, --r;
            segtree.apply(l, r + 1, x);
        }
        else {
            int s, t;
            std::cin >> s >> t;
            --s, --t;
            std::cout << segtree.prod(s, t + 1).val << '\n';
        }
    }

    return 0;
}
