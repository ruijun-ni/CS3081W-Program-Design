#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
class IController {
 public:
  /**
   * @brief Destructor
   */
  virtual ~IController() {}

  /**
   * @brief Adds an entity to the program.
   * @param entity The new entity
   */
  virtual void AddEntity(const IEntity& entity) = 0;

  /**
   * @brief Update entity to the program.
   * @param entity The new entity
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /**
   * @brief Removes an entity from the program.
   * @param id Id of the new entity
   */
  virtual void RemoveEntity(int id) = 0;

  /**
   * @brief Adds a path to the program.
   * @param id Id of the new path
   * @param path Current path
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;

  /**
   * @brief Removes a path from the program.
   * @param id Id of the removed path
   */
  virtual void RemovePath(int id) = 0;

  /**
   * @brief Allows messages to be passed back to the view.
   * @param event Messages passed back to the view
   * @param details The messages details
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
