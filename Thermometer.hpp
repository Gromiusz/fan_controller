#pragma once
#include <memory>

class Thermometer
{
public:
    virtual ~Thermometer() = 0;
    virtual double getTemperature() const = 0;
    virtual std::unique_ptr<Thermometer> clone() const = 0;
};

class ThermometerDummy : public Thermometer
{
public:
    double getTemperature() const override;
    std::unique_ptr<Thermometer> clone() const override;
};