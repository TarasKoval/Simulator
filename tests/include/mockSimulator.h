#include "gmock/gmock.h"
#include "simulator.h"

class MockSimulator : public outdoor::ISimulator {
public:
    MOCK_METHOD2(getOutdoorMeasurments, void(std::vector<int>
            &measurements,
            const size_t &maxSize));

    MOCK_METHOD2(getInteriorMeasurments, void(std::vector<int>
            &measurements,
            const size_t &maxSize));

    MOCK_METHOD1(setInteriorControl, bool(unsigned int
            temperatureChange));
};
