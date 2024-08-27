#include "Controller.hpp"
#include <iostream>

Controller::Controller(const Thermometer& _thermometer,
                       const Fan& _fan,
                       double target,
                       double _tolerance,
                       const std::shared_ptr<LcdDisplay>& display_ptr) : 
                       thermometer(_thermometer.clone()), 
                       fan(_fan.clone()), 
                       targetTemperature(target), 
                       tolerance(_tolerance), 
                       lcdDisplay(display_ptr)
{}


void Controller::updateRpm() 
{
    auto actualTemp = thermometer->getTemperature();
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

void Controller::displayInfo() const 
{
    if(lcdDisplay)
    {
        const std::string output = std::to_string(fan->getSpeed());
        lcdDisplay->print(output);
    }
}
