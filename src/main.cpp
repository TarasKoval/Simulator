#include <iostream>
#include "functions.h"

int main() {
    const std::vector<ulong> inputData = {123, 345, 567};
    auto result = mathExpectation(inputData, 2);
    std::cout << result << std::endl;
}