#pragma once
#include <vector>
#include "snow/math/matrix.hpp"

namespace snow{

/**
 * @brief Gauss Jordan's Elimination
 * @details solve Ax = b
 * @tparam T 
 * @param mat 
 * @param b 
 */
template < typename T >
std::vector<T> gauss_jordan(const Matrix<T>& A, const std::vector<T>& b){
    int N = A.size();
    Matrix B(A);
    for (int i = 0; i < N; ++i) B[i].emplace_back(b[i]);

    for (int i = 0; i < N; ++i){
        int pivot = i;
        for (int j = i; j < N; ++j){
            
        }
    }

    return {};
}

} // namespace snow