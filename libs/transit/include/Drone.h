#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "Singleton.h"
#include "math/vector3.h"

/**
 * @brief Represents a drone in a physical system.
 * Drones move using euler integration based on a specified
 * velocity and direction.
 */
class Drone : public IEntity {
 public:

  /**
   * @brief constructor
   * @param obj Drones are created with a model and its parameters
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Get the speed of drone.
   * @return Speed of drone.
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Get the drone position.
   * @return The drone position.
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Get the drone direction.
   * @return The drone direction.
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Get the drone destination.
   * @return The drone destination.
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get the drone details.
   * @return The drone details.
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Get the drone availability.
   * @return The drone availability.
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Get the nearest entity.
   * @param scheduler The scheduler of drone
   * @return The nearest entity.
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief The drone will fly to the energy station
   * @param dt The delta time
   * @param scheduler The scheduler of drone
   * @return If the drone finish the fly strategy, return true. Otherwise, false.
   */
  bool FlyToCharge(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the drone's position.
   * @param dt The delta time
   * @param scheduler The scheduler of drone
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Set the drone's position.
   * @param pos_ Drone's current position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the drone's direction.
   * @param dir_ Drone's current direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the drone's destination.
   * @param des_ Drone's current destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
  * @brief Rotates a drone.
  * @param angle The rotate angle of drone
  */
  void Rotate(double angle);

  /**
   * @brief Jumps a drone.
   * @param angle The jump height of drone
   */
  void Jump(double height);

  /**
   * @brief Get toTargetPosStrategy of the drone
   * @return Return the toTargetPosStrategy
   */
  IStrategy* getTargetPosStrategy() {return toTargetPosStrategy;}

  /**
   * @brief Get toTargetDestStrategy of the drone
   * @return Return the toTargetDestStrategy
   */
  IStrategy* getTargetDestStrategy() {return toTargetDestStrategy;}

  /**
   * @brief Get toStationStrategy of the drone
   * @return Return the toStationStrategy
   */
  IStrategy* getStationStrategy() {return toStationStrategy;}

  /**
   * @brief Get toChargeStrategy of the drone
   * @return Return the toChargeStrategy
   */
  IStrategy* getChargeStrategy() {return toChargeStrategy;}

  /**
   * @brief Remove the copy constructor and assignment operator.
   *
   * @param drone  
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Remove the assignment operator.
   * @param drone The Drone object cannot be coppied
   * @return The Drone object
   */
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;  //!< drone's details
  Vector3 position;  //!< drone's position
  Vector3 direction;  //!< drone's direction
  float jumpHeight = 0;
  bool goUp = true; // jump helper
  Vector3 destination;  //!< drone's destination
  float speed;  //!< drone's speed
  bool available;  //!< drone's availabiliy status
  bool pickedUp;  //!< if the drone pick up the robot
  std::string strategyName;  //!< drone's strategy name
  IEntity* nearestEntity = NULL; //!< the nearest entity of drone
  IStrategy* toTargetPosStrategy = NULL;  //!< the strategy drone use to pick up the robot
  IStrategy* toTargetDestStrategy = NULL;  //!< the strategy drone use to send the robot
  IStrategy* toStationStrategy = NULL;  //!< the strategy drone use to go to the energy station
  IStrategy* toChargeStrategy = NULL;  //!< the strategy drone use to go to the energy station
};

#endif
