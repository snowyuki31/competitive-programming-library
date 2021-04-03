#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"
#include <iostream>
#include <vector>
#include "snow/math/matrix.hpp"
#include "atcoder/modint"

/**
 * @brief Matrix
 * 
 */
int main(){
    while(1){
        int N, M, A, B, C, T;
        std::cin >> N >> M >> A >> B >> C >> T;
        if(N == 0) break;
        
        using mint = atcoder::modint;

        mint::set_mod(M);
        std::vector<mint> init(N);
        for(int i = 0; i < N; ++i){
            int tmp;
            std::cin >> tmp;
            init[i] = tmp;
        }

        std::vector<std::vector<mint>> f(N, std::vector<mint>(N));
        for(int i = 0; i < N; ++i){
            if(i >= 1) f[i][i - 1] = A;
            f[i][i] = B;
            if(i + 1 < N) f[i][i + 1] = C;
        }

        snow::Matrix mat(f);
        snow::Matrix ret = mat.pow(T);

        std::vector<mint> ans = ret * init;
        
        std::cout << ans[0].val();
        for(int i = 1; i < N; ++i) std::cout << ' ' << ans[i].val();
        std::cout << '\n';
    }
}