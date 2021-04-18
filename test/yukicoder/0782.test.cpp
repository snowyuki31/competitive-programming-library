#define PROBLEM "https://yukicoder.me/problems/no/782"
#include <iostream>

#include "snow/math/convert-base.hpp"

/**
 * @brief Conversion Base (negative base)
 * 
 */
int main() {
    int T, B;
    std::cin >> T >> B;
    while(T--){
        int N;
        std::cin >> N;
        auto ret = snow::convert_base(N, B);
        for(auto r : ret) std::cout << r;
        std::cout << '\n';
    }
    
    return 0;
}