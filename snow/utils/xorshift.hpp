#pragma once

namespace snow {

struct xorShift128 {
    unsigned long long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    xorShift128(unsigned long long seed = 0) {
        w ^= seed;
    }
    unsigned long long operator()() {
        unsigned long long t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
};

} // namespace snow