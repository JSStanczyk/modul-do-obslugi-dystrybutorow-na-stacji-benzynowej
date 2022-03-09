#include "../inc/fuel.hpp"
#include "../inc/disel.hpp"
#include <string>

Disel::Disel(float a, float b, std::string c) : stationFuleLevel(a), price(b),
             fuelName(c){}

void Disel::giveFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel-howMuch;
    }

void Disel::loadFuel(float howMuch)
    {
        stationFuleLevel=stationFuleLevel+howMuch;
    }

float Disel::giveFuelStatus()
    {
        return stationFuleLevel;
    }

float Disel::giveFuelPrice()
    {
        return price;
    }

std::string Disel::giveFuelName()
    {
        return fuelName;
    }