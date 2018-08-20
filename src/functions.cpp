#include "functions.h"

double arithmeticMean(const std::vector<int> &inputData) {
    double sum = std::accumulate(inputData.begin(), inputData.end(), 0.0);
    double mean = sum / inputData.size();
    return mean;
}
