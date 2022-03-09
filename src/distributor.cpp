#include "../inc/distributor.hpp"
#include "../inc/fuel.hpp"
#include <chrono>
#include <iostream>
#include <memory>


Distributor::Distributor(std::shared_ptr<Fuel> a, float b,
                         float c, float d, float e):fuelType(a), reFuelingTime(b),
                         reFuelingSpeed(c), stationFuelLevel(d), fuelTaken(e)
    {
        startButton='z';
        endButton='z';
    }

void Distributor::setFuelType(std::shared_ptr<Fuel> fuelType_)
    {
        fuelType=fuelType_;
    }

void Distributor::getStationFuelLevel()
    {
        stationFuelLevel=fuelType->giveFuelStatus();
    }

float Distributor::giveStationFuelLevel()
    {
        return stationFuelLevel;
    }

void Distributor::getStartButton()
    {
        for(;;)
        {
            std::cout<<"\n\n\n\n\n\n\n\nWpisz 'r' i zatwierdź enterem aby zacząć tankować\n->";
            std::cin>>startButton;
            if(startButton=='r') break;
            else std::cout<<"\n\n\n\n\n\n\n\nNie ten przycisk"<<std::endl;
        }
    }

void Distributor::getEndButton()
    {
        for(;;)
        {
            std::cout<<"\n\n\n\n\n\n\n\nWpisz 'r' i zatwierdź enterem aby zakończyć tankowanie\n->";
            std::cin>>endButton;
            if(endButton=='r') break;
            else std::cout<<"\n\n\n\n\n\n\n\nNie ten przycisk"<<std::endl;
        }
    }

void Distributor::reFuel()
    {
        getStartButton();
        auto start = std::chrono::steady_clock::now();
        getEndButton();
        std::chrono::duration<float> reFuelingTime=std::chrono::steady_clock::now()-start;
        fuelTaken=reFuelingTime.count()*reFuelingSpeed;
        fuelType->giveFuel(fuelTaken);
    }

float Distributor::giveFuelTaken()
    {
        return fuelTaken;
    }