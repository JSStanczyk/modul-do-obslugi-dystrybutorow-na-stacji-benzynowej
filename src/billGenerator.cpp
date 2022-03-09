#include "../inc/customer.hpp"
#include "../inc/distributor.hpp"
#include "../inc/fuel.hpp"
#include "../inc/billGenerator.hpp"
#include <memory>

BillGenerator::BillGenerator(std::shared_ptr<Distributor> a, std::shared_ptr<Customer> b,
                             std::shared_ptr<Fuel> c, float d)
                             :calculatingParameter(a), customer(b), fuelType(c),
                             calculatedFee(d){}

void BillGenerator::setFuelType(std::shared_ptr<Fuel> fuelType_)
    {
        fuelType=fuelType_;
    }

void BillGenerator::calculateFee()
    {
        calculatedFee=fuelType->giveFuelPrice()*calculatingParameter->giveFuelTaken();
    }
void BillGenerator::makeBill()
    {
        customer->saveBill(calculatedFee);
        customer->setFuelTaken(calculatingParameter->giveFuelTaken());
    }