#include "../inc/fuel.hpp"
#include "../inc/gas.hpp"
#include <string>

Gas::Gas(float a, float b, std::string c) : stationFuleLevel(a), price(b),
         fuelName(c){}

void Gas::giveFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel-howMuch;
    }

void Gas::loadFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel+howMuch;
    }

float Gas::giveFuelStatus()
    {
        return stationFuleLevel;
    }

float Gas::giveFuelPrice()
    {
        return price;
    }

std::string Gas::giveFuelName()
    {
        return fuelName;
    }