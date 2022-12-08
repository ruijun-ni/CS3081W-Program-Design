#include "BatteryDecorator.h"

BatteryDecorator::BatteryDecorator(Drone* drone_) {
    drone = drone_;
    battery = 100;
}


bool BatteryDecorator::canArrive() {
    float totalDis = drone->getTargetPosStrategy()->distance + drone->getTargetDestStrategy()->distance + drone->getStationStrategy()->distance;
    return (GetBattery() * 120) >= totalDis;
}

void BatteryDecorator::update(double dt, std::vector<IEntity*> scheduler) {
    // if cannot arrive, we need to charge
    if (canArrive() && drone->getChargeStrategy() == NULL) {
        drone->Update(dt, scheduler);
    } else {
        drone->FlyToCharge(dt, scheduler);
        // after arriving at the charge station, charge
        sleep(3); // wait for 3 sec
        SetBattery(100);
    }
}

