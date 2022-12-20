#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
* @brief The class inherite from CelebrationDecorator. It is responsible for jump celebration behavior
*/
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for JumpDecorator
   * @param strategy_ The moving strategy
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

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

#endif  // JUMP_DECORATOR_H_