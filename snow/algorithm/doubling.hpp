#pragma once
#include <vector>

namespace snow {

/**
 * @brief Doubling
 */
template < typename T >
struct Doubling {
    public:
        Doubling(std::vector<T>& f, long long lim) : N(f.size()), LIM(64 - __builtin_clzll(lim)), table(LIM, std::vector<T>(N, -1)){
            // Built Doubling Table.
            for (int i = 0; i < N; ++i) table[0][i] = f[i];
            for (int k = 1; k < LIM; ++k) {
                for (int i = 0; i < N; ++i) {
                    if(table[k - 1][i] == -1) table[k][i] = -1;
                    else table[k][i] = table[k - 1][table[k - 1][i]];
                }
            }
        }

        /**
         * @fn
         * @brief Get position after t times of operations, starting from p.
         */
        T get(T p, long long t){
            for(int k = LIM - 1; k >= 0; --k) if((t >> k) & 1) p = table[k][p];
            return p;
        }

        size_t size(){
            return LIM;
        }

    private:
        const int N;
        const int LIM;
        std::vector<std::vector<T>> table;
};

} // namespace snow