#include "Controller.hpp"
#include "Thermometer.hpp"
#include "SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <iostream>

int main()
try {
    SlowThermometer t;
    TinyFan f;
    double targetTemperature = 36.6;
    double tolerance = .5;
    auto display_ptr = std::make_shared<LcdDisplay>();

    // Controller oldController{t, f, targetTemperature, tolerance, nullptr};
    // oldController.updateRpm();
    // oldController.displayInfo();

    Controller newController{t, f, targetTemperature, tolerance, display_ptr};
    newController.updateRpm();
    newController.displayInfo();

    return 0;
} catch (const std::exception & e) {
    std::cerr << e.what() << '\n';
    return -1;
}

