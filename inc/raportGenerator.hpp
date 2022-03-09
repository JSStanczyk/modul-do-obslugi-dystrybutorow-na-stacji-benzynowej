#pragma once
#include "customer.hpp"
#include "fuel.hpp"
#include "supply.hpp"
#include <memory>
#include <fstream>
#include <string>

class RaportGenerator
{
private:
    std::shared_ptr<Fuel> fuelType;
    std::shared_ptr<Customer> customer;
    std::shared_ptr<Supply> supply;
    std::fstream file;
    std::string fuelName;
    std::string fileName;
    float customerBill, customerFuel;
    int i;

public:
    RaportGenerator(std::shared_ptr<Customer> a=nullptr, std::shared_ptr<Supply> b=nullptr, std::string c="raport.txt",
                    int d=1, std::string e="Brak", std::shared_ptr<Fuel> f=nullptr);
    void setFuelType(std::shared_ptr<Fuel> a=nullptr);
    void getCustomerParameters();
    void getFuelName();
    void openFileStream();
    void closeFileStream();
    void makeReFuelingRaport();
    void makeSypplyRaport();
    
};