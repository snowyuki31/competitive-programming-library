#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include <utility>
#include "snow/geometry/ccw.hpp"

/**
 * @brief Counter-Clockwise
 */
int main() {
    geometry::Point<long double> A, B;
    std::cin >> A >> B;
    int Q;
    std::cin >> Q;
    while(Q--){
        geometry::Point<long double> C;
        std::cin >> C;

        auto ret = geometry::ccw(A, B, C);

        if(ret == geometry::CCW) std::cout << "COUNTER_CLOCKWISE" << '\n';
        if(ret == geometry::CW) std::cout << "CLOCKWISE" << '\n';
        if(ret == geometry::BACK) std::cout << "ONLINE_BACK" << '\n';
        if(ret == geometry::FRONT) std::cout << "ONLINE_FRONT" << '\n';
        if(ret == geometry::ON) std::cout << "ON_SEGMENT" << '\n';  
    }
    return 0;
}