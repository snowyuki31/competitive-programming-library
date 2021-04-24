#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001
#include <algorithm>
#include <iostream>
#include <utility>
#include "snow/geometry/rotating-calipers.hpp"

/**
 * @brief Diameter of a Convex Polygon
 */
int main() {
    int N;
    std::cin >> N;
    std::vector<geometry::Point<long double>> points(N);
    for (int i = 0; i < N; ++i) std::cin >> points[i];

    geometry::RotatingCalipers rc(points);
    std::cout << rc.get_distance() << '\n';

    return 0;
}