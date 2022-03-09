#pragma once
#include "fuel.hpp"

class Petrol_95 : public Fuel
{
private:
    float stationFuleLevel, price;
public:
    Petrol_95(float a=80000, float b= 3.96);
    virtual void getFuel(float howMuch);
    virtual void loadFuel(float howMuch);
};