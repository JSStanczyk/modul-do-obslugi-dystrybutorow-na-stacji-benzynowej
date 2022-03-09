#include "../inc/raportGenerator.hpp"
#include "../inc/fuel.hpp"
#include "../inc/customer.hpp"
#include "../inc/supply.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

RaportGenerator::RaportGenerator(std::shared_ptr<Customer> a, std::shared_ptr<Supply> b, std::string c, int d,
                                 std::string e, std::shared_ptr<Fuel> f):
                                 customer(a), supply(b), fileName(c), i(d), fuelName(e), fuelType(f){}

void RaportGenerator::setFuelType(std::shared_ptr<Fuel> fuelType_)
    {
        fuelType=fuelType_;
    }

void RaportGenerator::getCustomerParameters()
    {
        customerBill=customer->giveBill();
        customerFuel=customer->giveFuelTaken();
    }

void RaportGenerator::getFuelName()
    {
        fuelName=fuelType->giveFuelName();
    }

void RaportGenerator::openFileStream()
    {
       file.open(fileName, std::ios::out);
    }

void RaportGenerator::closeFileStream()
    {
        file.close();
    }

void RaportGenerator::makeReFuelingRaport()
    {
        file<<"\nKlient "<<i<<"\nRodzaj paliwa: "<<fuelName<<"\nZatankowano: "
            <<std::setprecision(2)<<std::fixed<<customerFuel<<" L"<<"\nZa kwotę: "
            <<std::setprecision(2)<<std::fixed<<customerBill<<" zł"<<"\nStan paliwa: "
            <<std::setprecision(2)<<std::fixed<<fuelType->giveFuelStatus()<<" L"<<std::endl;
        i++;
    }

void RaportGenerator::makeSypplyRaport()
    {
        file<<"\n\t\tDostawa"<<"\n\t\t\t{"<<"\n\t\t\t\tTyp paliwa: "<<fuelName
            <<"\n\t\t\t\tDostarczono: "<<std::setprecision(2)<<std::fixed
            <<supply->giveSuppliedFuel()<<" L"<<"\n\t\t\t\tStan paliwa: "
            <<std::setprecision(2)<<std::fixed<<fuelType->giveFuelStatus()
            <<" L"<<"\n\t\t\t}"<<std::endl;
    }
