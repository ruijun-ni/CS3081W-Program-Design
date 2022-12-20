#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;

/**
 * @brief The abstract class that is resonpsible for entity moving 
 */
class IStrategy {
 public:
  /**
   * @brief Virtual function. Move the entity
   * @param entity The entity that need to move
   * @param dt The delta time
   */
  virtual void Move(IEntity* entity, double dt) = 0;

  /**
   * @brief Virtual function. It check if currently strategy is complete
   */
  virtual bool IsCompleted() = 0;

  /**
   * @brief Virtual function. It returns this strategy. 
   */
  virtual IStrategy* getStrategy() { return this; };

  float distance = 0; //<! The total distance of this strategy

 protected:
  const IGraph* graph; //<! IGraph object to be used in the simulation. 
};  // close class

#endif  // ISTRATEGY_H_