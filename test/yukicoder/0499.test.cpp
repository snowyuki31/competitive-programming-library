#define PROBLEM "https://yukicoder.me/problems/no/499"
#include <iostream>

#include "snow/math/convert-base.hpp"

/**
 * @brief Conversion Base (base 7)
 * 
 */
int main() {
    int N;
    std::cin >> N;
    auto ret = snow::convert_base(N, 7);
    for(auto r : ret) std::cout << r;
    std::cout << '\n';

    return 0;
}