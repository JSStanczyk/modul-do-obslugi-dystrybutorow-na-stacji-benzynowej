#pragma once
#include <string>

class Fuel
{
public:
    virtual void giveFuel(float howMuch)=0;
    virtual void loadFuel(float howMuch)=0;
    virtual float giveFuelStatus()=0;
    virtual float giveFuelPrice()=0;
    virtual std::string giveFuelName()=0;
    virtual ~Fuel(){};
    
};