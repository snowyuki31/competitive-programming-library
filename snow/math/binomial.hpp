#pragma once

#include <vector>

namespace snow {

/**
 * @brief Binomial Coefficient - $\binom{n}{k}$ 前処理$O(n)$, $O(1)$
 * @param N max N
 * @tparam mint 
 */
template < typename mint >
struct Binomial {
    public:
        Binomial(int N) : _N(N + 1), _M(mint::mod()), D(std::min(_N, _M)), fac(D), finv(D), inv(D) {
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < D; ++i) {
                fac[i] = fac[i - 1] * i;
                inv[i] = _M - inv[_M % i] * (_M / i);
                finv[i] = finv[i - 1] * inv[i];
            }
        }

        /**
         * @brief Calculate nCk
         * 
         * @param n 
         * @param k 
         */
        mint get(int n, int k){
            if (n < k) return 0;
            if (n < 0 || k < 0) return 0;
            if (n >= _M) return get(n % _M, k % _M) * get(n / _M, k / _M); // Lucas's theorem.
            return fac[n] * finv[k] * finv[n - k];
        }

    protected:
        const int _N;
        const int _M;
        const int D;
        std::vector<mint> fac, finv, inv;
};

} // namespace snow