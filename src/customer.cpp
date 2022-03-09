#include "../inc/customer.hpp"

Customer::Customer(float a, float b):bill(a), fuelTaken(b){}

void Customer::saveBill(float a)
    {
        bill=a;
    }

float Customer::giveBill()
    {
        return bill;
    }

void Customer::setFuelTaken(float howMuch)
    {
        fuelTaken=howMuch;
    }

float Customer::giveFuelTaken()
    {
        return fuelTaken;
    }