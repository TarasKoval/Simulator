#include "controller.h"
#include "functions.h"

Controller::Controller(outdoor::ISimulator *rhsSimulator) : simulator(rhsSimulator), logSize(16) {}

Controller::~Controller() {}

void Controller::minimizeTemperatureDifference() {
    simulator->getOutdoorMeasurments(outdoorTemperatureLog, logSize);
    simulator->getInteriorMeasurments(indoorTemperatureLog, logSize);

    auto outdoorTemperature = arithmeticMean(outdoorTemperatureLog);
    auto indoorTemperature = arithmeticMean(indoorTemperatureLog);

    auto temperatureDifference = outdoorTemperature - indoorTemperature;
    if (temperatureDifference > 0) {
        simulator->setInteriorControl(addControlCodeToNumber(temperatureDifference, 2));
    } else if (temperatureDifference < 0) {
        simulator->setInteriorControl(addControlCodeToNumber(abs(temperatureDifference), 1));
    }
}
