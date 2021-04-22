#pragma once
#include <vector>
#include <utility>

namespace snow {

/**
 * @brief Weighted Doubling
 */
template < typename Monoid >
struct WeightedDoubling {
    using Data = std::pair<int, Monoid>;

    public:
        WeightedDoubling(std::vector<Data>& f, long long lim, const Monoid I = Monoid()) : N(f.size()), LIM(64 - __builtin_clzll(lim)), table(LIM, std::vector<Data>(N, Data(-1, I))), I(I){
            // Build Doubling Table.
            for (int i = 0; i < N; ++i) table[0][i] = f[i];
            for (int k = 1; k < LIM; ++k) {
                for (int i = 0; i < N; ++i) {
                    int pre = table[k - 1][i].first;
                    if(pre == -1) table[k][i].first = -1;
                    else {
                        table[k][i].first = table[k - 1][pre].first;
                        table[k][i].second = table[k - 1][i].second + table[k - 1][pre].second;
                    }
                }
            }
        }

        /**
         * @fn
         * @brief Get position after t times of operations, starting from p.
         */
        Data get(int p, long long t){
            Monoid val = I;
            for(int k = LIM - 1; k >= 0; --k) if((t >> k) & 1) {
                val = val + table[k][p].second;
                p = table[k][p].first;
                if(p == -1) break;
            }
            return {p, val};
        }

        size_t size(){
            return LIM;
        }

    private:
        const int N;
        const int LIM;
        const Monoid I;
        std::vector<std::vector<Data>> table;
};

} // namespace snow