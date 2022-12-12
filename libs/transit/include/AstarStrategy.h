#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "Singleton.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class AstarStrategy : public IStrategy {
 public:
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  ~AstarStrategy();
  void Move(IEntity* entity, double dt);
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // ASTAR_STRATEGY_H_