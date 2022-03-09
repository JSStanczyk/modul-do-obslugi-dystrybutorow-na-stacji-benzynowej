#pragma once
#include "billGenerator.hpp"
#include "supply.hpp"
#include "petrol.hpp"
#include "mainMenu.hpp"
#include "inputAnalizer.hpp"
#include "gas.hpp"
#include "fuel.hpp"
#include "distributor.hpp"
#include "customer.hpp"
#include "disel.hpp"
#include "supplyMenu.hpp"
#include "raportGenerator.hpp"
#include <memory>

class MainSequence
{
private:
    int isRunning;
    std::shared_ptr<Fuel> disel;
    std::shared_ptr<Fuel> petrol;
    std::shared_ptr<Fuel> gas;
    std::shared_ptr<MainMenu> mainMenu;
    std::shared_ptr<SupplyMenu> supplyMenu;
    std::shared_ptr<InputAnalizer> inputAnalizer;
    std::shared_ptr<Distributor> distributor;
    std::shared_ptr<Supply> supply;
    std::shared_ptr<Customer> customer;
    std::shared_ptr<BillGenerator> billGenerator;
    std::shared_ptr<RaportGenerator> raportGenerator;

public:
    MainSequence(int a=1);
    void resorceAlocator();
    void reFuelingSequence(std::shared_ptr<Fuel> fuelType);
    void supplySequence(std::shared_ptr<Fuel> fuelType);
    void supplyMeneger();
    void printFinalFuelSatus();
    void _do_();

};