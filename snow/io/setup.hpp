#pragma once
#include <iostream>
#include <iomanip>

namespace snow{

struct IoSetup {
    IoSetup() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(10);
    }
} iosetup;

} // namespace snow