#include "controller.h"
#include "functions.h"

Controller::Controller(Simulator *rhsSimulator) : simulator(rhsSimulator), logSize(16) {}

Controller::~Controller() {}

void Controller::minimizeTemperatureDifference() {
    simulator->getOutdoorTemperatureLog(outdoorTemperatureLog, logSize);
    simulator->getIndoorTemperatureLog(indoorTemperatureLog, logSize);

    auto outdoorTemperature = arithmeticMean(outdoorTemperatureLog);
    auto indoorTemperature = arithmeticMean(indoorTemperatureLog);

    auto temperatureDifference = outdoorTemperature - indoorTemperature;
    if (temperatureDifference >= 0) {
        simulator->setInteriorControl(temperatureDifference);
    } else {
        simulator->setInteriorControl(temperatureDifference * -1);
    }
}
