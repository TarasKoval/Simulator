#ifndef RRORELCALC_FUNCTIONS_H
#define RRORELCALC_FUNCTIONS_H

#include <vector>
#include <zconf.h>
#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>

int arithmeticMean(const std::vector<int> &inputData);

unsigned int addControlCodeToNumber(unsigned int number, unsigned int controlCode);

unsigned int removeControlCodeFromNumber(unsigned int &number);

#endif //RRORELCALC_FUNCTIONS_H
