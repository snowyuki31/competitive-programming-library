#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include <algorithm>
#include <iostream>
#include <utility>
#include "snow/geometry/convex-hull.hpp"

/**
 * @brief Convex-Hull
 */
int main() {
    int N;
    std::cin >> N;
    std::vector<geometry::Point<long double>> points(N);
    for (int i = 0; i < N; ++i) std::cin >> points[i];

    auto ret = geometry::convex_hull(points);
    
    int min_pos;
    int x = 1e6, y = 1e6;
    for (int i = 0; i < (int)ret.size(); ++i){
        auto [a, b] = ret[i];
        if(b < y or (b == y and a < x)) x = a, y = b, min_pos = i;
    }

    std::rotate(ret.begin(), ret.begin() + min_pos, ret.end());

    std::cout << ret.size() << '\n';
    for(auto r : ret) std::cout << r << '\n';

    return 0;
}