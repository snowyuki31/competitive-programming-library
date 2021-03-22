#pragma once

#include <vector>
#include <algorithm>

namespace snow {

/**
 * @brief Divisor ($O(\sqrt{n})$)
 * 
 * @tparam T 
 * @param n 
 */
template < typename T >
std::vector<T> divisor(T n) {
    std::vector<T> ret;
    for(T i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.emplace_back(i);
            if(i * i != n) ret.emplace_back(n / i);
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

} // namespace snow