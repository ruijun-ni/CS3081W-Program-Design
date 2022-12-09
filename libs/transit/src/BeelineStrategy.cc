#include "BeelineStrategy.h"

BeelineStrategy::BeelineStrategy(Vector3 position, Vector3 destination) {
    this->position = position;
    this->destination = destination;
}

bool BeelineStrategy::IsCompleted(){
    return (destination - position).Magnitude()<1.0;
}

void BeelineStrategy::Move(IEntity* entity, double dt){
    position = entity->GetPosition();
    Vector3 dir = (destination - position).Unit();
    float speed = entity->GetSpeed(); 

    // collect total distance per drone
    Singleton* s = Singleton::GetInstance();
    s->AddTotalDistance(speed * dt); 

    position = position + dir * speed * dt;
    entity->SetPosition(position);
    entity->SetDirection(dir);
}