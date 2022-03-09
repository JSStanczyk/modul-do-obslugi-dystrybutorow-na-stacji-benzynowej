#pragma once
#include "fuel.hpp"
#include <string>

class Disel : public Fuel
{
private:
    float stationFuleLevel, price;
    std::string fuelName;

public:
    Disel(float a=1000, float b=3.89, std::string c="Disel");
    virtual void giveFuel(float howMuch);
    virtual void loadFuel(float howMuch);
    virtual float giveFuelStatus();
    virtual float giveFuelPrice();
    virtual std::string giveFuelName();

};