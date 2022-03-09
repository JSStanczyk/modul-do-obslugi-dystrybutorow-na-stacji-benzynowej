#pragma once
#include "../inc/fuel.hpp"
#include <memory>


class Distributor
{
private:
    double reFuelingTime, reFuelingSpeed, stationFuelLevel, fuelTaken;
    char startButton, endButton;
    std::shared_ptr<Fuel> fuelType;

public:
    Distributor(std::shared_ptr<Fuel> a=nullptr, float b=0, float c=1.35, float d=0, float e=0);
    void setFuelType(std::shared_ptr<Fuel> fuelType_);
    void getStationFuelLevel();
    float giveStationFuelLevel();
    void getStartButton();
    void getEndButton();
    void reFuel();
    float giveFuelTaken();

};