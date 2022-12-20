#ifndef STATION_H
#define STATION_H

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a station in a physical system.
 */
class Station : public IEntity {
 public:
  /**
   * @brief constructor
   * @param obj station are created with a model and its parameters
   */
  Station(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Station() override = default;

  /**
   * @brief Get the station details.
   * @return The station details.
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Get the station position.
   * @return The station position.
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Get the station direction.
   * @return The station direction.
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Get the station destination.
   * @return The station destination.
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get the speed of station.
   * @return Speed of station.
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Set the station's position.
   * @param pos_ Station's current position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the station's direction.
   * @param dir_ Station's current direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the station's destination.
   * @param des_ Station's current destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

 private:
  JsonObject details; //!< station's details
  Vector3 position; //!< station's position

  Vector3 direction; //!< station's direction
  Vector3 destination; //!< station's destination
  IStrategy* strategy = NULL; //!< the strategy of station
  float speed; //!< station's speed
};

#endif  // STATION_H