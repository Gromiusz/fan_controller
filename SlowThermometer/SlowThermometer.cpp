#include "SlowThermometer.hpp"
#include <random>

double SlowThermometer::getTemperature() const
{
    std::random_device rd{};
    // https://en.cppreference.com/w/cpp/numeric/random/random_device
    // MinGW bug - deterministic results
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{36.6, 2.0};
    return d(gen);
}

std::unique_ptr<Thermometer> SlowThermometer::clone() const 
{
    return std::make_unique<SlowThermometer>(*this);
}