#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockSimulator.h"
#include "controller.h"

class ControllerTest : public ::testing::Test {
protected:
    std::vector<int> temperature15{14, 16, 17, 13, 15};
    std::vector<int> temperature17{18, 16, 21, 13, 17};
};

TEST_F(ControllerTest, PositiveDifference) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, getOutdoorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(simulator, getInteriorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature15));
    EXPECT_CALL(simulator, setInteriorControl(22)).
            Times(1);

    Controller controller(&simulator);
    controller.minimizeTemperatureDifference();
}

TEST_F(ControllerTest, ZeroDifference) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, getOutdoorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(simulator, getInteriorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(simulator, setInteriorControl(testing::_)).
            Times(0);

    Controller controller(&simulator);
    controller.minimizeTemperatureDifference();
}

TEST_F(ControllerTest, NegativeDifference) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, getOutdoorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature15));
    EXPECT_CALL(simulator, getInteriorMeasurements(testing::_, testing::_))
            .Times(1)
            .WillOnce(testing::SetArgReferee<0>(temperature17));
    EXPECT_CALL(simulator, setInteriorControl(21)).
            Times(1);

    Controller controller(&simulator);
    controller.minimizeTemperatureDifference();
}
