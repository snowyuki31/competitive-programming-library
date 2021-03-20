#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "snow/utils/acl-wrapper.hpp"
#include "snow/monoids/plus.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    snow::segtree<snow::plus_monoid<int>> segtree(n);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int i, x;
            std::cin >> i >> x;
            --i;
            segtree.set(i, segtree.get(i) + x);
        }
        else {
            int s, t;
            std::cin >> s >> t;
            --s, --t;
            std::cout << segtree.prod(s, t + 1) << '\n';
        }
    }

}
