#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/mockSimulator.h"
#include "controller.h"

using ::testing::AtLeast;
using ::testing::Return;

TEST(SimulatorTest, CallSetInteriorControl) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, setInteriorControl(testing::_))
            .Times(AtLeast(1))
            .WillRepeatedly(Return(true));

    EXPECT_TRUE(simulator.setInteriorControl(1));
}

class ControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
        simulator = new MockSimulator;
    }

    void TearDown() override {
        delete simulator;
    }

    MockSimulator *simulator;
    std::vector<int> temperature15{14, 16, 17, 13, 15};
    std::vector<int> temperature17{18, 16, 21, 13, 17};
};

TEST_F(ControllerTest, DifferenceCalculation) {

    EXPECT_CALL(*simulator, getOutdoorTemperatureLog(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(*simulator, getIndoorTemperatureLog(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature15));
    EXPECT_CALL(*simulator, setInteriorControl(2)).Times(1);

    Controller controller(simulator);
    controller.minimizeTemperatureDifference();
}
