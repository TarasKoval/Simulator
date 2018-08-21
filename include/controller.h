#ifndef SIMULATOR_CONTROLER_H
#define SIMULATOR_CONTROLER_H

#include "simulator.h"

class Controller {
private:
    outdoor::ISimulator *simulator;
    size_t logSize;
    std::vector<int> outdoorTemperatureLog;
    std::vector<int> indoorTemperatureLog;

public:
    explicit Controller(outdoor::ISimulator *rhsSimulator);

    ~Controller();

    void minimizeTemperatureDifference();
};

#endif //SIMULATOR_CONTROLER_H
