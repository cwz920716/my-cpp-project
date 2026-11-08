#include <array>
#include <iostream>

#include "mycpp/math.hpp"

int main() {
    constexpr std::array values{1, 2, 3, 4, 5};
    std::cout << "add(2, 3) = " << mycpp::add(2, 3) << '\n'
              << "factorial(10) = " << mycpp::factorial(10) << '\n'
              << "sum({1..5}) = " << mycpp::sum(values) << '\n';
    return 0;
}
