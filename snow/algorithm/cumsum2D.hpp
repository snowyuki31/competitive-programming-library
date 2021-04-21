#pragma once

#include <vector>

namespace snow {

/**
 * @brief Cumulative Sum (2D)
 */
template < typename T >
struct Cumsum2D {
    public:
        Cumsum2D(std::vector<std::vector<T>> const& data) : H(data.size()), W(data.front().size()), _data(H + 1, std::vector<T>(W + 1)) {
            for (int i = 1; i <= H; ++i) {
                for(int j = 1; j <= W; ++j) {
                    _data[i][j] = data[i - 1][j - 1] + _data[i - 1][j];
                }
            }
            for (int i = 0; i <= H; ++i) {
                for(int j = 0; j <= W; ++j) {
                    if(j >= 1) _data[i][j] += _data[i][j - 1];
                }
            }
        }

        /**
         * @brief get cumsum [sx, gx), [sy, gy)
         */
        T get(int sx, int sy, int gx, int gy) const {
            return _data[gx][gy] - _data[sx][gy] - _data[gx][sy] + _data[sx][sy];
        }

    private:
        int H, W;
        std::vector<std::vector<T>> _data;
};

} // namespace snow