#ifndef OUTDOOR_SIMULATOR_H
#define OUTDOOR_SIMULATOR_H

#include <vector>
#include <cstdio>

class Simulator {
public:
    virtual ~Simulator() = default;

    virtual void getOutdoorTemperatureLog(std::vector<int> &measurements, const size_t &maxSize) = 0;

    virtual void getIndoorTemperatureLog(std::vector<int> &measurements, const size_t &maxSize) = 0;

    // Set new control value for interior controller.
    // Zero input value means "turn off".
    // Return is the actual value valid.
    virtual bool setInteriorControl(unsigned int controlCode) = 0;
};


#endif//OUTDOOR_SIMULATOR_H
