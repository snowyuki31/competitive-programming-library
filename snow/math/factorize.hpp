#pragma once

#include <map>

namespace snow {

/**
 * @brief Prime Factorization - $O(\sqrt{n})$
 * 
 * @tparam T 
 * @param v 
 */
template < typename T >
std::map<T, int> factorize(T v){
    std::map<T, int> ret;
    for(T i = 2; i * i <= v; ++i){
        while(!(v % i)) ret[i]++, v /= i;
    }
    if(v != 1) ret[v]++;
    return ret;
}

} // namespace snow