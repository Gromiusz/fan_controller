#include "Thermometer.hpp"
#include "Fan.hpp"
#include "gmock/gmock.h"
#include <memory>

class ThermometerDummy : public Thermometer
{
public:
    double getTemperature() const override { return 38.0; }
    std::unique_ptr<Thermometer> clone() const override { return std::make_unique<ThermometerDummy>(*this); }
};

class FanDummy : public Fan
{
public:
    void setSpeed(int) override {}
    int getSpeed() const override { return 1000; }
    bool disable() override { return false; }
    bool enable() override {return true; }
    std::unique_ptr<Fan> clone() const override { return std::make_unique<FanDummy>(*this); }
};

class FanStub : public Fan
{
public:
    int rpm;
    FanStub() : rpm(0) {}
    void setSpeed(int _rpm) override { rpm = _rpm; }
    int getSpeed() const override { return rpm; }
    bool disable() override { rpm = 0; return false; }
    bool enable() override { rpm = 1000; return true; }
    std::unique_ptr<Fan> clone() const override { return std::make_unique<FanStub>(*this); }
};

class ThermometerMock : public Thermometer
{
public:
    MOCK_METHOD(double, getTemperature, (), (const, override));
    MOCK_METHOD(std::unique_ptr<Thermometer>, clone, (), (const, override));
};

class FanMock : public Fan
{
public:
    MOCK_METHOD(void, setSpeed, (int), (override));
    MOCK_METHOD(int, getSpeed, (), (const, override));
    MOCK_METHOD(bool, disable, (), (override));
    MOCK_METHOD(bool, enable, (), (override));
    MOCK_METHOD(std::unique_ptr<Fan>, clone, (), (const, override));
};