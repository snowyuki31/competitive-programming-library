#pragma once
#include <vector>
#include <algorithm>

namespace snow {
    /**
     * @brief Base Conversion
     * 
     */
    template <typename T>
    std::vector<T> convert_base(T val, T base){
        std::vector<T> ret;
        T tmp = 1, base_ = abs(base);
        while(val){
            T dig = val * tmp % base_;
            if(dig < 0) dig += base_;
            ret.emplace_back(dig);

            val -= dig * tmp;
            val /= base_;
            tmp *= base / base_;
        }
        if(ret.empty()) ret.emplace_back(0);
        std::reverse(ret.begin(), ret.end());

        return ret;
    };
};