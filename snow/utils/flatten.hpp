#pragma once
#include <vector>

namespace snow {

/**
 * @brief Flatten
 */
template < typename T >
struct Flatten {
    public:
        Flatten(T a, T b, T c = 1, T d = 1, T e = 1){
            D = e;
            C = D * d;
            B = C * c;
            A = B * b;
        }

        T get(T a, T b, T c = 0, T d = 0, T e = 0){
            T state = a * A;
            state += b * B;
            state += c * C;
            state += d * D;
            return state + e;
        }

        std::vector<T> restore(T val){
            std::vector<T> ret;
            std::vector<T> X{A, B, C, D, E};
            for(auto x : X){
                ret.emplace_back(val / x);
                val %= x;
            }
            return ret;
        }

    private:
        T A, B, C, D, E = 1;
};

} // namespace snow