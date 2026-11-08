#include "mycpp/math.hpp"

#include <numeric>
#include <stdexcept>

namespace mycpp {

std::uint64_t factorial(unsigned n) {
    if (n > 20) {
        throw std::invalid_argument("factorial: n > 20 overflows uint64_t");
    }
    std::uint64_t result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long sum(std::span<const int> values) noexcept {
    return std::accumulate(values.begin(), values.end(), 0LL);
}

}  // namespace mycpp
