#include "JumpDecorator.h"

bool JumpDecorator::IsCompleted() {
  return this->CelebrationDecorator::IsCompleted();
}

void JumpDecorator::Move(IEntity* entity, double dt) {
  if (strategy->IsCompleted() && !IsCompleted()) {
    time = time + dt;
    entity->Jump(dt * 20);
  } else {
    strategy->Move(entity, dt);
  }
}