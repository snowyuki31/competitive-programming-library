#pragma once
#include <vector>
#include <cassert>
#include "snow/geometry/template.hpp"

namespace geometry {

/**
 * @brief Area (多角形の面積)
 * 
 */
template< typename T >
T area(std::vector<geometry::Point<T>> points){
    assert(points.size() >= 3);

    int N = points.size();
    T res = 0;
    for (int i = 0; i < N; ++i){
        T tmp = cross(points[i], points[(i + 1) % N]);
        res += tmp;
    }

    return std::abs(res) / 2;
}

} // namespace geometry