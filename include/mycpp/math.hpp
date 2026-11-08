#pragma once

#include <concepts>
#include <cstdint>
#include <span>

namespace mycpp {

template <typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

template <Arithmetic T>
constexpr T add(T a, T b) noexcept {
    return a + b;
}

// Returns n! ; throws std::invalid_argument for n > 20 (overflows uint64_t).
std::uint64_t factorial(unsigned n);

// Sum of all elements in the span.
long long sum(std::span<const int> values) noexcept;

}  // namespace mycpp
