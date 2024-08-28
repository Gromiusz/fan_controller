#pragma once
#include <memory>

class Fan
{
public:
    virtual ~Fan() = 0;
    virtual void setSpeed(int) = 0;
    virtual int getSpeed() const = 0;
    virtual bool disable() = 0;
    virtual bool enable() = 0;
    virtual std::unique_ptr<Fan> clone() const = 0;
};

class TinyFan : public Fan
{
    int rpm;

public:
    TinyFan();
    // Fan(const Fan&);
    // Fan(Fan&&);

    void setSpeed(int) override;
    int getSpeed() const override;
    bool disable() override;
    bool enable() override;
    std::unique_ptr<Fan> clone() const override;
};

// class FanDummy : public Fan
// {
// public:
//     void setSpeed(int) override;
//     int getSpeed() const override;
//     bool disable() override;
//     bool enable() override;
//     std::unique_ptr<Fan> clone() const override;
// };