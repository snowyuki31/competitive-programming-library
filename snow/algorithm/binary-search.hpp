#pragma once

#include <utility>

namespace snow {

// [left, right)
template< typename T, typename F >
T binary_search(T left, T right, F f, T EPS = 1) {
    while(abs(right - left) > EPS){
        T mid = (right + left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }
    return right;
}

} // namespace snow