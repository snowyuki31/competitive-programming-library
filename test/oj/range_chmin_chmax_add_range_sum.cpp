#define PROBLEM "https://old.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include "snow/utils/acl-wrapper.hpp"
#include "snow/monoids/beats.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;

    snow::segtree_beats<snow::beats<long>, snow::beats<long>::mapping> segtree(N);
    

}