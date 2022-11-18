#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class JumpDecorator : public CelebrationDecorator {
 public:
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  bool IsCompleted();
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // JUMP_DECORATOR_H_