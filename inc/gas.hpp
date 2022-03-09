#pragma once
#include "fuel.hpp"
#include <string>

class Gas : public Fuel
{
private:
    float stationFuleLevel, price;
    std::string fuelName;

public:
    Gas(float a=1000, float b=2.48, std::string c="Gaz");
    virtual void giveFuel(float howMuch);
    virtual void loadFuel(float howMuch);
    virtual float giveFuelStatus();
    virtual float giveFuelPrice();
    virtual std::string giveFuelName();

};