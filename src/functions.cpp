#include "functions.h"

int arithmeticMean(const std::vector<int> &inputData) {
    int sum = std::accumulate(inputData.begin(), inputData.end(), 0);
    int mean = sum / static_cast<int>(inputData.size());
    return mean;
}

unsigned int addControlCodeToNumber(unsigned int number, unsigned int controlCode) {
    unsigned int returnValue = number * 10 + controlCode;
    return returnValue;
}

unsigned int removeControlCodeFromNumber(unsigned int &number) {
    unsigned int controlCode = number % 10;
    number = (number - controlCode) / 10;
    return controlCode;
}
