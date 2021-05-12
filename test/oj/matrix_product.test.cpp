#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <iostream>
#include "snow/math/matrix.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

/**
 * @brief Matrix Product
 * 
 */
int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<mint>> A(N, std::vector<mint>(M));
    std::vector<std::vector<mint>> B(M, std::vector<mint>(K));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            int t;
            std::cin >> t;
            A[i][j] = t;
        }
    }
    for (int j = 0; j < M; ++j){
        for (int k = 0; k < K; ++k){
            int t;
            std::cin >> t;
            B[j][k] = t;
        }
    }
    snow::Matrix<mint> a(A), b(B);

    auto ret = a * b;

    for(int i = 0; i < N; ++i){
        std::cout << ret[i][0].val();
        for(int k = 0; k < K; ++k) if(k) std::cout << " " << ret[i][k].val();
        std::cout << '\n';
    }
    
    return 0;
}