#include "../inc/petrol98.hpp"
#include "../inc/fuel.hpp"

void Petrol_98::getFuel(float howMuch)
{
    stationFuleLevel=stationFuleLevel-howMuch;
}

void Petrol_98::loadFuel(float howMuch)
{
    stationFuleLevel=stationFuleLevel+howMuch;
}

Petrol_98::Petrol_98(float a, float b) : stationFuleLevel(a), price(b){}