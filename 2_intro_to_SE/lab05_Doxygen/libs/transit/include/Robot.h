#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/// @brief Abstract controller class used in the Transit Service. Represents a robot in the map.
class Robot : public IEntity {
 public:
 /**
   * @brief constructor
   * @param obj Robot are created with a name
   */
  Robot(JsonObject& obj);

  /**
   * @brief Overrides Destructor
   */
  ~Robot() override = default;

  /**
   * @brief Get position of Robot.
   * @return position of Robot
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Get direction of Robot.
   * @return direction of Robot
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Get destination of Robot.
   * @return destination of Robot
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get availability of Robot.
   * @return availability status of Robot
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Overrides GetDetails function. 
   * @return JsonObject details of Robot
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Get speed of Robot.
   * @return speed of Robot
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Set availability of Robot.
   * @param choice availability status of Robot
   */
  void SetAvailability(bool choice);

  /**
   * @brief Set position of Robot.
   * @param pos_ new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set direction of Robot.
   * @param dir_ new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set destination of Robot.
   * @param der_ new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

   /**
   * @brief Rotate the Robot with angle.
   * @param angle the rotation angle
   */
  void Rotate(double angle);

 private:
  JsonObject details;  //!< Robot's details
  Vector3 position;  //!< Robot's position
  Vector3 direction;  //!< Robot's direction
  Vector3 destination;  //!< Robot's destination
  float speed;  //!< Robot's speed
  bool available;  //!< Robot's availability status
};

#endif  // ROBOT_H
