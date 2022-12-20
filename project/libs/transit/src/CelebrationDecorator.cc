#include "CelebrationDecorator.h"

bool CelebrationDecorator::IsCompleted() { return time >= 1.5; }

void CelebrationDecorator::Move(IEntity* entity, double dt) {
  strategy->Move(entity, dt);
}