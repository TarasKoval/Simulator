#include "gtest/gtest.h"
#include "functions.h"

TEST(MathExpectationTest, TestOne) {
    const std::vector<ulong> inputData = {123, 345, 567};
    auto result = mathExpectation(inputData, 2);
    EXPECT_NEAR(234, result, 0.001);
}