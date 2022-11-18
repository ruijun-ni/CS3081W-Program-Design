#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
class IController {
 public:
  virtual ~IController() {}
  /// Adds an entity to the program
  virtual void AddEntity(const IEntity& entity) = 0;
  /// Adds an entity to the program
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /// Removes an entity from the program
  virtual void RemoveEntity(int id) = 0;
  /// Adds a path to the program
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /// Removes a path from the program
  virtual void RemovePath(int id) = 0;
  /// Allows messages to be passed back to the view
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
