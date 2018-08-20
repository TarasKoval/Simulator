#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/mockSimulator.h"

using ::testing::AtLeast;
using ::testing::Return;

TEST(SimulatorTest, CallSetInteriorControl) {
    MockSimulator simulator;
    EXPECT_CALL(simulator, setInteriorControl(testing::_))
            .Times(AtLeast(1))
            .WillRepeatedly(Return(true));

    EXPECT_TRUE(simulator.setInteriorControl(1));
}
