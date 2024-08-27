#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Controller.hpp"


// struct ControllerTest : public ::testing::Test
// {
//     //ThermometerDummy t;
//     TinyFan f;
//     double targetTemperature = 36.6;
//     double tolerance = .5;

//     Controller oldController;
//     //ControllerTest() : oldController{t, f, targetTemperature, tolerance, nullptr} {}
// };

// TEST_F(ControllerTest, updateRpm)
// {
//     oldController.updateRpm();
//     auto new_fan_speed = f.getSpeed();
//     ASSERT_EQ(new_fan_speed, 2400);
// }