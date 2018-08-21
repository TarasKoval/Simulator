#include "controller.h"
#include "functions.h"

Controller::Controller(outdoor::ISimulator *rhsSimulator) : simulator(rhsSimulator), logSize(16) {}

Controller::~Controller() = default;

void Controller::minimizeTemperatureDifference() {
    simulator->getOutdoorMeasurements(outdoorTemperatureLog, logSize);
    simulator->getInteriorMeasurements(indoorTemperatureLog, logSize);

    auto outdoorTemperature = arithmeticMean(outdoorTemperatureLog);
    auto indoorTemperature = arithmeticMean(indoorTemperatureLog);

    auto temperatureDifference = outdoorTemperature - indoorTemperature;
    if (temperatureDifference > 0) {
        simulator->setInteriorControl(addControlCodeToNumber(static_cast<unsigned int>(temperatureDifference), 2));
    } else if (temperatureDifference < 0) {
        simulator->setInteriorControl(addControlCodeToNumber(static_cast<unsigned int>(abs(temperatureDifference)), 1));
    }
}
