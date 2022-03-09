#pragma once
#include "../inc/customer.hpp"
#include "../inc/distributor.hpp"
#include "../inc/fuel.hpp"
#include <memory>

class BillGenerator
{
private:
    float calculatedFee;
    std::shared_ptr<Fuel> fuelType;
    std::shared_ptr<Distributor> calculatingParameter;
    std::shared_ptr<Customer> customer;

public:
    BillGenerator(std::shared_ptr<Distributor> a=nullptr, std::shared_ptr<Customer> b=nullptr,
                  std::shared_ptr<Fuel> c=nullptr, float d=0);

    void setFuelType(std::shared_ptr<Fuel> fuelType_);
    void calculateFee();
    void makeBill();

};