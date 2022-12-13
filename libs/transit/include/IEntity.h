#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
class IEntity {
 public:
  /**
   * @brief default constructor
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Destructor
   */
  virtual ~IEntity() {}

  /**
   * @brief Get id of IEntity.
   * @return Id of IEntity
   */
  virtual int GetId() const { return id; }

  /**
   * @brief Get position of IEntity.
   * @return Position of IEntity
   */
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Get direction of IEntity.
   * @return Direction of IEntity
   */
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Get destination of IEntity.
   * @return Destination of IEntity
   */
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Get details of IEntity.
   * @return The JsonObject object of details of IEntity
   */
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Get speed of IEntity.
   * @return Speed of IEntity
   */
  virtual float GetSpeed() const = 0;

  /**
   * @brief Get availability of IEntity.
   * @return Availability status of IEntity
   */
  virtual bool GetAvailability() const {};

  /**
   * @brief Get strategy of IEntity.
   */
  virtual std::string GetStrategyName(){}

  /**
   * @brief Set availability of IEntity.
   * @param choice The new availability status of IEntity
   */
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief Update IEntity.
   * @param dt The delta time
   * @param scheduler current scheduler
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief Set graph of IEntity.
   * @param graph New graph
   */
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Set position of IEntity.
   * @param pos_ New position
   */
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief Set direction of IEntity.
   * @param dir_ New direction
   */
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief Set destination of IEntity.
   * @param des_ New destination
   */
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Set strategy of IEntity.
   * @param strategyName_ The strategy.
   */
  virtual void SetStrategyName(std::string strategyName_){}

  /**
   * @brief Rotate the IEntity with the delta time.
   * @param angle Angle the IEntity rotates.
   */
  virtual void Rotate(double angle) {}

  /**
   * @brief Rotate the IEntity with the delta time.
   * @param height Height the IEntity jumps.
   */
  virtual void Jump(double height) {}

 protected:
  int id;  //!< IEntity's id
  const IGraph* graph;  //!< IEntity's graph
};

#endif
