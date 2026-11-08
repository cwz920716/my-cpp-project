#include "mycpp/math.hpp"

#include <gtest/gtest.h>

#include <array>
#include <stdexcept>
#include <vector>

TEST(AddTest, Integers) {
    EXPECT_EQ(mycpp::add(2, 3), 5);
    EXPECT_EQ(mycpp::add(-4, 4), 0);
}

TEST(AddTest, FloatingPoint) {
    EXPECT_DOUBLE_EQ(mycpp::add(0.5, 0.25), 0.75);
}

TEST(AddTest, IsConstexpr) {
    static_assert(mycpp::add(1, 1) == 2);
}

TEST(FactorialTest, SmallValues) {
    EXPECT_EQ(mycpp::factorial(0), 1u);
    EXPECT_EQ(mycpp::factorial(1), 1u);
    EXPECT_EQ(mycpp::factorial(5), 120u);
}

TEST(FactorialTest, LargestSupported) {
    EXPECT_EQ(mycpp::factorial(20), 2432902008176640000ull);
}

TEST(FactorialTest, ThrowsOnOverflow) {
    EXPECT_THROW(mycpp::factorial(21), std::invalid_argument);
}

TEST(SumTest, Empty) {
    EXPECT_EQ(mycpp::sum({}), 0);
}

TEST(SumTest, ArrayAndVector) {
    constexpr std::array arr{1, 2, 3, 4};
    std::vector<int> vec{10, -5, 7};
    EXPECT_EQ(mycpp::sum(arr), 10);
    EXPECT_EQ(mycpp::sum(vec), 12);
}
