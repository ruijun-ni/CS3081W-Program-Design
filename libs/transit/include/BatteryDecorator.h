#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "Drone.h"
#include "IEntity.h"

class BatteryDecorator : public Drone {
 public:
  BatteryDecorator(IEntity* drone_) {
    drone = drone_;
    battery = 100;
  }
  ~BatteryDecorator();
  float GetBattery() const { return battery; }
  void SetBattery(float battery_) { battery = battery_; }

 private:
  IEntity* drone;
  float battery;
}

#endif  // BATTERY_DECORATOR_H_