#include "../inc/supply.hpp"
#include <iostream>
#include <memory>

Supply::Supply(float a, std::shared_ptr<Fuel> b):fuelGiven(a), fuelType(b)
    {}

void Supply::getFuelSupply()
    {
        std::cout<<"\n\n\n\n\n\n\n\nWprowadź ilość paliwa jaką chcesz dostarczyć\n->";
        std::cin>>fuelGiven;
        for(;;)
            {
                if(fuelGiven>=0) break;
                else std::cout<<"\n\n\n\n\n\n\n\nNie można dostarczyć ujemnej ilości"<<std::endl;
            }
    }

void Supply::reSupply()
    {
        fuelType->loadFuel(fuelGiven);
    }

void Supply::setFuelType(std::shared_ptr<Fuel> fuelType_)
    {
        fuelType=fuelType_;
    }

float Supply::giveSuppliedFuel()
    {
        return fuelGiven;
    }