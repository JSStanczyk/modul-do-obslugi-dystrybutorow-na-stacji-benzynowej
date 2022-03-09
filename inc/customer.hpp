#pragma once

class Customer
{
private:
    float bill, fuelTaken;
    
public:
    Customer(float a=0, float b=0);
    void saveBill(float a);
    float giveBill();
    void setFuelTaken(float howMuch);
    float giveFuelTaken();

};