#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Fan.hpp"

struct BasicFanTest : public ::testing::Test{
    Fan f;
    double disabledRpm = 0;
    double minRpm = 1000;
    double maxRpm = 3000;
};

TEST_F(BasicFanTest, NewFanDisabled)
{
    ASSERT_EQ(f.getSpeed(), disabledRpm);
}

TEST_F(BasicFanTest, getSpeed)
{
    f.setSpeed(minRpm);
    ASSERT_EQ(f.getSpeed(), minRpm);

    f.setSpeed(maxRpm);
    ASSERT_EQ(f.getSpeed(), maxRpm);

    f.setSpeed(disabledRpm);
    ASSERT_EQ(f.getSpeed(), disabledRpm);
}

TEST_F(BasicFanTest, setSpeed)
{
    auto before = f.getSpeed();
        
    ASSERT_THROW(f.setSpeed(minRpm - 1), std::invalid_argument);
    ASSERT_EQ(f.getSpeed(), before);

    ASSERT_THROW(f.setSpeed(maxRpm + 1), std::invalid_argument);
    ASSERT_EQ(f.getSpeed(), before);
}