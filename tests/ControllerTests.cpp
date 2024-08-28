#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Controller.hpp"
#include "mocks.hpp"


struct ControllerTest : public ::testing::Test
{
    ThermometerDummy t;
    FanStub f;
    double targetTemperature = 36.6;
    double tolerance = .5;

    Controller oldController;
    ControllerTest() : oldController{t, f, targetTemperature, tolerance, nullptr} {}
};


TEST_F(ControllerTest, updateRpm)
{
    oldController.updateRpm();
    auto new_fan_speed = oldController.printInfo();
    ASSERT_EQ(new_fan_speed, "2400");
}