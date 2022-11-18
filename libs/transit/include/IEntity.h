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
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  virtual ~IEntity() {}
  virtual int GetId() const { return id; }
  virtual Vector3 GetPosition() const = 0;
  virtual Vector3 GetDirection() const = 0;
  virtual Vector3 GetDestination() const = 0;
  virtual JsonObject GetDetails() const = 0;
  virtual float GetSpeed() const = 0;
  virtual bool GetAvailability() const {};
  virtual std::string GetStrategyName(){}
  virtual void SetAvailability(bool choice) {}
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  virtual void SetPosition(Vector3 pos_) {}
  virtual void SetDirection(Vector3 dir_) {}
  virtual void SetDestination(Vector3 des_) {}
  virtual void SetStrategyName(std::string strategyName_){}
  virtual void Rotate(double angle) {}
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
