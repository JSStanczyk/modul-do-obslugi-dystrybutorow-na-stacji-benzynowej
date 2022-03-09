#include "../inc/petrol.hpp"
#include "../inc/fuel.hpp"
#include <string>

Petrol::Petrol(float a, float b, std::string c) : stationFuleLevel(a), price(b),
               fuelName(c){}

void Petrol::giveFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel-howMuch;
    }

void Petrol::loadFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel+howMuch;
    }

float Petrol::giveFuelStatus()
    {
        return stationFuleLevel;
    }

float Petrol::giveFuelPrice()
    {
        return price;
    }

std::string Petrol::giveFuelName()
    {
        return fuelName;
    }