#pragma once
#include "fuel.hpp"
#include <memory>

class Supply
{
private:
    float fuelGiven;
    std::shared_ptr<Fuel> fuelType;

public:
    Supply(float a=0, std::shared_ptr<Fuel> b=nullptr);
    void getFuelSupply();
    void reSupply();
    void setFuelType(std::shared_ptr<Fuel> fuelType_);
    float giveSuppliedFuel();

};