#pragma once
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include "snow/io/setup.hpp"
#include "snow/geometry/geometry"
#include "snow/geometry/convex-hull.hpp"

namespace geometry {

/**
 * @brief Rotating-Calipers (Furthest point pair)
 * 
 */
template< typename T >
struct RotatingCalipers{
    public:
        RotatingCalipers(const std::vector<geometry::Point<T>>& points) {
            assert(points.size() > 1);
            CH = geometry::convex_hull(points);
            _rotating_calipers();
        }

        T get_distance() { return dist; }

        std::pair<geometry::Point<T>, geometry::Point<T>> get_pair(){
            return {CH[px], CH[py]};
        }

    private:
        std::vector<geometry::Point<T>> CH;
        T dist;
        int px, py;

        void _rotating_calipers(){
            int N = CH.size();
            if(N == 2){
                dist = abs(CH[0] - CH[1]);
                px = 0, py = 1;
                return;
            }

            int i = 0, j = 0;

            // Get x-axis farthest point pair.
            for(int k = 0; k < N; ++k){
                if(CH[i] >= CH[k]) i = k;
                if(CH[j] < CH[k]) j = k;
            }

            // Maximize distance as rotating.
            T res = 0;
            int si = i, sj = j;
            while(i != sj || j != si){
                if(res < abs(CH[i] - CH[j])) res = abs(CH[i] - CH[j]);

                if(cross(CH[(i + 1) % N] - CH[i], CH[(j + 1) % N] - CH[j]) < 0){
                    i = (i + 1) % N;
                }else{
                    j = (j + 1) % N;
                }
            }

            dist = res;
            px = si, py = sj;
        }
};

} // namespace geometry