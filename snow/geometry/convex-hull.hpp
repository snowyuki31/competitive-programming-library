#pragma once
#include <vector>
#include <algorithm>
#include "snow/geometry/geometry"

namespace geometry {

/**
 * @brief Convex-Hull (凸包)
 * 
 */
template < typename T >
std::vector<Point<T>> convex_hull(std::vector<Point<T>> X){
    std::sort(X.begin(), X.end());
    int k = 0;
    int n = X.size();
    std::vector<Point<T>> res(2 * n);
    for(int i = 0; i < n; ++i){
        while(k > 1 and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    for(int i = n - 2, t = k; i >= 0; --i){
        while(k > t and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    res.resize(k - 1);
    return res;
}

} // namespace geometry