#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include "snow/datastructure/segtree/wrapper.hpp"
#include "snow/monoids/min.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    snow::lazy_segtree<min_monoid<int>, min_monoid<int>::update> segtree(n);

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
