#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

Fan::~Fan() {}

TinyFan::TinyFan() {
    rpm = 0;
}

// Fan::Fan(Fan&& other) : rpm(std::move(other.rpm)) {}

// Fan::Fan(const Fan& other) : rpm(other.rpm) {}

void TinyFan::setSpeed(int newRpm) {
    if ((newRpm < 1000 and newRpm != 0) or newRpm > 3000) {
        throw std::invalid_argument("Invalid speed");
    }
    auto difference = std::abs(newRpm - rpm);
    for (auto i = 0; i < difference; ++i) {
        if (newRpm - rpm > 0) {
            rpm++;
        } else {
            rpm--;
        }
    }
}

int TinyFan::getSpeed() const {
    return rpm;
}

bool TinyFan::disable() {
    rpm = 0;
    return true;
}

bool TinyFan::enable() {
    rpm = 1000;
    return true;
}

std::unique_ptr<Fan> TinyFan::clone() const {
    return std::make_unique<TinyFan>(*this);
}