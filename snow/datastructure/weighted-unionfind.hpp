#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace snow {

// Based on ACL implementation
template < typename Abel = int >
struct WeightedUnionFind {
  public:
    WeightedUnionFind() : _n(0) {}
    explicit WeightedUnionFind(int n, Abel e = 0) : _n(n), parent_or_size(n, -1), diff_weight(n, e) {}

    bool merge(int a, int b, Abel w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        w += weight(a), w -= weight(b);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w *= -1;
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        diff_weight[y] = w;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        int r = leader(parent_or_size[a]);
        diff_weight[a] += diff_weight[parent_or_size[a]];
        return parent_or_size[a] = r;
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    Abel weight(int a){
        leader(a);
        return diff_weight[a];
    }

    Abel diff(int a, int b){
        return weight(b) - weight(a);
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
    std::vector<Abel> diff_weight;
};

}  // namespace snow
