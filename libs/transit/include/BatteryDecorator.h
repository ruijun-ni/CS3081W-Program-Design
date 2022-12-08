#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "Drone.h"
#include "IEntity.h"
#include <unistd.h>     //required for sleep()

class BatteryDecorator : public Drone {
 public:
  BatteryDecorator(Drone* drone_);
  
  ~BatteryDecorator() {};

  float GetBattery() const { return battery; }

  void SetBattery(float battery_) { battery = battery_; }

  bool canArrive();
  
  void update(double dt, std::vector<IEntity*> scheduler);
  
 private:
  Drone* drone;
  float battery;
};

#endif  // BATTERY_DECORATOR_H_