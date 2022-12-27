#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

/// @brief Abstract controller class used in the Transit Service.
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
   * @return id of IEntity
   */
  virtual int GetId() const { return id; }

  /**
   * @brief Get position of IEntity.
   * @return position of IEntity
   */
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Get direction of IEntity.
   * @return direction of IEntity
   */
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Get destination of IEntity.
   * @return destination of IEntity
   */
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Get details of IEntity.
   * @return the JsonObject object of details of IEntity
   */
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Get speed of IEntity.
   * @return speed of IEntity
   */
  virtual float GetSpeed() const = 0;

  /**
   * @brief Get availability of IEntity.
   * @return availability status of IEntity
   */
  virtual bool GetAvailability() const = 0;

  /**
   * @brief Set availability of IEntity.
   * @param choice the new availability status of IEntity
   */
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief Update IEntity.
   * @param dt the delta time
   * @param scheduler current scheduler
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief Set graph of IEntity.
   * @param graph new graph
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Set position of IEntity.
   * @param pos_ new position
   */
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief Set direction of IEntity.
   * @param dir_ new direction
   */
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief Set destination of IEntity.
   * @param der_ new destination
   */
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Rotate the IEntity with the delta time.
   * @param dt the delta time
   */
  virtual void Rotate(double dt) {}

 protected:
  int id;  //!< IEntity's id
  const IGraph* graph;  //!< IEntity's graph
};

#endif
