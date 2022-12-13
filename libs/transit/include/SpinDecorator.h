#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
* @brief This class inherite from CelebrationDecorator. It is responsible for spin celebration behavior
**/
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor
   * @param strategy The moving strategy
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Check if the strategy is complete
   * @return True if compelte, false otherwise
   */
  bool IsCompleted();
  /**
   * @brief Move the entity
   * @param entity Entity that need to move
   * @param dt Delta time
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // SPIN_DECORATOR_H_