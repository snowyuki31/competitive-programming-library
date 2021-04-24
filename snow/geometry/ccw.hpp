#pragma once
#include "snow/geometry/template.hpp"

namespace geometry {

enum CCW_RESULT { CCW = +1, CW = -1, BACK = +2, FRONT = -2, ON = 0 };

/**
 * @brief Counter-Clockwise
 * 
 */
template< typename T >
int ccw(Point<T> A, Point<T> B, Point<T> C){
    B -= A, C -= A;
    if(cross(B, C) > EPS) return CCW;
    if(cross(B, C) < -EPS) return CW;
    if(dot(B, C) < 0) return BACK;
    if(norm(B) < norm(C)) return FRONT;
    return ON;
}

} // namespace geometry