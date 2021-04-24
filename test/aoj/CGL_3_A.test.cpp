#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#include <iostream>
#include <vector>
#include "snow/geometry/area.hpp"

/**
 * @brief Area
 */
int main() {
    int N;
    std::cin >> N;
    std::vector<geometry::Point<long double>> points(N);
    for (int i = 0; i < N; ++i) std::cin >> points[i];
    long ans = geometry::area(points) * 10;
    int dec = ans % 10;
    ans /= 10;

    std::cout << ans << '.' << dec << '\n';

    return 0;
}