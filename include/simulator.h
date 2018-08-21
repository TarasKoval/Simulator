#ifndef OUTDOOR_SIMULATOR_H
#define OUTDOOR_SIMULATOR_H

#include <vector>
#include <cstdlib>

namespace outdoor {
    class ISimulator {
    public:
        virtual ~ISimulator() = default;

        virtual void getOutdoorMeasurements(std::vector<int> &measurements, const size_t &maxSize) = 0;

        virtual void getInteriorMeasurements(std::vector<int> &measurements, const size_t &maxSize) = 0;

        // Set new control value for interior controller.
        // Zero input value means "turn off".
        // Return is the actual value valid.
        virtual bool setInteriorControl(unsigned int controlCode) = 0;
    };
}//namespace outdoor

#endif//OUTDOOR_SIMULATOR_H
