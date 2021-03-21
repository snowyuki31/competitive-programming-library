#pragma once

#include <time.h>
#include <vector>
#include <string>
#include "snow/utils/xorshift.hpp"

namespace snow {

/* refference : https://qiita.com/keymoon/items/11fac5627672a6d6a9f6 */
struct RollingHash {
    using ull = unsigned long long;
    const unsigned long long BASE;
    snow::xorShift128 xs;

    const ull MASK30 = (1ull << 30) - 1;
    const ull MASK31 = (1ull << 31) - 1;
    const ull MOD = (1ull << 61) - 1;
    const ull MASK61 = MOD;
    const ull POSITIVIZER = MOD * ((1ull << 3) - 1);

    std::vector<ull> hashed, power;

    RollingHash(const std::string& s) : hashed(s.size() + 1, 0), power(s.size() + 1, 0), xs(time(NULL)), BASE(xs()) {
        power[0] = 1;
        for(int i = 0; i < s.size(); ++i) power[i + 1] = CalcMod(Mul(power[i], BASE));
        for(int i = 0; i < s.size(); ++i) hashed[i + 1] = CalcMod(Mul(hashed[i], BASE) + s[i]);
    }

    //[L, r)
    ull get(int l, int r){
        return CalcMod(hashed[r] + POSITIVIZER - Mul(hashed[l], power[r - l]));
    }

    ull Mul(ull a, ull b){
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30;
        ull midd = mid & MASK30;
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    ull CalcMod(ull x){
        ull xu = x >> 61;
        ull xd = x & MASK61;
        ull res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }
};

}