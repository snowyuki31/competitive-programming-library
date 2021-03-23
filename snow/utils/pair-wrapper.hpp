#pragma once

#include <limits>
#include <utility>

namespace std {

template <typename T0, typename T1>
class numeric_limits<std::pair<T0, T1>> {
public:
    static constexpr std::pair<T0, T1> min() { return {std::numeric_limits<T0>::min(), std::numeric_limits<T1>::min()}; }
    static constexpr std::pair<T0, T1> max() { return {std::numeric_limits<T0>::max(), std::numeric_limits<T1>::max()}; }
};

}  // namespace std