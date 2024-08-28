#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <cmath>


class Controller {
    std::unique_ptr<Thermometer> thermometer;
    std::unique_ptr<Fan> fan;
    double targetTemperature;
    double tolerance;
    std::shared_ptr<LcdDisplay> lcdDisplay;
    double actualTemp;

public:
    Controller(const Thermometer&, const Fan&, double, double, const std::shared_ptr<LcdDisplay>&);
    void updateRpm();
    std::string printInfo() const;
    void displayInfo() const;
};