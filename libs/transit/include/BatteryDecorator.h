#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include <unistd.h>  //required for sleep()

#include "Drone.h"
#include "IEntity.h"

class BatteryDecorator : public IEntity {
 public:
  BatteryDecorator(Drone* drone_);

  ~BatteryDecorator(){};

  float GetBattery() const { return battery; }

  void SetBattery(float battery_) { battery = battery_; }

  bool canArrive();

  void Update(double dt, std::vector<IEntity*> scheduler);

  float GetSpeed() const { return drone->GetSpeed(); }

  Vector3 GetPosition() const { return drone->GetPosition(); }

  Vector3 GetDirection() const { return drone->GetDirection(); }

  Vector3 GetDestination() const { return drone->GetDestination(); }

  JsonObject GetDetails() const { return drone->GetDetails(); }

  bool GetAvailability() const { return drone->GetAvailability(); }

  void Charge(double dt);

  void SetGraph(const IGraph* graph) { drone->SetGraph(graph); }

  float curDistance = 0;

 private:
  Drone* drone;
  float battery;
  bool check;
  bool isCharge = false;
};

#endif  // BATTERY_DECORATOR_H_