#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "Drone.h"
#include "IEntity.h"
#include <unistd.h>     //required for sleep()
/**
* @brief This class inhertis from the IEntity class and is responsible for creating a batteryDecrator.
*/
class BatteryDecorator : public IEntity {
 public:
  /**
   * @brief Constructor.
   * @param drone_ Drone that use to initialize the member variable "drone"
   */
  BatteryDecorator(Drone* drone_);
  
  /**
   * @brief Destructor.
   */
  ~BatteryDecorator() {};

  /**
   * @brief Get the battery of drone.
   * @return The batter power
   */
  float GetBattery() const { return battery; }
  
  /**
   * @brief Set the battery power of drone
   * @param battery The Amount of battery power going to be set
   */
  void SetBattery(float battery_) { battery = battery_; }

  /**
   * @brief Check if the current energy can support the trip
   * @return If the drone can arrive estination, return true. Otherwise, false.
   */
  bool canArrive();

  /**
   * @brief Move the drone base on battery level
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  
  /**
   * @brief Get the speed of drone
   * @return The speed of drone
   */
  float GetSpeed() const { return drone->GetSpeed(); }

  /**
   * @brief Tet the position of drone
   * @return The position of drone
   */
  Vector3 GetPosition() const { return drone->GetPosition(); }
  
  /**
   * @brief Get the direction of drone
   * @return The direction of drone
   */
  Vector3 GetDirection() const { return drone->GetDirection(); }

  /**
   * @brief Get the destination of drone
   * @return The destination of drone
   */
  Vector3 GetDestination() const { return drone->GetDestination(); }

  /**
   * @brief Get the detail of drone
   * @return The detail of drone
   */
  JsonObject GetDetails() const { return drone->GetDetails(); }

  /**
   * @brief Get the availablity of drone
   * @return The availability of drone
   */
  bool GetAvailability() const { return drone->GetAvailability(); }

  /**
   * @brief Charge the battery
   */
  void Charge(double dt);

  /**
   * @brief Set the graph of drone
   */
  void SetGraph(const IGraph* graph);

 private:
  Drone* drone; //!< Drone entity
  float battery; //!< Battery power level
  bool check; //!< If the drone has enough power to finish the trip
  bool isCharge = false; //!< If the drone is charging
};

#endif  // BATTERY_DECORATOR_H_