#define PROBLEM "https://old.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include "snow/utils/acl-wrapper.hpp"
#include "snow/monoids/plus-size.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

/**
 * @brief Range Affine Range Sum with modint
 * 
 */
int main() {
    int N, Q;
    std::cin >> N >> Q;
    snow::lazy_segtree<snow::plus_size_monoid<mint>, snow::plus_size_monoid<mint>::affine> segtree(N);
    for(int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        segtree.set(i, {a, 1});
    }

    while(Q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if(t == 0) {
            int b, c;
            std::cin >> b >> c;
            segtree.apply(l, r, {b, c});
        }
        else {
            std::cout << segtree.prod(l, r).val.val() << '\n';
        }
    }
}