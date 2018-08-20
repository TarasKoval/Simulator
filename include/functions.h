#ifndef RRORELCALC_FUNCTIONS_H
#define RRORELCALC_FUNCTIONS_H

#include <vector>
#include <zconf.h>
#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>

double arithmeticMean(const std::vector<int> &inputData);

int addControlCodeToNumber(int number, unsigned int controlCode);

int removeControlCodeFromNumber(int &number);

#endif //RRORELCALC_FUNCTIONS_H
