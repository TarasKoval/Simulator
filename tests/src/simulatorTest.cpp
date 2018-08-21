#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockSimulator.h"
#include "controller.h"

class ControllerTest : public ::testing::Test {
protected:
    std::vector<int> temperature15{14, 16, 17, 13, 15};
    std::vector<int> temperature17{18, 16, 21, 13, 17};
};

TEST_F(ControllerTest, DifferenceCalculation) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, getOutdoorMeasurments(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(simulator, getInteriorMeasurments(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature15));
    EXPECT_CALL(simulator, setInteriorControl(22)).Times(1);

    Controller controller(&simulator);
    controller.minimizeTemperatureDifference();
}
