#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "Drone.h"
#include "IEntity.h"
#include <unistd.h>     //required for sleep()

class BatteryDecorator : public Drone {
 public:
  BatteryDecorator(IEntity* drone_){
    drone = drone_;
    battery = 100;
  }
  ~BatteryDecorator();
  float GetBattery() const { return battery; }
  void SetBattery(float battery_) { battery = battery_; }

  bool canArrive() {
    float totalDis = drone->toTargetPosStrategy->distance + drone->toTargetDestStrategy->distance + drone->toStationStrategy->distance;
    return (GetBattery() * 120) >= totalDis;
  }
  
  void update(double dt, std::vector<IEntity*> scheduler) {
    // if cannot arrive, we need to charge
    if (canArrive() && drone->toChargeStrategy == NULL) {
      drone->Update(dt, scheduler);
    } else {
      drone->FlyToCharge(dt, scheduler);
      // after arriving at the charge station, charge
      sleep(3); // wait for 3 sec
      SetBattery(100);
    }
  }

 private:
  IEntity* drone;
  float battery;
};

#endif  // BATTERY_DECORATOR_H_