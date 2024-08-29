#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Controller.hpp"
#include "mocks.hpp"


struct ControllerDummyTest : public ::testing::Test
{
    ThermometerDummy t;
    FanDummy f;
    double targetTemperature = 36.6;
    double tolerance = .5;

    Controller controller;
    ControllerDummyTest() : controller{t, f, targetTemperature, tolerance, nullptr} {}
};

struct ControllerStubTest : public ::testing::Test
{
    ThermometerDummy t;
    FanStub f;
    double targetTemperature = 36;
    double tolerance = .5;

    // Controller controller;
    //ControllerStubTest() : controller{t, f, targetTemperature, tolerance, nullptr} {}
};

struct ControllerTest : public ::testing::Test
{
    ThermometerDummy t;
    TinyFan f;
    double targetTemperature = 36;
    double tolerance = .5;

    // Controller controller;
    //ControllerStubTest() : controller{t, f, targetTemperature, tolerance, nullptr} {}
};

//////////////////

TEST_F(ControllerDummyTest, printInfo)
{
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: -1.00\nTarget Temp: 36.60\nFan speed: 1000\n");
}

TEST_F(ControllerStubTest, updateRpm3000)
{
    double targetTemperature = 35;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 35.00\nFan speed: 4000\n");
}

TEST_F(ControllerStubTest, updateRpm1600)
{
    double targetTemperature = 37.4;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 37.40\nFan speed: 1600\n");
}

TEST_F(ControllerStubTest, updateRpm1000)
{
    double targetTemperature = 38.5;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 38.50\nFan speed: 1000\n");
}

TEST_F(ControllerStubTest, updateRpm1000v2)
{
    double targetTemperature = 37.5;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 37.50\nFan speed: 1000\n");
}

TEST_F(ControllerStubTest, updateRpm0)
{
    double targetTemperature = 38.6;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 38.60\nFan speed: 0\n");
}

/////////////////////////////////////////////////////////////////////

TEST_F(ControllerTest, updateRpm3000)
{
    double targetTemperature = 36;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    controller.updateRpm();
    auto result = controller.printInfo();
    ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 36.00\nFan speed: 3000\n");
}

TEST_F(ControllerTest, updateRpmThrow)
{
    double targetTemperature = 35.99;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    // controller.updateRpm();
    ASSERT_THROW(controller.updateRpm(), std::invalid_argument);
    // auto result = controller.printInfo();
    // ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 36.01\nFan speed: 3000\n");
}

TEST_F(ControllerTest, updateRpmNotThrow)
{
    double targetTemperature = 36.0;
    Controller controller{t, f, targetTemperature, tolerance, nullptr};

    // controller.updateRpm();
    ASSERT_NO_THROW(controller.updateRpm());
    // auto result = controller.printInfo();
    // ASSERT_EQ(result, "\nActual Temp: 38.00\nTarget Temp: 36.01\nFan speed: 3000\n");
}

TEST(ControllerwithMocks, updateRpm)
{
    testing::NiceMock<ThermometerMock> t;
    testing::NiceMock<FanMock > f;
    double tolerance = .5;
    double targetTemperature = 36.0;
    EXPECT_CALL(t, clone()).WillOnce(testing::Return(std::make_unique<ThermometerMock>()));
    EXPECT_CALL(f, clone()).WillOnce(testing::Return(std::make_unique<FanMock>()));
    
    Controller controller{t, f, targetTemperature, tolerance, nullptr};
    
}


