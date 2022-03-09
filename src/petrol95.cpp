#include "../inc/petrol95.hpp"
#include "../inc/fuel.hpp"

void Petrol_95::getFuel(float howMuch)
{
    stationFuleLevel=stationFuleLevel-howMuch;
}

void Petrol_95::loadFuel(float howMuch)
{
    stationFuleLevel=stationFuleLevel+howMuch;
}

Petrol_95::Petrol_95(float a, float b) : stationFuleLevel(a), price(b){}