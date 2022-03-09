#pragma once
#include "fuel.hpp"
#include <string>

class Petrol : public Fuel
{
private:
    float stationFuleLevel, price;
    std::string fuelName; 
public:
    Petrol(float a=1000, float b= 4.39, std::string c="Benzyna");
    virtual void giveFuel(float howMuch);
    virtual void loadFuel(float howMuch);
    virtual float giveFuelStatus();
    virtual float giveFuelPrice();
    virtual std::string giveFuelName();
};