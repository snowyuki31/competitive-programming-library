#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2320"
#include <iostream>
#include <string>
#include "snow/io/helper.hpp"
#include "snow/utils/flatten.hpp"
#include "snow/algorithm/doubling.hpp"

/**
 * @brief Doubling
 * 
 */

void solve(int H, int W, long long L) {
    std::vector<std::string> grid(H);
    std::cin >> grid;

    std::vector<int> f(H * W * 4, -1);
    snow::Flatten F(H, W, 4);

    std::vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
    std::string dir = "ESWN";

    int si, sj, sk;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(grid[i][j] != '#' and grid[i][j] != '.'){
                char& c = grid[i][j];
                si = i, sj = j;
                if(c == 'N') sk = 3;
                if(c == 'E') sk = 0;
                if(c == 'S') sk = 1;
                if(c == 'W') sk = 2;
                c = '.';
            }
        }
    }

    // k = 0 : (0, +1), 1 : (+1, 0), 2 : (0, -1), 3 : (-1, 0)
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            for (int k = 0; k < 4; ++k){
                if(grid[i][j] == '#') continue;

                int k_ = k;
                for(int _ = 0; _ < 4; ++_){
                    int ni = i + dx[k_], nj = j + dy[k_];
                    if(ni < 0 or ni >= H or nj < 0 or nj >= W or grid[ni][nj] == '#'){
                        ++k_;
                        k_ %= 4;
                        continue;
                    }
                    f[F.get(i, j, k)] = F.get(ni, nj, k_);
                    break;
                }
            }
        }
    }

    snow::Doubling doubling(f, L);
    int ret = doubling.get(F.get(si, sj, sk), L);
    auto ans = F.restore(ret);
    print(ans[0] + 1, ans[1] + 1, dir[ans[2]]);
}

int main(){
    while(1){
        int H, W;
        long long L;
        std::cin >> H >> W >> L;
        if(H == 0) break;
        solve(H, W, L);
    }
    return 0;
}