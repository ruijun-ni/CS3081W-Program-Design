#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

/// @brief Represents a drone in a physical system.
/// Drones move using euler integration based on a specified
/// velocity and direction.
class Drone : public IEntity {
 public:
  /**
   * @brief constructor
   * @param obj Drones are created with a name
   */
  Drone(JsonObject& obj);  //!< Drones are created with a name

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
  * @brief Get the speed of drone.
  * @return Speed of drone.
  **/
  float GetSpeed() const { return speed; }

  /**
  * @brief Get the drone position.
  * @return the drone position.
  **/
  Vector3 GetPosition() const { return position; }

  /**
  * @brief Get the drone direction.
  * @return the drone direction.
  **/
  Vector3 GetDirection() const { return direction; }

  /**
  * @brief Get the drone destination.
  * @return the drone destination.
  **/
  Vector3 GetDestination() const { return destination; }

  /**
  * @brief Get the drone details.
  * @return the drone details.
  **/
  JsonObject GetDetails() const { return details; }

  /**
  * @brief Get the drone availability.
  * @return the drone availability.
  **/
  bool GetAvailability() const { return available; }

  /**
  * @brief Get the nearest entity.
  * @param scheduler the scheduler of drone
  * @return the nearest entity.
  **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
  * @brief Updates the drone's position.
  * @param dt the delta time
  * @param scheduler the scheduler of drone
  **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
  * @brief Set the drone's position.
  * @param pos_ drone's current position
  **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
  * @brief Sets the drone's direction.
  * @param dir_ drone's current direction
  **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
  * @brief Sets the drone's destination.
  * @param des_ drone's current destination
  **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
  * @brief Rotates a drone.
  * @param angle the rotate angle of drone
  **/
  void Rotate(double angle);

  /**
   * @brief Remove the copy constructor and assignment operator
   *                 so that drones cannot be coppied.
   * @param drone  
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Remove the assignment operator.
   * @param drone The Drone object cannot be coppied
   * @return The Drone object
   **/
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;  //!< drone's details
  Vector3 position;  //!< drone's position
  Vector3 direction;  //!< drone's direction
  Vector3 destination;  //!< drone's destination
  float speed;  //!< drone's speed
  bool available;  //!< drone's availabiliy status

  IEntity* nearestEntity = NULL; //!< the nearest entity of drone
};

#endif