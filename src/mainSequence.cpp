#include "../inc/billGenerator.hpp"
#include "../inc/supply.hpp"
#include "../inc/petrol.hpp"
#include "../inc/mainMenu.hpp"
#include "../inc/inputAnalizer.hpp"
#include "../inc/gas.hpp"
#include "../inc/fuel.hpp"
#include "../inc/distributor.hpp"
#include "../inc/customer.hpp"
#include "../inc/disel.hpp"
#include "../inc/mainSequence.hpp"
#include "../inc/supplyMenu.hpp"
#include "../inc/raportGenerator.hpp"
#include <iostream>
#include <memory>
#include <iomanip>

MainSequence::MainSequence(int a):isRunning(a){}

void MainSequence::resorceAlocator()
    {
        Fuel *disel_=new Disel; disel=std::shared_ptr<Fuel>(disel_);
        Fuel *petrol_=new Petrol; petrol=std::shared_ptr<Fuel>(petrol_);
        Fuel *gas_=new Gas; gas=std::shared_ptr<Fuel>(gas_);
        MainMenu *mainMenu_=new MainMenu; mainMenu=std::shared_ptr<MainMenu>(mainMenu_);
        SupplyMenu *supplyMenu_=new SupplyMenu; supplyMenu=std::shared_ptr<SupplyMenu>(supplyMenu_);
        InputAnalizer *inputAnalizer_=new InputAnalizer; inputAnalizer=std::shared_ptr<InputAnalizer>(inputAnalizer_);
        Distributor *distributor_=new Distributor; distributor=std::shared_ptr<Distributor>(distributor_);
        Supply *supply_=new Supply; supply=std::shared_ptr<Supply>(supply_);
        Customer * customer_=new Customer; customer=std::shared_ptr<Customer>(customer_);
        BillGenerator *billGenerator_=new BillGenerator(distributor, customer); billGenerator=std::shared_ptr<BillGenerator>(billGenerator_);
        RaportGenerator *raportGenerator_=new RaportGenerator(customer, supply); raportGenerator=std::shared_ptr<RaportGenerator>(raportGenerator_);
    }

void MainSequence::reFuelingSequence(std::shared_ptr<Fuel> fuelType)
    {
        distributor->setFuelType(fuelType);
        distributor->getStationFuelLevel();
        if(distributor->giveStationFuelLevel()>=50)
            {
                billGenerator->setFuelType(fuelType);
                raportGenerator->setFuelType(fuelType);
                raportGenerator->getFuelName();
                distributor->reFuel();
                billGenerator->calculateFee();
                billGenerator->makeBill();
                raportGenerator->getCustomerParameters();
                raportGenerator->makeReFuelingRaport();
            }
        else
            {
                std::cout<<"\n\n\n\n\n\n\n\nBrak wystarczającej ilości tego rodzaju paliwa"<<std::endl;
            }
    }  

void MainSequence::supplySequence(std::shared_ptr<Fuel> fuelType)
    {
        raportGenerator->setFuelType(fuelType);
        raportGenerator->getFuelName();
        supply->setFuelType(fuelType);
        supply->getFuelSupply();
        supply->reSupply();
        raportGenerator->makeSypplyRaport();
    }

void MainSequence::supplyMeneger()
    {
        supplyMenu->printSupplyMenu();
        inputAnalizer->getUserChoice();
        switch(inputAnalizer->giveUserChioce())
            {
                case 'd':
                case 'D':
                    supplySequence(disel);
                break;

                case 'b':
                case 'B':
                    supplySequence(petrol);
                break;

                case 'g':
                case 'G':
                    supplySequence(gas);
                break;
            }
    }

void MainSequence::printFinalFuelSatus()
    {
        std::cout<<"\n"<<disel->giveFuelName()<<"\nStan: "<<std::setprecision(2)
                 <<std::fixed<<disel->giveFuelStatus()<<" L\n\n"<<petrol->giveFuelName()
                 <<"\nStan: "<<std::setprecision(2)<<std::fixed<<petrol->giveFuelStatus()
                 <<" L\n\n"<<gas->giveFuelName()<<"\nStan: "<<std::setprecision(2)<<std::fixed
                 <<gas->giveFuelStatus()<<" L\n"<<std::endl;
    }

void MainSequence::_do_()
    {   
        resorceAlocator();
        raportGenerator->openFileStream();
        while(isRunning)
        {
            mainMenu->printMainMenu();
            inputAnalizer->getUserChoice();
            switch(inputAnalizer->giveUserChioce())
                {
                    case 'd':
                    case 'D':
                       reFuelingSequence(disel);
                    break;

                    case 'b':
                    case 'B':
                        reFuelingSequence(petrol);
                    break;

                    case 'g':
                    case 'G':
                        reFuelingSequence(gas);
                    break;

                    case 's':
                    case 'S':
                        supplyMeneger();
                    break;

                    case 'e':
                    case 'E':
                        isRunning=0;
                        printFinalFuelSatus();
                    break;

                }
                //system("clear");
        }
        raportGenerator->closeFileStream();
    }