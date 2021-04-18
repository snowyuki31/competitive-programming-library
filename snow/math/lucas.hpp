#pragma once
#include <algorithm>
#include "snow/math/convert-base.hpp"

namespace snow {

/**
 * @brief Lucas's theorem (Binomial Coefficient mod p) 
 * 
 */
int lucas(int m, int n, int p){
    auto m_ = convert_base(m, p);
    int l = m_.size();
    auto n_ = convert_base(n, p, l);

    /**
     * @fn
     * Calculate binomial coefficient in a naive way.
     * 
     * @brief Calculate binomial coef.
     * 
     */
    auto binom = [](int m, int n)->int {
        if(m < n) return 0;
        int ret = 1;
        for (int i = 1; i <= m; ++i) ret *= i;
        for (int i = 1; i <= n; ++i) ret /= i;
        for (int i = 1; i <= m - n; ++i) ret /= i;
        return ret;
    };

    int ret = 1;
    for(int i = 0; i < l; ++i) ret *= binom(m_[i], n_[i]), ret %= p;
    return ret;
}


} // namespace snow