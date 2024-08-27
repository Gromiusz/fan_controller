#pragma once
#include <memory>
#include "Thermometer.hpp"

class SlowThermometer : public Thermometer
{
public:
    //SlowThermometer();
    double getTemperature() const override;
    std::unique_ptr<Thermometer> clone() const override;
};
