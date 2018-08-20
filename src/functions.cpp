#include "functions.h"

double arithmeticMean(const std::vector<int> &inputData) {
    double sum = std::accumulate(inputData.begin(), inputData.end(), 0.0);
    double mean = sum / inputData.size();
    return mean;
}

int addControlCodeToNumber(int number, unsigned int controlCode) {
    int returnValue = number * 10 + controlCode;
    return returnValue;
}

int removeControlCodeFromNumber(int &number) {
    int controlCode = number % 10;
    number = (number - controlCode) / 10;
    return controlCode;
}
