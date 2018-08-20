#include "gmock/gmock.h"
#include "simulator.h"

class MockSimulator : public Simulator {
public:
    MOCK_METHOD2(getOutdoorTemperatureLog, void(std::vector<int>
            &measurements,
            const size_t &maxSize));

    MOCK_METHOD2(getIndoorTemperatureLog, void(std::vector<int>
            &measurements,
            const size_t &maxSize));

    MOCK_METHOD1(setInteriorControl, bool(unsigned int
            controlCode));
};
