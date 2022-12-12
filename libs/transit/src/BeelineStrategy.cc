#include "BeelineStrategy.h"

#include <iostream>

BeelineStrategy::BeelineStrategy(Vector3 position, Vector3 destination) {
  this->position = position;
  this->destination = destination;

  distance += sqrt(pow(position.x - destination.x, 2) +
                   pow(position.y - destination.y, 2) +
                   pow(position.z - destination.z, 2));
  std::cout << "The total distance for this beeline route is " << distance
            << std::endl;
}

bool BeelineStrategy::IsCompleted() {
  return (destination - position).Magnitude() < 1.0;
}

void BeelineStrategy::Move(IEntity* entity, double dt) {
  position = entity->GetPosition();
  Vector3 dir = (destination - position).Unit();
  float speed = entity->GetSpeed();

  // collect total distance per drone and total time
  Singleton* s = Singleton::GetInstance();
  s->AddTotalDistance(speed * dt);
  s->AddTotalTime(dt);

  position = position + dir * speed * dt;
  entity->SetPosition(position);
  entity->SetDirection(dir);
}