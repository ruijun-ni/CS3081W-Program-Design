#ifndef BEELINE_H_
#define BEELINE_H_

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
class BeelineStrategy : public IStrategy {
 public:
  BeelineStrategy(Vector3 position, Vector3 destination);
  ~BeelineStrategy();
  void Move(IEntity* entity, double dt);
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // BEELINE_H_