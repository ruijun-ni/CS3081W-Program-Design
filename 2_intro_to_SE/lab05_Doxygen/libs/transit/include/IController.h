#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

/// @brief Abstract controller class used in the Transit Service.
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
   * @param entity the new entity
   */
  virtual void AddEntity(const IEntity& entity) = 0;

  /**
   * @brief Update entity to the program.
   * @param entity the new entity
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /**
   * @brief Removes an entity from the program.
   * @param id id of the new entity
   */
  virtual void RemoveEntity(int id) = 0;

  /**
   * @brief Adds a path to the program.
   * @param id id of the new path
   * @param path current path
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;

  /**
   * @brief Removes a path from the program.
   * @param id id of the removed path
   */
  virtual void RemovePath(int id) = 0;

  /**
   * @brief Allows messages to be passed back to the view.
   * @param event messages passed back to the view
   * @param details the messages details
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
