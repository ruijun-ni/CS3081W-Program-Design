#include "BatteryDecorator.h"
#include <ctime>
#include <unistd.h>

void Delay(int time) {
    clock_t now = clock();
    while (clock() - now < time);
}

BatteryDecorator::BatteryDecorator(Drone* drone_) {
    drone = drone_;
    battery = 25;
}

void BatteryDecorator::Charge(double dt) {
    if (battery < 100) {
            SetBattery((battery+dt)>100? 100 : battery+dt);
            std::cout << "I'm charging, now I have " << battery << " percent energy." << std::endl;
        }
        else {
            isCharge = false;
            check = true;
        }
}

bool BatteryDecorator::canArrive() {
    float totalDis = 0;
    if (drone->getTargetDestStrategy()->getStrategy()->distance != 0 ) {
        totalDis = drone->getTargetPosStrategy()->distance + drone->getTargetDestStrategy()->getStrategy()->distance + drone->getStationStrategy()->distance;
    }
    else {
        totalDis = drone->getTargetPosStrategy()->distance + drone->getTargetDestStrategy()->getStrategy()->getStrategy()->distance + drone->getStationStrategy()->distance;
    }
    // std::cout<< totalDis <<std::endl;
    // std::cout<< (totalDis < (battery*100))<<std::endl;
    return (totalDis < (battery*125));
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    // if cannot arrive, we need to charge
    if (isCharge) {
        Charge(dt);
    }
    else {
        if (drone->GetAvailability()) {
            std::cout << "0000000000000" << std::endl;
            drone->GetNearestEntity(scheduler);
            if (drone->getTargetPosStrategy() != NULL){
                check = canArrive();
            }
        }
        std::cout << "11111111111111" << std::endl;
        if (drone->getTargetPosStrategy() != NULL){
            std::cout << "222222222222" << std::endl;
            if (check){
                std::cout << "33333333333333" << std::endl;
                drone->Update(dt, scheduler);
                curDistance += dt*30.0;
                SetBattery(battery - dt*30.0*0.008);
                std::cout << "I'm moving, now I have " << battery << " percent energy." << std::endl;
            }
            else {
                std::cout << "4444444444444444" << std::endl;
                bool done = drone->FlyToCharge(dt, scheduler);
                SetBattery(battery - dt*30.0*0.008);
                std::cout << "I'm moving, now I have " << battery << " percent energy." << std::endl;
                if (done){
                    isCharge = true;
                }
            }
        }
        else if (drone->getTargetDestStrategy() != NULL){
            std::cout << "555555555555555" << std::endl;
            drone->Update(dt, scheduler);
            curDistance += dt*30.0;
            SetBattery(battery - dt*30.0*0.008);
            std::cout << "I'm moving, now I have " << battery << " percent energy." << std::endl;
        }
    }
}

