#include "Controller.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

Controller::Controller(const Thermometer& _thermometer,
                       const Fan& _fan,
                       double target,
                       double _tolerance,
                       const std::shared_ptr<LcdDisplay>& display_ptr) : 
                       thermometer(_thermometer.clone()), 
                       fan(_fan.clone()), 
                       targetTemperature(target), 
                       tolerance(_tolerance), 
                       lcdDisplay(display_ptr),
                       actualTemp(-1)
{}

void Controller::updateRpm() 
{
    actualTemp = thermometer->getTemperature();
    auto differenceTemp = std::abs(actualTemp - targetTemperature);
    fan->enable();
    if(differenceTemp > tolerance)
    {
        if(targetTemperature > actualTemp)
        {
            fan->disable();
        }
        else
        {
            fan->setSpeed(1000+differenceTemp * 1000);
            
        }
    }
}

std::string Controller::printInfo() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << actualTemp;
    std::string actualTempSTR = oss.str();

    oss.clear();
    oss.str("");
    oss << std::fixed << std::setprecision(2) << targetTemperature;
    std::string targetTemperatureSTR = oss.str();

    const std::string output = 
    "\nActual Temp: " + actualTempSTR +
    "\nTarget Temp: " + targetTemperatureSTR +
    "\nFan speed: " + std::to_string(fan->getSpeed()) + "\n";

    return output;
}

void Controller::displayInfo() const 
{
    if(lcdDisplay)
    {
        lcdDisplay->print(printInfo());
    }
}