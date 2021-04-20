#pragma once
#include <time.h>

namespace snow {

/**
 * @brief XorShift (Random Number Generator)
 */
struct xorShift128 {
    unsigned long long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    xorShift128(unsigned long long seed = time(NULL)) {
        w ^= seed;
    }
    unsigned long long operator()() {
        unsigned long long t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    /**
     * @brief Get random number in [l, r).
     */
    unsigned long long operator()(unsigned long long l, unsigned long long r) {
        w = this->operator()();
        return w % (r - l) + l;
    }
};

} // namespace snow