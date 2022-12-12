#include "BatteryDecorator.h"
#include "Singleton.h"

#include <unistd.h>

#include <ctime>

BatteryDecorator::BatteryDecorator(Drone* drone_) {
  drone = drone_;
  battery = 25;
}

void BatteryDecorator::Charge(double dt) {
  if (battery < 100) {
    SetBattery((battery + dt) > 100 ? 100 : battery + dt);
  } else {
    isCharge = false;
    check = true;
  }
}

bool BatteryDecorator::canArrive() {
  float totalDis = 0;
  if (drone->getTargetDestStrategy()->getStrategy()->distance != 0) {
    totalDis = drone->getTargetPosStrategy()->distance +
               drone->getTargetDestStrategy()->getStrategy()->distance +
               drone->getStationStrategy()->distance;
  } else {
    totalDis =
        drone->getTargetPosStrategy()->distance +
        drone->getTargetDestStrategy()->getStrategy()->getStrategy()->distance +
        drone->getStationStrategy()->distance;
  }
  return (totalDis < (battery * 125));
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
  if (isCharge) {
    Charge(dt);
    Singleton* s = Singleton::GetInstance();
    s->AddTotalTime(dt);

  } else {
    if (drone->GetAvailability()) {
      drone->GetNearestEntity(scheduler);
      if (drone->getTargetPosStrategy() != NULL) {
        check = canArrive();
      }
    }
    if (drone->getTargetPosStrategy() != NULL) {
      if (check) {
        drone->Update(dt, scheduler);
        curDistance += dt * 30.0;
        SetBattery(battery - dt * 30.0 * 0.008);
      } else {
        bool done = drone->FlyToCharge(dt, scheduler);
        SetBattery(battery - dt * 30.0 * 0.008);
        if (done) {
          isCharge = true;
        }
      }
    } else if (drone->getTargetDestStrategy() != NULL) {
      drone->Update(dt, scheduler);
      curDistance += dt * 30.0;
      SetBattery(battery - dt * 30.0 * 0.008);
    }
  }
}
